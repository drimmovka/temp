#ifndef TEST_H
#define TEST_H

#include <string>

class Output
{
public:
    Output();
    ~Output();

    static void show_info_author(const std::string &option, 
                    const std::string &name, 
                    const std::string &surname);
};

#endif