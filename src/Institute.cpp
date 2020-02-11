#include <algorithm>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>
#include <fstream>
#include "Institute.hpp"

Optiune::Optiune(const std::wstring &numeLoc, int numarLocuriDisponibile) : numeLoc(numeLoc), numarLocuriDisponibile(
        numarLocuriDisponibile)
{
    Optiune::numarLocuriRamase = numarLocuriDisponibile;
}

Institute::Institute(const std::wstring &numeInstitute) : mNumeInstitute(numeInstitute) {}

void Institute::setStudentLocRepartizat(const int& nrCrt)
{
    auto place = std::find_if(mStudents.begin(), mStudents.end(),
            [&nrCrt](Student& student){return student.getNrCrt() == nrCrt; });

    mStudents.at((place - mStudents.begin())).setLocRepartizat(L"setaat");
}

std::wostream &operator<<(std::wostream &os, const Institute &institute) {
    os << "nume Institute: " << institute.mNumeInstitute << " \nobjects: \n";
    for(auto const& object : institute.mStudents)
        os << "\t" << object << "\n";
    os << std::endl;
    return os;
}

void Institute::setOptiuniPrimite(const std::vector<Optiune> &mOptiuniPrimite) {
    Institute::mOptiuniPrimite = mOptiuniPrimite;
}

void Institute::setStudents(const std::vector<Student> &students) {
    Institute::mStudents = students;
}

bool replaceCommaWithFullStopForLine(std::wstring& line)
{
    auto firstDelimiterForNota = LR"(,")";
    std::size_t foundFirstDelimiter = line.find(firstDelimiterForNota);
    if (foundFirstDelimiter !=std::string::npos) {
        // get last character from found wstringScore and check if the wstringScore is "100,00" or lower 10.02/
        auto lastCharacterOfScore = line.substr(foundFirstDelimiter + 7, 1);
        if (lastCharacterOfScore != L"0") {
            line.replace(foundFirstDelimiter + 1 , 1, L"");
            line.replace( foundFirstDelimiter + 6,1, L"");
            line.replace(foundFirstDelimiter + 3, 1, L".");
        } else
        {
            line.replace(foundFirstDelimiter + 1 , 1, L"");
            line.replace( foundFirstDelimiter + 7,1, L"");
            line.replace(foundFirstDelimiter + 4, 1, L".");
        }
        return true;
    }
    return false;
}

Student getStudentFromLine(const std::wstring& line)
{
    // Transform line to vector of elements
    std::vector<std::wstring> elements;
    boost::split(elements,line,boost::is_any_of(L","));

    std::vector<std::wstring> optiuniFromLine;
    for(size_t i = 8 ; i < elements.size() && !elements.at(i).empty(); ++i )
        optiuniFromLine.emplace_back(elements.at(i));
    auto nrCrt = std::stoi(elements[0]);
    auto numePrenume = elements[1];
    auto an = std::stoi(elements[2]);
    auto serie = std::stoi(elements[3]);
    auto grupa = std::stoi(elements[4]);
    auto nrTelefon = std::stol(elements[5]);
    auto mail = elements[6];
    double punctaj = boost::lexical_cast<double>(elements[7]);

    Student returnedStudent{nrCrt, numePrenume, an, serie, grupa, nrTelefon, mail, punctaj, optiuniFromLine};
//    Student returnedStudent{std::stoi(elements[0]), elements[1], std::stoi(elements[2]), std::stoi(elements[3]),
//                            std::stoi(elements[4]), std::stol(elements[5]), elements[6],std::stod(elements[7]),
//                            optiuniFromLine};
    return returnedStudent;
}

int Institute::findOptiuneDupanume(const std::wstring& numeOptiuneAleasa)
{
    auto place = std::find_if(mOptiuniPrimite.begin(), mOptiuniPrimite.end(),
                              [&numeOptiuneAleasa](Optiune& optiuneCurenta){return optiuneCurenta.numeLoc == numeOptiuneAleasa; });

    if( place != mOptiuniPrimite.end())
        return (place - mOptiuniPrimite.begin());
    else return -1;
}

void Institute::repartizareStudentiPentruOptiune()
{
    for(auto& student : mStudents)
    {
        bool isRepartizat = false;
        int numarOptiuneCurenta = 0;
        auto optiuniAlese = student.getMOptiuniAlese();

        do
        {
            //check if
            auto locOptiuneInVector = findOptiuneDupanume(optiuniAlese.at(numarOptiuneCurenta));
            if(locOptiuneInVector != -1)
            {
                if (mOptiuniPrimite.at(locOptiuneInVector).numarLocuriRamase != 0)
                {
                    student.setLocRepartizat(optiuniAlese.at(numarOptiuneCurenta));
                    --mOptiuniPrimite.at(locOptiuneInVector).numarLocuriRamase;
                    isRepartizat = true;
                } else
                {
                    ++numarOptiuneCurenta;
                }
            }
        }while (numarOptiuneCurenta != optiuniAlese.size() && !isRepartizat);

        if(!isRepartizat)
        {
            student.setLocRepartizat(L"Nerepartizat");
        }
    }
}

