#include "output.h"
#include "help.h"
#include "error.h"
#include "structures.h"
#include "countWords.h"
#include "replaceNonAlphaWithCode.h"
#include "sort.h"
#include "removeUpperAndSpecialSymbolsCase.h"

int textWillBeEntered(int testType) {
    if (testType < 0 || testType > 5) {
        printCourseInfoAndAuthor();
        throwTestTypeError();
        return 0;
    } else if (testType == 5) {
        printCourseInfoAndAuthor();
        help();
        return 0;
    }
    return 1;
}

void allocator(Text* t, int testType) {
    switch (testType)
    {
    case 0:
        printCourseInfoAndAuthor();
        printText(t);
        break;
    case 1:
        printCourseInfoAndAuthor();
        countWords(t);
        break;
    case 2:
        replaceNonAlphaWithCode(t);
        printCourseInfoAndAuthor();
        printText(t);
        break;
    case 3:
        sortByLatinSymbols(t);
        printCourseInfoAndAuthor();
        printText(t);
        break;
    case 4:
        removeUpperAndSpecialSymbolsCase(t);
        printCourseInfoAndAuthor();
        printText(t);
        break;
    }
}