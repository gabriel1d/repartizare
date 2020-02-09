//
// Created by gabi on 09.02.2020.
//

#include "Student.hpp"

Student::Student(int nrCrt, const std::wstring &nume) : nrCrt(nrCrt), nume(nume) {}

void Student::setDeSetat(const std::wstring &deSetat) {
    Student::deSetat = deSetat;
}

std::wostream &operator<<(std::wostream &os, const Student &object) {
    os << "nrCrt: " << object.nrCrt << " nume: " << object.nume << " deSetat: " << object.deSetat << "\n";
    return os;
}

int Student::getNrCrt() const {
    return nrCrt;
}
