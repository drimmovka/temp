#include <stdlib.h>

#include "structures.h"

Sentence* createSentence() {
    Sentence* s = (Sentence*) malloc(sizeof(Sentence));
    s->line = NULL;
    s->sentenceSize = 0;
    return s;
}

Text* createText() {
    Text* t = (Text*) malloc(sizeof(Text));
    t->sentences = NULL;
    t->sentencesNumber = 0;
    return t;
}