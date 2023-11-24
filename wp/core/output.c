#include <stdio.h>
#include "structures.h"

#define OPTION "5.5"
#define NAME "Kirill"
#define SURNAME "Maltsev"

void printCourseInfoAndAuthor() {
    printf("Course work for option %s, created by %s %s.\n", OPTION, NAME, SURNAME);
}

void printText(Text* text) {
    for (int i=0; i<text->sentences_number; i++) {
        printf("%d %s\n", i, text->sentences[i].line);
    }
}