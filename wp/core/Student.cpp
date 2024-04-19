#include "Student.h"

#include <sys/types.h>
#include <string>

Student::Student(std::string surname, std::string name, std::string patronymic, 
            std::string birth_date, uint admission_year, std::string faculty, 
            std::string department, std::string group, std::string record_book_number, 
            std::string gender, std::vector<std::vector<Subject>> sessions)
    {
		this->surname = surname;
		this->name = name;
		this->patronymic = patronymic;
		this->birth_date = birth_date;
		this->admission_year = admission_year;
		this->faculty = faculty;
		this->department = department;
		this->group = group;
		this->record_book_number = record_book_number;
		this->gender = gender;
        this->sessions = sessions;
	}

Student::~Student() = default;

std::string Student::getSurname()
{
    return this->surname;
}

std::string Student::getName()
{
    return this->name;
}

std::string Student::getPatronymic()
{
    return this->patronymic;
}

std::string Student::getBirthDate()
{
    return this->birth_date;
}

uint Student::getAdmissionYear()
{
    return this->admission_year;
}

std::string Student::getFaculty()
{
    return this->faculty;
}

std::string Student::getDepartment()
{
    return this->department;
}

std::string Student::getGroup()
{
    return this->group;
}

std::string Student::getRecordBookNumber()
{
    return this->record_book_number;
}

std::string Student::getGender()
{
    return this->gender;
}

std::vector<std::vector<Subject>> *Student::getSessions()
{
    return &this->sessions;
}


void Student::setSurname(std::string surname)
{
    this->surname = surname;
}

void Student::setName(std::string name)
{
    this->name = name;
}

void Student::setPatronymic(std::string patronymic)
{
    this->patronymic = patronymic;
}

void Student::setBirthDate(std::string birth_date)
{
	this->birth_date = birth_date;
}

void Student::setAdmissionYear(uint admission_year)
{
	this->admission_year = admission_year;
}

void Student::setFaculty(std::string faculty)
{
    this->faculty = faculty;
}

void Student::setDepartment(std::string department)
{
	this->department = department;
}

void Student::setGroup(std::string group)
{
	this->group = group;
}

void Student::setRecordBookNumber(std::string record_book_number)
{
	this->record_book_number = record_book_number;
}

void Student::setGender(std::string gender)
{
	this->gender = gender;
}

void Student::setSessions(std::vector<std::vector<Subject>> sessions)
{
	this->sessions = sessions;
}

double Student::getAcademicPerformance()
{
    int summary = 0;
    int count = 0;
    for (int i = 0; i < this->sessions.size(); i++) {
        count += this->sessions[i].size();
        for (int j = 0; j < this->sessions[i].size(); j++) {
            summary += this->sessions[i][j].getGrade();
        }
    }
    return summary / count;
}