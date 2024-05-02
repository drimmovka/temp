#include "Handler.h"

#include <getopt.h>
#include <iostream>
#include <map>
#include <string>

Handler::Handler() = default;

Handler::~Handler() = default;

struct Flag
{
    bool entered;
    std::string parameter;
};

void Handler::handleFlags(int argc, char **argv)
{
    std::map<int, Flag> flags = {
        {'h',    {0, ""}},
        {'i',    {0, ""}},
        {'o',    {0, ""}},
        {1001,   {0, ""}},
        {1002,   {0, ""}},
        {1003,   {0, ""}},
        {1004,   {0, ""}},
        {1005,   {0, ""}},
        {1006,   {0, ""}},
        {1007,   {0, ""}},
        {1008,   {0, ""}},
        {1009,   {0, ""}},
        {1010,   {0, ""}},
        {1011,   {0, ""}},
        {1012,   {0, ""}},
        {1013,   {0, ""}},
        {1014,   {0, ""}},
        {1015,   {0, ""}},
        {1016,   {0, ""}},
        {1017,   {0, ""}}
    };

    const char *short_options = "hi:o:";
    const struct option long_options[] = {
        {"help",            no_argument,       NULL, 'h'},
        {"input",           required_argument, NULL, 'i'},
        {"output",          required_argument, NULL, 'o'},
        {"info",            no_argument,       NULL, 1001},
        
        {"thickness",       no_argument,       NULL, 1002},
        {"color",           no_argument,       NULL, 1003},
        {"fill",            no_argument,       NULL, 1004},
        {"fill_color",      no_argument,       NULL, 1005},

        {"circle",          no_argument,       NULL, 1006},
        {"center",          no_argument,       NULL, 1007},
        {"radius",          no_argument,       NULL, 1008},
        
        {"rgbfilter",       no_argument,       NULL, 1009},
        {"component_name",  no_argument,       NULL, 1010},
        {"component_value", no_argument,       NULL, 1011},
        
        {"split",           no_argument,       NULL, 1012},
        {"number_x",        no_argument,       NULL, 1013},
        {"number_y",        no_argument,       NULL, 1014},
        
        {"squared_lines",   no_argument,       NULL, 1015},
        {"left_up",         no_argument,       NULL, 1016},
        {"side_size",       no_argument,       NULL, 1017},
        
        {NULL,     0,                 NULL, 0}
    };
    
    int option;
    while ((option = getopt_long(argc, argv, short_options, long_options, NULL)) != -1) {
        if (flags.find(option) != flags.end()) {
            flags[option].entered = true;
            if (optarg) {
                flags[option].parameter = optarg;
            }
        } else {
            return;
        }
    }
}