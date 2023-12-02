#include <wchar.h>
#include <wctype.h>

#include "structures.h"

int checkCase(Sentence* s) {
    int flag = 0;
    for (int i=0; i<s->sentenceSize; i++) {
        if (s->line[i] == L'#' || s->line[i] == L'$' || s->line[i] == L'^' || s->line[i] == L'%' || s->line[i] == L'@') flag = 1;
        if (iswupper(s->line[i])) return 0;
    }
    return flag;
}

void removeUpperAndSpecialSymbolsCase(Text* t) {
    int j = 0;
    for (int i=0; i<t->sentencesNumber; i++) {
        if (!checkCase(&t->sentences[i])) {
            t->sentences[j] = t->sentences[i];
            j++;
        }
    }
    t->sentencesNumber = j;
}