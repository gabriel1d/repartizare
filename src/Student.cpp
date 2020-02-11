
#include "Student.hpp"

Student::Student(int nrCrt, const std::wstring& numeSiPrenume, int an, int serie, int grupa, const long& nrTelefon,
                 const std::wstring& mail, const double& punctaj, const std::vector<std::wstring>& optiuniAlese)
                 : mNrCrt(nrCrt), mNumeSiPrenume(numeSiPrenume), mAn(an), mSerie(serie), mGrupa(grupa), mNrTelefon(nrTelefon)
                 , mMail(mail), mPunctaj(punctaj), mOptiuniAlese(optiuniAlese) {}

void Student::setLocRepartizat(const std::wstring &locRepartizat) {
    Student::mLocRepartizat = locRepartizat;
}

std::wostream &operator<<(std::wostream &os, const Student &student) {
    os << "mNrCrt: " << student.mNrCrt << " mNumeSiPrenume: " << student.mNumeSiPrenume << " mAn: " << student.mAn
       << " mSerie: " << student.mSerie << " mGrupa: " << student.mGrupa << " mNrTelefon: " << student.mNrTelefon
       << " mMail: " << student.mMail << " mPunctaj: " << student.mPunctaj << " mOptiuniAlese:";
    for(auto const& optiune : student.mOptiuniAlese)
        os << " " << optiune;
    os << " mLocRepartizat: " << student.mLocRepartizat;

    return os;
}

int Student::getNrCrt() const {
    return mNrCrt;
}

const std::vector<std::wstring> &Student::getMOptiuniAlese() const {
    return mOptiuniAlese;
}

const std::wstring &Student::getMLocRepartizat() const {
    return mLocRepartizat;
}

const std::wstring &Student::getMNumeSiPrenume() const {
    return mNumeSiPrenume;
}

double Student::getMPunctaj() const {
    return mPunctaj;
}

void printfStudent(const Student& student)
{
    wprintf(L"%-7d  %-35ls  %-5d  %-5d  %-5d  %-15ld  %-35ls  %-10.2f", student.mNrCrt, student.mNumeSiPrenume.c_str(), student.mAn, student.mSerie, student.mGrupa, student.mNrTelefon, student.mMail.c_str(), student. mPunctaj);

    for(size_t it = 0; it < 6; ++it)
    {
        if(it < student.mOptiuniAlese.size())
        {
            wprintf(L"%-25ls ", student.mOptiuniAlese.at(it).c_str());
        }
        else
            wprintf(L"%-25ls ", L"-");

    }
//    for(auto const& optiuneAleasa : student.mOptiuniAlese)
//        if(optiuneAleasa != L"")
//        {
//            wprintf(L"%-25ls ", optiuneAleasa.c_str());
//        }else
//        {
//            wprintf(L"%-25ls ", L"-");
//        }

    wprintf(L"%-10ls", student.mLocRepartizat.c_str());
    wprintf(L"\n");
}