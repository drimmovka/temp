#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"

void getTestType(int* test_type) {
    scanf("%d\n", test_type);
}

char* getInput(int* sentences_number) {
    
    int text_size = 0;
    int capacity = 0;
    char* text = NULL;

    int newLineCount = 0;
    while (newLineCount < 2) {
        char ch = getchar();
        if (ch == '\n') newLineCount++;
        else newLineCount = 0;
        
        if (text_size + 1 >= capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            text = (char*) realloc(text, capacity * sizeof(char));
        }
        
        if (ch == '.') {
            (*sentences_number)++;
        }

        text[text_size] = ch;
        text_size++;
    }
    text[text_size-2] = '\0';
    return text;
}

void splitText(Text* text, char* input) {
    text->sentences = (Sentence*) malloc(text->sentences_number * sizeof(Sentence));
    char* sep = ".";
    char* substr;

    substr = strtok(input, sep);
    int i = 0;
    while (substr != NULL) {
        while (isspace(*substr)) {
    		substr++;
		}
        text->sentences[i].line = (char*) malloc((strlen(substr)+2) * sizeof(char));
        strcpy(text->sentences[i].line, substr);
        text->sentences[i].line[strlen(substr)] = '.';
        text->sentences[i].line[strlen(substr)+1] = '\0';
        text->sentences[i].sentence_size = strlen(text->sentences[i].line);
        i++;
        substr = strtok(NULL, sep);
    }
}