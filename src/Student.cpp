
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
       << " mMail: " << student.mMail << " mPunctaj: " << student.mPunctaj << " mOptiuniAlese: ";
    for(auto const& optiune : student.mOptiuniAlese)
        os << " " << optiune;
    os << " mLocRepartizat: " << student.mLocRepartizat;

    return os;
}

int Student::getNrCrt() const {
    return mNrCrt;
}
