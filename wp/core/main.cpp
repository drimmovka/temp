#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

#include "Student.h"

const std::string input_file_name = "input.txt";


std::vector<std::string> splitLine(std::string &line, char delim)
{
    line += delim; /* adding 1 more delim for catching last wrod */
    std::vector<std::string> splited_line;
    int delim_idx = 0;
    for (int i = 0; i < line.size(); i++) {
        if (line[i] == delim) {
            splited_line.push_back(line.substr(delim_idx, i - delim_idx));
            delim_idx = i + 1;
        }
    }
    return splited_line;
}

std::vector<std::vector<std::string>> getData(const std::string &input_file_name)
{
	std::ifstream fin("input.txt", std::ios::binary);

    std::vector<std::vector<std::string>> data;

    std::string line;
    while (getline(fin, line, '\n')) {
        data.push_back(splitLine(line, ' '));
    }
    
    return data;
}

bool isNumber(const std::string &str)
{
    for (int i = 0; i < str.size(); i++) {
        if (!isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

std::vector<std::vector<Subject>> getSessions(std::vector<std::string> &data_line)
{
    std::vector<std::vector<Subject>> sessions;

    int i = 11;
    std::vector<Subject> session;
    while (i < data_line.size()) {
        if (isNumber(data_line[i])) {
            sessions.push_back(session);
            session.clear();
            i++;
        } else {
            std::string name = data_line[i];
            uint grade = stoi(data_line[i+1]);
            Subject subject = Subject(name, grade);
            session.push_back(subject);
            i += 2;
        }
    }
    sessions.push_back(session);
    return sessions;
}

std::vector<Student> parseData(std::vector<std::vector<std::string>> &data)
{
    std::vector<Student> students;
    for (int i = 0; i < data.size(); i++) {
        std::string surname             = data[i][0];
        std::string name                = data[i][1];
        std::string patronymic          = data[i][2];
        std::string birth_date          = data[i][3];
        uint admission_year             = stoi(data[i][4]);
        std::string faculty             = data[i][5];
        std::string department          = data[i][6];
        std::string group               = data[i][7];
        std::string record_book_number  = data[i][8];
        std::string gender              = data[i][9];
        std::vector<std::vector<Subject>> sessions = getSessions(data[i]);
        
        
        Student student = Student(surname, name, patronymic, birth_date,
                                  admission_year, faculty, department, group,
                                  record_book_number, gender, sessions);
        students.push_back(student);
    }
    return students;
}

class Partition {
private:
	std::vector<Student> group1;
	std::vector<Student> group2;

public:
    Partition() = default;
    ~Partition() = default;

	void addInGroup1(Student element) {
		this->group1.push_back(element);
	}

	void addInGroup2(Student element) {
		this->group2.push_back(element);
	}

	void sortGroup1(bool(*cmp)(Student, Student)) {
		sort(this->group1.begin(), this->group1.end(), cmp);
	}

	void sortGroup2(bool(*cmp)(Student, Student)) {
		sort(this->group2.begin(), this->group2.end(), cmp);
	}

	void printGroup1() {
		std::cout << "[";
		for (int i = 0; i < this->group1.size(); i++) {
			std::cout << this->group1[i].getSurname();
			if (i != this->group1.size()-1) std::cout << ", ";
		}
		std::cout << "]\n";
	}

	void printGroup2() {
		std::cout << "[";
		for (int i = 0; i < this->group2.size(); i++) {
			std::cout << this->group2[i].getSurname();
			if (i != this->group2.size()-1) std::cout << ", ";
		}
		std::cout << "]\n";
	}

};

bool cmp(Student p1, Student p2) {
	return p1.getAcademicPerformance() < p2.getAcademicPerformance();
}

int main()
{

    std::vector<std::vector<std::string>> data = getData(input_file_name);
    std::vector<Student> students = parseData(data);

    // for (int i = 0; i < students.size(); i++) {        
    //     for (int j = 0; j < students[i].getSessions()->size(); j++) {
    //         std::cout << j << std::endl;
    //         for (int q = 0; q < students[i].getSessions()->size(); q++) {
    //             std::cout << (*students[i].getSessions())[j][q].getName() << " " << (*students[i].getSessions())[j][q].getName() << std::endl;
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    std::set<int> admission_years;
	for (int i = 0; i < students.size(); i++) {
		admission_years.insert(students[i].getAdmissionYear());
	}

	std::vector<Partition> partitions;
	for (int i : admission_years) {
		Partition partition;
		for (int j = 0; j < students.size(); j++) {
			if (students[j].getAdmissionYear() == i) {
				partition.addInGroup1(students[j]);
			} else {
				partition.addInGroup2(students[j]);
			}
		}
		partition.sortGroup1(cmp);
		partition.sortGroup2(cmp);
		partitions.push_back(partition);
	}
	for (int i = 0; i < partitions.size(); i++) {
		partitions[i].printGroup1();
		partitions[i].printGroup2();
		std::cout << std::endl;
	}

    
    // std::string command;
    // while (true) {
    //     std::cin >> command;
    //     if (command == "--output") {

    //     } else if (command == "--exit") {
    //         std::cout << "Interrupted" << std::endl;
    //         exit(0);
    //     } else {
    //         std::cout << "Wrong command" << std::endl;
    //     }
    // }
    
    return 0;
}