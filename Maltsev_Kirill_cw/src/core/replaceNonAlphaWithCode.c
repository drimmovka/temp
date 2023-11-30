#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "structures.h"

void getNewLength(Sentence* s, int* newLength) {
    for (int j=0; j<s->sentenceSize; j++) {
        if (!iswalpha(s->line[j])) {
            wchar_t* code = (wchar_t*) calloc(100, sizeof(wchar_t));
            swprintf(code, 10, L"%d", (int) s->line[j]); 
            (*newLength) += wcslen(code);
        }
    }
}

void rewriteSentence(Sentence* s, int newLength) {
    wchar_t* temp = (wchar_t*) calloc(newLength+1, sizeof(wchar_t));
    int q = 0;
    for (int j=0; j<s->sentenceSize; j++) {
        if (!iswalpha(s->line[j])) {
            wchar_t* code = (wchar_t*) calloc(100, sizeof(wchar_t));
            swprintf(code, 10, L"%d", (int) s->line[j]);
            for (int k=0; k<wcslen(code); k++) {
                temp[q] = code[k];
                q++;
            }
        } else {
            temp[q] = s->line[j];
            q++;
        }
    }
    s->line = (wchar_t*) calloc(newLength+1, sizeof(wchar_t));
    s->sentenceSize = newLength;
    wcscpy(s->line, temp);
}

void replaceNonAlphaWithCode(Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        int newLength = t->sentences[i].sentenceSize;
        getNewLength(&t->sentences[i], &newLength);
        rewriteSentence(&t->sentences[i], newLength);
    }
}