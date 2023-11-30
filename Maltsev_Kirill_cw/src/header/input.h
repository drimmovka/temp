#ifndef INPUT_H
#define INPUT_H

#include <wchar.h>

#include "structures.h"

void getTestType(int*);
wchar_t* getInput(int*);
void splitText(Text*, wchar_t*);

#endif