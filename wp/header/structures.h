#ifndef STRUCTERES_H
#define STRUCTERES_H

typedef struct {
    char* line;
    int sentence_size;
} Sentence;

typedef struct {
    Sentence* sentences;
    int sentences_number;
} Text;

Text* createText();

#endif