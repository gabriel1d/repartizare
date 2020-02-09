//
// Created by gabi on 09.02.2020.
//

#ifndef VECTOROFOBJECTS_INSTITUTE_HPP
#define VECTOROFOBJECTS_INSTITUTE_HPP

#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>

#include "Student.hpp"

class Institute {
public:
    Institute(const std::wstring &numeInstitute, const std::vector<Student> &students);

    void setStudent(const int& nrCrt);

    friend std::wostream &operator<<(std::wostream &os, const Institute &institute);

private:
    std::wstring numeInstitute;
    std::vector<Student> students;
};

#endif //VECTOROFOBJECTS_INSTITUTE_HPP
