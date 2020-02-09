#include <iostream>
#include "Institute.hpp"

int main() {

    Institute institut1{L"bucuresti", {{1, L"Alin"}, {2,L"Mihai"}}};

    std::wcout << institut1 << std::endl;

    institut1.setOjbect(2);

    std::wcout << institut1 << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
