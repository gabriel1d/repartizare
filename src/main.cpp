#include <iostream>
#include "Institute.hpp"

int main() {
    std::vector<Optiune> optiuniPrimite1{{L"Brașov-fără cazare",2},
                                         {L"Cluj-Napoca-cu cazare",1},
                                         {L"Cluj-Napoca-fără cazare",10},
                                         {L"Constanța-cu cazare",1},
                                         {L"Constanța-fără cazare",1},
                                         {L"Chișinău-cu cazare",3},
                                         {L"Chișinău-fără cazare",6},
                                         {L"Craiova-cu cazare",1},
                                         {L"Craiova-fără cazare",5},
                                         {L"Oradea-cu cazare",1},
                                         {L"Oradea-fără cazare",3},
                                         {L"Galați-cu cazare",1},
                                         {L"Galați-fără cazare",4},
                                         {L"Iași-cu cazare",1},
                                         {L"Iași-fără cazare",8},
                                         {L"Timișoara-cu cazare",2},
                                         {L"Timișoara-fără cazare",3},
                                         {L"Sibiu-cu cazare",1},
                                         {L"Sibiu-fără cazare",999},
                                         {L"Târgu Mureș-cu cazare",1},
                                         {L"Târgu Mureș-fără cazare",999}};

    Institute institut1{L"Bucuresti"};

    institut1.setOptiuniPrimite(optiuniPrimite1);

    printareOptiuniPrimite(institut1);

    incarcareDateStudentiDinFisier("../resources/input_special.csv",institut1);

    std::wcout << std::endl;

    institut1.repartizareStudentiPentruOptiune();

    printareOptiuniPrimite(institut1);

    printfStudents(institut1);
//    printareStudenti(institut1);
//    printareStudentiRepartizatiPentruOptiunea(institut1, L"Nerepartizat");

//    sendStudentsToCSV(institut1,L"Nerepartizat", "../resources/output.csv");
//
//    int i=0;
//
//    for (auto const optiune : optiuniPrimite1)
//    {
//        std::string outputCSV = "../resources/output" + std::to_string(i) + ".csv";
//
//        sendStudentsToCSV(institut1, optiune.numeLoc, outputCSV);
//        i++;
//    }
//    printareStudentiRepartizatiPentruOptiunea(institut1, L"Nerepartizat");


//    printareStudentiRepartizatiPentruOptiunea(institut1, L"Brașov-fără cazare");

//    printareStudenti(institut1);
//
//    std::wcout << institut1 << std::endl;
//
//    institut1.setStudentLocRepartizat(2);
//
//    std::wcout << institut1 << std::endl;
//
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}
