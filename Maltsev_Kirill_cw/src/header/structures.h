#ifndef STRUCTERES_H
#define STRUCTERES_H

typedef struct {
    char* line;
    int sentenceSize;
} Sentence;

typedef struct {
    Sentence* sentences;
    int sentencesNumber;
} Text;

Text* createText();

#endif