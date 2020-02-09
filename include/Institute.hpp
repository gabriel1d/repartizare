//
// Created by gabi on 09.02.2020.
//

#ifndef VECTOROFOBJECTS_INSTITUTE_HPP
#define VECTOROFOBJECTS_INSTITUTE_HPP

#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>

struct Object
{
    int nrCrt;
    std::wstring nume;
    std::wstring deSetat{L""};

    Object(int nrCrt, const std::wstring &nume);

    void setDeSetat(const std::wstring &deSetat);

    friend std::wostream &operator<<(std::wostream &os, const Object &object);
};

class Institute {
public:
    Institute(const std::wstring &numeInstitute, const std::vector<Object> &objects);

    void setOjbect(const int& nrCrt);

    friend std::wostream &operator<<(std::wostream &os, const Institute &institute);

private:
    std::wstring numeInstitute;
    std::vector<Object> objects;
};

#endif //VECTOROFOBJECTS_INSTITUTE_HPP
