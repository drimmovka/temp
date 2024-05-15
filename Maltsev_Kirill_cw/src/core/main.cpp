#include "Output.h"
#include "Handler.h"
#include "EditorPNG.h"

int main(int argc, char **argv)
{
    Output::show_author_info("5.17", "Kirill", "Maltsev");
    hdlr::Handler handler;
    handler.getFlags(argc, argv);
    handler.handleFlags();
    return 0;
}