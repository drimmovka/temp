#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "structures.h"
#include "bst.h"

wchar_t* sentenceToUpper(Sentence* s) {
    wchar_t* cpy = (wchar_t*) calloc( wcslen(s->line)+1, sizeof(wchar_t) );
    wcpcpy(cpy, s->line);
    for (int j=0; j<wcslen(cpy); j++) {
        cpy[j] = towupper(cpy[j]);
    }
    return cpy;
}

void fillBstBySentences(Bst* bst, Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        wchar_t* cpy = sentenceToUpper(&t->sentences[i]);
        insert(bst, cpy);
    }
}

void removeDuplicates(Text* t) {
    Bst* bst = createBst();
    fillBstBySentences(bst, t);
    
    int j = 0;
    for (int i=0; i<t->sentencesNumber; i++) {
        
        wchar_t* cpy = sentenceToUpper(&t->sentences[i]);

        if (find(bst, cpy) == 1) {
            t->sentences[j] = t->sentences[i];
            j++;
        }
    }
    t->sentencesNumber = j;
    free(bst);
}