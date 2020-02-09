//
// Created by gabi on 09.02.2020.
//

#ifndef REPARTIZARE_STUDENT_HPP
#define REPARTIZARE_STUDENT_HPP
#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>

class Student {
public:
    Student(int nrCrt, const std::wstring &nume);

    void setDeSetat(const std::wstring &deSetat);

    friend std::wostream &operator<<(std::wostream &os, const Student &object);

    int getNrCrt() const;

private:
    int nrCrt;
    std::wstring nume;
    std::wstring deSetat{L""};
};


#endif //REPARTIZARE_STUDENT_HPP
