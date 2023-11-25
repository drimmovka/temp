#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "structures.h"

void getNewLength(Sentence* s, int* newLength) {
    for (int j=0; j<s->sentenceSize; j++) {
        if (!isalpha(s->line[j])) {
            char* code = (char*) calloc(100, sizeof(char));
            sprintf(code, "%d", (int) s->line[j]); 
            (*newLength) += strlen(code);
        }
    }
}

void rewriteSentence(Sentence* s, int newLength) {
    char* temp = (char*) calloc(newLength+1, sizeof(char));
    int q = 0;
    for (int j=0; j<s->sentenceSize; j++) {
        if (!isalpha(s->line[j])) {
            char* code = (char*) calloc(100, sizeof(char));
            sprintf(code, "%d", (int) s->line[j]);
            for (int k=0; k<strlen(code); k++) {
                temp[q] = code[k];
                q++;
            }
        } else {
            temp[q] = s->line[j];
            q++;
        }
    }
    s->line = (char*) calloc(newLength+1, sizeof(char));
    s->sentenceSize = newLength;
    strcpy(s->line, temp);
}

void replaceNonAlphaWithCode(Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        int newLength = t->sentences[i].sentenceSize;
        getNewLength(&t->sentences[i], &newLength);
        rewriteSentence(&t->sentences[i], newLength);
    }
}