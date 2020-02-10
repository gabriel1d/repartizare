#ifndef GROUPOFSTUDENTSFORINSTITUTE_HPP
#define GROUPOFSTUDENTSFORINSTITUTE_HPP

#include "Student.hpp"
#include <memory>

class GroupOfStudentsForInstitute {
public:
    GroupOfStudentsForInstitute(const std::wstring &mNumeGrup);

    void emplaceSharedPointerOfStudentBack(const std::shared_ptr<Student>& student);


private:
    std::wstring mNumeGrup;
    std::vector<std::shared_ptr<Student>> mStudentsGroup;
};


#endif // GROUPOFSTUDENTSFORINSTITUTE_HPP
