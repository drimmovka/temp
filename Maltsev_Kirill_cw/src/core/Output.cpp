#include "Output.h"

#include <iostream>

Output::Output() = default;

Output::~Output() = default;

void Output::show_info_author(const std::string &option, 
                    const std::string &name, 
                    const std::string &surname)
{
    std::cout << "Course work for option " << option << ", created by " << name << " " << surname << std::endl;
}