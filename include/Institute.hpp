#ifndef INSTITUTE_HPP
#define INSTITUTE_HPP

#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>
#include <memory>
#include "Student.hpp"

class Institute {
public:
    Institute(const std::wstring &numeInstitute);

    void setStudentLocRepartizat(const int& nrCrt);

    friend std::wostream &operator<<(std::wostream &os, const Institute &institute);

    void setStudents(const std::vector<std::shared_ptr<Student>> &students);

    const std::vector<std::shared_ptr<Student>> &getMStudents() const;

private:
    std::wstring mNumeInstitute;
    std::vector<std::shared_ptr<Student>> mStudents;

};

void incarcareDateStudentiDinFisier(const std::string& fisierulSursa, Institute& institutie);

#endif // INSTITUTE_HPP
