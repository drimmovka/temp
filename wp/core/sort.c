#include <stdlib.h>
#include <ctype.h>
#include "structures.h"

#define ASCII_CODE_A 65
#define ASCII_CODE_B 90

int countLatinLetters(Sentence* sentence) {
    int cnt = 0;
    for (int i=0; i<sentence->sentence_size; i++) {
        int code = (int) toupper(sentence->line[i]);
        if (code >= ASCII_CODE_A && code <= ASCII_CODE_B) cnt++;
    }
    return cnt;
}

int cmp(const void* p1, const void* p2) {
    return countLatinLetters((Sentence*) p1) - countLatinLetters((Sentence*) p2);
}

void sortByLatinLetters(Text* text) {
    qsort(text->sentences, text->sentences_number, sizeof(Sentence), cmp);
}