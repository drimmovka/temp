#include <stdlib.h>
#include "structures.h"

Sentence* createSentence() {
    Sentence* s = (Sentence*) malloc(sizeof(Sentence));
    s->line = NULL;
    s->sentence_size = 0;
    return s;
}

Text* createText() {
    Text* t = (Text*) malloc(sizeof(Text));
    t->sentences = createSentence();
    t->sentences_number = 0;
    return t;
}