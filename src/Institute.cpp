//
// Created by gabi on 09.02.2020.
//

#include "Institute.hpp"
#include <algorithm>

Institute::Institute(const std::wstring &numeInstitute, const std::vector<Student> &students) : numeInstitute(
        numeInstitute), students(students) {}

void Institute::setStudent(const int& nrCrt)
{
    auto place = std::find_if(students.begin(), students.end(),
            [&nrCrt](Student& student){return student.getNrCrt() == nrCrt; });

    students.at((place - students.begin())).setDeSetat(L"setaat");
}

std::wostream &operator<<(std::wostream &os, const Institute &institute) {
    os << "nume Institute: " << institute.numeInstitute << " \nobjects: \n";
    for(auto const& object : institute.students)
        os << "\t" << object << " ";
    os << std::endl;
    return os;
}
