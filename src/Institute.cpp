#include <algorithm>
#include <boost/algorithm/string.hpp>
#include "Institute.hpp"

Institute::Institute(const std::wstring &numeInstitute) : mNumeInstitute(numeInstitute) {}

void Institute::setStudentLocRepartizat(const int& nrCrt)
{
    auto place = std::find_if(mStudents.begin(), mStudents.end(),
            [&nrCrt](auto& student){return student->getNrCrt() == nrCrt; });

    mStudents.at((place - mStudents.begin()))->setLocRepartizat(L"setaat");
}

std::wostream &operator<<(std::wostream &os, const Institute &institute) {
    os << "nume Institute: " << institute.mNumeInstitute << " \nobjects: \n";
    for(auto const& object : institute.mStudents)
        os << "\t" << object << "\n";
    os << std::endl;
    return os;
}

void Institute::setStudents(const std::vector<std::shared_ptr<Student>> &mStudents) {
    Institute::mStudents = mStudents;
}

const std::vector<std::shared_ptr<Student>> &Institute::getMStudents() const {
    return Institute::mStudents;
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
    auto punctaj = std::stod(elements[7]);

    Student returnedStudent{nrCrt, numePrenume, an, serie, grupa, nrTelefon, mail, punctaj, optiuniFromLine};
//    Student returnedStudent{std::stoi(elements[0]), elements[1], std::stoi(elements[2]), std::stoi(elements[3]),
//                            std::stoi(elements[4]), std::stol(elements[5]), elements[6],std::stod(elements[7]),
//                            optiuniFromLine};
    return returnedStudent;
}

void incarcareDateStudentiDinFisier(const std::string& fisierulSursa, Institute& institutie)
{
    char *locale = setlocale(LC_ALL, "");
    FILE *inputFile = fopen(fisierulSursa.c_str(), "r");

    std::vector<std::shared_ptr<Student>> students;
    std::wstring stringLine{};
    wint_t characterfromFile{};

    do {
        characterfromFile = fgetwc(inputFile);
        if (characterfromFile == L'\n' || characterfromFile == WEOF) {
            // avem o linie intreaga
            // o modificam sa avem "30.01" in loc de 30,01"
            if(replaceCommaWithFullStopForLine(stringLine) == true)
                students.emplace_back(std::make_shared<Student>(getStudentFromLine(stringLine)));
            stringLine.clear();
        } else {
            stringLine += characterfromFile;
        }
    } while (characterfromFile != EOF);

    fclose(inputFile);
    institutie.setStudents(students);
}
