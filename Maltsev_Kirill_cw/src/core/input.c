#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structures.h"

void getTestType(int* testType) {
    scanf("%d", testType);
}

char* getInput(int* sentencesNumber) {
    
    int text_size = 0;
    int capacity = 0;
    char* t = NULL;

    int newLineCount = 0;
    char ch = getchar(); // skipping the first '\n'
    while (newLineCount < 2) {
        ch = getchar();
        if (ch == '\n') newLineCount++;
        else newLineCount = 0;
        
        if (text_size + 1 >= capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            t = (char*) realloc(t, capacity * sizeof(char));
        }
        
        if (ch == '.') {
            (*sentencesNumber)++;
        }

        t[text_size] = ch;
        text_size++;
    }
    t[text_size-2] = '\0';
    return t;
}

void splitText(Text* t, char* input) {
    t->sentences = (Sentence*) malloc(t->sentencesNumber * sizeof(Sentence));
    char* sep = ".";
    char* substr;

    substr = strtok(input, sep);
    int i = 0;
    while (substr != NULL) {
        while (isspace(*substr)) {
    		substr++;
		}
        t->sentences[i].line = (char*) calloc(strlen(substr)+2, sizeof(char));
        strcpy(t->sentences[i].line, substr);
        t->sentences[i].line[strlen(substr)] = '.';
        t->sentences[i].sentenceSize = strlen(t->sentences[i].line);
        i++;
        substr = strtok(NULL, sep);
    }
}