//
// Created by gabi on 09.02.2020.
//

#include "Institute.hpp"
#include <algorithm>

Object::Object(int nrCrt, const std::wstring &nume) : nrCrt(nrCrt), nume(nume) {}

void Object::setDeSetat(const std::wstring &deSetat) {
    Object::deSetat = deSetat;
}

std::wostream &operator<<(std::wostream &os, const Object &object) {
    os << "nrCrt: " << object.nrCrt << " nume: " << object.nume << " deSetat: " << object.deSetat << "\n";
    return os;
}

Institute::Institute(const std::wstring &numeInstitute, const std::vector<Object> &objects) : numeInstitute(
        numeInstitute), objects(objects) {}

void Institute::setOjbect(const int& nrCrt)
{
    auto place = std::find_if(objects.begin(), objects.end(),
            [&nrCrt](Object& object){return object.nrCrt == nrCrt; });

    objects.at((place - objects.begin())).setDeSetat(L"setaat");
}

std::wostream &operator<<(std::wostream &os, const Institute &institute) {
    os << "nume Institute: " << institute.numeInstitute << " \nobjects: \n";
    for(auto const& object : institute.objects)
        os << "\t" << object << " ";
    os << std::endl;
    return os;
}
