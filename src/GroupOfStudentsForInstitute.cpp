#include "GroupOfStudentsForInstitute.hpp"

GroupOfStudentsForInstitute::GroupOfStudentsForInstitute(const std::wstring &mNumeGrup) : mNumeGrup(mNumeGrup) {}

void GroupOfStudentsForInstitute::emplaceSharedPointerOfStudentBack(const std::shared_ptr<Student>& input)
{
    GroupOfStudentsForInstitute::mStudentsGroup.emplace_back(input);
}