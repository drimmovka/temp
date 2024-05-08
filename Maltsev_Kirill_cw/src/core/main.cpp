#include "EditorPNG.h"
#include "Output.h"
#include "Handler.h"

#include "EditorPNG.h"

#include <iostream>

int main(int argc, char **argv)
{
    Output::show_author_info("5.17", "Kirill", "Maltsev");
    Handler handler;
    handler.getFlags(argc, argv);
    handler.handleFlags();
    return 0;
}