void printfStudents(const Institute& institute)
{
    wprintf(L"%-7ls  %-35ls  %-5ls  %-5ls  %-5ls  %-15ls  %-35ls  %-10ls%-25ls %-25ls %-25ls %-25ls %-25ls %-25ls% -10ls\n"
            , L"Nr Crt.", L"Nume si Prenume", L"An", L"Serie", L"Grupa", L"Telefon", L"Mail", L"Punctaj"
            , L"Optiune1", L"Optiune2", L"Optiune3", L"Optiune4", L"Optiune5", L"Optiune6", L"Repartizare");
    for( auto const& student: institute.mStudents)
        printfStudent(student);
}
void printareOptiuniPrimite(const Institute &institute)
{
    for(auto const& optiune : institute.mOptiuniPrimite)
        std::wcout << optiune.numeLoc << L" " << optiune.numarLocuriDisponibile << L" " << optiune.numarLocuriRamase << L"\n";
}

void printareStudenti(const Institute &institute)
{
    for(auto const& student : institute.mStudents)
        std::wcout << "\t" << student << "\n";
    std::wcout << std::endl;
}

void printareStudentiRepartizatiPentruOptiunea(const Institute& institute, const std::wstring& optiune)
{
    for(auto& student : institute.mStudents)
    {
        if(student.getMLocRepartizat() == optiune)
            std::wcout << "\t" << student << "\n";
    }
    std::wcout << std::endl;
}
void sendStudents(const Institute& institute)
{
    char *locale = setlocale(LC_ALL, "");
    FILE* outputFile = fopen( "../resources/Studenti_din_institutie.csv", "w");

    for(auto& student : institute.mStudents)
    {
        fwprintf(outputFile,L"%d,",student.getNrCrt());
        fwprintf(outputFile,L"%10s,",L"");
        fwprintf(outputFile,student.getMNumeSiPrenume().c_str());
        fwprintf(outputFile,L",%.2lf,",student.getMPunctaj());
        for(auto const& optiune : student.getMOptiuniAlese()) {
            fwprintf(outputFile, optiune.c_str());
            fwprintf(outputFile, L",");
        }
        fwprintf(outputFile,student.getMLocRepartizat().c_str());
        fwprintf(outputFile,L"\n");
    }

    fclose(outputFile);
}
void sendStudentsToCSV(const Institute& institute, const std::wstring& optiune, const std::string& stringOutputFile)
{
    char *locale = setlocale(LC_ALL, "");
    FILE* outputFile = fopen( stringOutputFile.c_str(), "w");

    for(auto& student : institute.mStudents)
    {
        if(student.getMLocRepartizat() == optiune)
        {
            fwprintf(outputFile,L"%d,",student.getNrCrt());
            fwprintf(outputFile,student.getMNumeSiPrenume().c_str());
            fwprintf(outputFile,L",%.5lf,",student.getMPunctaj());
            for(auto const& optiune : student.getMOptiuniAlese()) {
                fwprintf(outputFile, optiune.c_str());
                fwprintf(outputFile, L",");
            }
            fwprintf(outputFile,student.getMLocRepartizat().c_str());
            fwprintf(outputFile,L"\n");
        }
    }

    fclose(outputFile);
}

void incarcareDateStudentiDinFisier(const std::string& fisierulSursa, Institute& institutie)
{
    char *locale = setlocale(LC_ALL, "");
    FILE *inputFile = fopen(fisierulSursa.c_str(), "r");

    std::vector<Student> students;
    std::wstring stringLine{};
    wint_t characterfromFile{};

    do {
        characterfromFile = fgetwc(inputFile);
        if (characterfromFile == L'\n' || characterfromFile == WEOF) {
            // avem o linie intreaga
            // eliminam \r
            stringLine.erase( std::remove(stringLine.begin(), stringLine.end(), '\r'), stringLine.end() );
            // o modificam sa avem "30.01" in loc de 30,01"
            if(replaceCommaWithFullStopForLine(stringLine) == true)
                students.emplace_back(getStudentFromLine(stringLine));
            stringLine.clear();
        } else {
            stringLine += characterfromFile;
        }
    } while (characterfromFile != EOF);

    fclose(inputFile);
    institutie.setStudents(students);
}
