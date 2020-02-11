#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>

class Student {
public:
    Student(int nrCrt, const std::wstring& numeSiPrenume, int an, int serie, int grupa, const long& nrTelefon,
            const std::wstring& mail, const double& punctaj, const std::vector<std::wstring>& optiuniAlese);

    void setLocRepartizat(const std::wstring &locRepartizat);

    friend std::wostream &operator<<(std::wostream &os, const Student &student);

    int getNrCrt() const;

    const std::vector<std::wstring> &getMOptiuniAlese() const;

    const std::wstring &getMLocRepartizat() const;

    const std::wstring &getMNumeSiPrenume() const;

    double getMPunctaj() const;

    friend void printfStudent(const Student& student);

private:
    int mNrCrt;
    std::wstring mNumeSiPrenume;
    int mAn;
    int mSerie;
    int mGrupa;
    long mNrTelefon;
    std::wstring mMail;
    double mPunctaj;
    std::vector<std::wstring> mOptiuniAlese;
    std::wstring mLocRepartizat {L""};
};


#endif // STUDENT_HPP
