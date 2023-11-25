#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structures.h"
#include "bst.h"

char* sentenceToUpper(Sentence* s) {
    char* cpy = (char*) calloc( strlen(s->line)+1, sizeof(char) );
    strcpy(cpy, s->line);
    for (int j=0; j<strlen(cpy); j++) {
        cpy[j] = toupper(cpy[j]);
    }
    return cpy;
}

void fillBstBySentences(Bst* bst, Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        char* cpy = sentenceToUpper(&t->sentences[i]);
        insert(bst, cpy);
    }
}

void removeDuplicates(Text* t) {
    Bst* bst = createBst();
    fillBstBySentences(bst, t);
    
    int j = 0;
    for (int i=0; i<t->sentencesNumber; i++) {
        
        char* cpy = sentenceToUpper(&t->sentences[i]);

        if (find(bst, cpy) == 1) {
            t->sentences[j] = t->sentences[i];
            j++;
        }
    }
    t->sentencesNumber = j;
}