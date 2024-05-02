#ifndef HANDLER_H
#define HANDLER_H

class Handler
{
public:
    Handler();
    ~Handler();
    static void handleFlags(int argc, char **argv);
};

#endif