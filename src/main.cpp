#include <iostream>
#include "Institute.hpp"

int main() {

    Institute institut1{L"Bucuresti"};

    incarcareDateStudentiDinFisier("../resources/input_special.csv",institut1);

    std::wcout << institut1 << std::endl;

    institut1.setStudentLocRepartizat(2);

    std::wcout << institut1 << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
