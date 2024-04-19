#ifndef STUDENT_H
#define STUDENT_H

#include "Subject.h"

#include <string>
#include <vector>


class Student
{

private:
	std::string surname;
	std::string name;
	std::string patronymic;
	std::string birth_date;
	uint admission_year;
	std::string faculty;
	std::string department;
	std::string group;
	std::string record_book_number;
	std::string gender;
    std::vector<std::vector<Subject>> sessions;

public:

	Student(std::string surname, std::string name, std::string patronymic, 
            std::string birth_date, uint admission_year, std::string faculty, 
            std::string department, std::string group, std::string record_book_number, 
            std::string gender, std::vector<std::vector<Subject>> sessions);
    
    ~Student();

	std::string getSurname();
	std::string getName();
	std::string getPatronymic();
	std::string getBirthDate();
	uint getAdmissionYear();
	std::string getFaculty();
	std::string getDepartment();
	std::string getGroup();
	std::string getRecordBookNumber();
	std::string getGender();
	std::vector<std::vector<Subject>> *getSessions();

	void setSurname(std::string surname);
	void setName(std::string name);
	void setPatronymic(std::string patronymic);
	void setBirthDate(std::string birth_date);
	void setAdmissionYear(uint admission_year);
	void setFaculty(std::string faculty);
	void setDepartment(std::string department);
	void setGroup(std::string group);
	void setRecordBookNumber(std::string record_book_number);
	void setGender(std::string gender);
	void setSessions(std::vector<std::vector<Subject>> sessions);

	double getAcademicPerformance();
};

#endif