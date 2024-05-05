#include "EditorPNG.h"
#include "Output.h"
#include "Handler.h"


int main(int argc, char **argv)
{
    Output::show_info_author("5.17", "Kirill", "Maltsev");

    Handler handler;
    handler.getFlags(argc, argv);
    handler.handleFlags();
    return 0;
}