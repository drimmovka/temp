#ifndef HANDLER_H
#define HANDLER_H

#include <getopt.h>
#include <map>
#include <string>
#include <set>

#define FLAGS_NUMBER            21

#define HELP_IDX                'h'
#define INPUT_IDX               'i'
#define OUTPUT_IDX              'o'
#define INFO_IDX                1001

#define THICKNESS_IDX           1002
#define COLOR_IDX               1003
#define FILL_IDX                1004
#define FILL_COLOR_IDX          1005

#define CIRCLE_IDX              1006
#define CENTER_IDX              1007
#define RADIUS_IDX              1008

#define RGBFILTER_IDX           1009
#define COMPONENT_NAME_IDX      1010
#define COMPONENT_VALUE_IDX     1011

#define SPLIT_IDX               1012
#define NUMBER_X_IDX            1013
#define NUMBER_Y_IDX            1014

#define SQUARED_LINES_IDX       1015
#define LEFT_UP_IDX             1016
#define SIDE_SIZE_IDX           1017


struct Flag
{
    bool entered;
    std::string parameter;
};

class Handler
{
private:
    std::map<int, Flag>    flags_;
    const char             *short_options_;
    const struct option    long_options_[FLAGS_NUMBER];
    std::string            last_argument;
    
    std::set<int> getRedundantFlags(std::set<int>& required_flags, 
        std::set<int>& optional_flags);

    bool checkFlagCompliance(std::set<int>& required_flags, 
        std::set<int>& redundant_flags);

    bool isHelp();
    bool isInfo();
    bool isCircle();
    bool isRGBFilter();
    bool isSplit();
    bool isSquaredLines();

    void getFinFoutNames(std::string &input_file_name, std::string &output_file_name);
    
    void CircleFunc();
    void RGBFilterFunc();
    void SplitFunc();
    void SquaredLinesFunc();

public:
    Handler();
    ~Handler();
    void getFlags(int argc, char **argv);
    void handleFlags();
};

#endif