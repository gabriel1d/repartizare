#ifndef INSTITUTE_HPP
#define INSTITUTE_HPP

#include <iosfwd>
#include <string>
#include <vector>
#include <ostream>
#include <memory>

#include "Student.hpp"

struct Optiune
{
    std::wstring numeLoc;
    int numarLocuriDisponibile;
    int numarLocuriRamase;

    Optiune(const std::wstring &numeLoc, int numarLocuriDisponibile);
};

class Institute {
public:
    Institute(const std::wstring &numeInstitute);

    void setStudentLocRepartizat(const int& nrCrt);

    int findOptiuneDupanume(const std::wstring& numeOptiuneAleasa);

    void setOptiuniPrimite(const std::vector<Optiune> &mOptiuniPrimite);

    void setStudents(std::vector<std::shared_ptr<Student>> &students);

    void repartizareStudentiPentruOptiune();

    friend void printfStudents(const Institute& institute);
    friend void printareOptiuniPrimite(const Institute &institute);
    friend void printareStudentiRepartizatiPentruOptiunea(const Institute& institute, const std::wstring& optiune);
    friend void sendStudentsToCSV(const Institute& institute, const std::wstring& optiune, const std::string& stringOutputFile);
private:
    std::wstring mNumeInstitute;
    std::vector<Optiune> mOptiuniPrimite;
    std::vector<std::shared_ptr<Student>> mStudents;
};

void incarcareDateStudentiDinFisier(const std::string& fisierulSursa, Institute& institutie);

#endif // INSTITUTE_HPP
