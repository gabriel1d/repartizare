#ifndef INSTITUTE_HPP
#define INSTITUTE_HPP

#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>

#include "Student.hpp"

class Institute {
public:
    Institute(const std::wstring &numeInstitute);

    void setStudentLocRepartizat(const int& nrCrt);

    friend std::wostream &operator<<(std::wostream &os, const Institute &institute);

    void setStudents(const std::vector<Student> &students);

private:
    std::wstring mNumeInstitute;
    std::vector<Student> mStudents;
};

void incarcareDateStudentiDinFisier(const std::string& fisierulSursa, Institute& institutie);

#endif // INSTITUTE_HPP
