#include <wchar.h>

#include "structures.h"

#define OPTION L"5.5"
#define NAME L"Kirill"
#define SURNAME L"Maltsev"

void printCourseInfoAndAuthor() {
    wprintf(L"Course work for option %ls, created by %ls %ls.\n", OPTION, NAME, SURNAME);
}

void printText(Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        wprintf(L"%ls\n", t->sentences[i].line);
    }
}