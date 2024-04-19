#include "Subject.h"

#include <sys/types.h>
#include <string>

Subject::Subject(std::string name, uint grade)
{
    this->name = name;
    this->grade = grade;
}

Subject::~Subject() = default;

std::string Subject::getName()
{
    return this->name;
}

uint Subject::getGrade()
{
    return this->grade;
}

void Subject::setName(std::string name)
{
    this->name = name;
}

void Subject::setGrade(uint grade)
{
    this->grade = grade;
}