#include <iostream>
#include "Institute.hpp"
#include "GroupOfStudentsForInstitute.hpp"

void workBitch(const Institute& institute)
{
    for(auto& student : institute.getMStudents())
    {
        GroupOfStudentsForInstitute grup{L"Niste Handicapati"};
        if(student->getNrCrt() == 18)
        {
            grup.emplaceSharedPointerOfStudentBack(student);
            auto a = student.use_count();
            auto b=2;
        }

        int a = 1;
    }
}
int main() {

    Institute institut1{L"Bucuresti"};
    Student gheo{18,L"gheo",1,1,1,1,L"",12,{L"acasa"}};
    Student ion{12,L"ion",1,1,1,1,L"",12,{L"acasa"}};
    Student nani{18,L"nani",1,1,1,1,L"",12,{L"acasa"}};
    std::vector<std::shared_ptr<Student>> students{std::make_shared<Student>(gheo), std::make_shared<Student>(ion), std::make_shared<Student>(nani)};

    institut1.setStudents(students);

    workBitch(institut1);

    incarcareDateStudentiDinFisier("../resources/input_special.csv",institut1);

    std::wcout << institut1 << std::endl;

    institut1.setStudentLocRepartizat(2);

    std::wcout << institut1 << std::endl;

    std::cout << "Hello, World!" << std::endl;
    return 0;
}
