#ifndef SUBJECT_H
#define SUBJECT_H

#include <sys/types.h>
#include <string>

class Subject
{

private:
    std::string name;
    uint grade;

public:
    Subject(std::string name, uint grade);
    ~Subject();
    std::string getName();
    uint getGrade();
    void setName(std::string name);
    void setGrade(uint grade);

};

#endif