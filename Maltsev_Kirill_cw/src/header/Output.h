#ifndef TEST_H
#define TEST_H

#include <string>

class Output
{
public:
    Output();
    ~Output();

    static void show_author_info(const char *option, const char *name, const char *surname);
    static void help();
};

#endif