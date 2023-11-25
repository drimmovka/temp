#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "structures.h"
#include "bst.h"

void insertWords(Bst* bst, char* line) {
    char* sep = "., \f\n\r\t\v";
    char* substr;

    substr = strtok(line, sep);
    while (substr != NULL) {
        while (isspace(*substr)) {
    		substr++;
		}
        insert(bst, substr);
        substr = strtok(NULL, sep);        
    }
}

void fillBstByWords(Bst* bst, Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        char* cpy = (char*) calloc(strlen(t->sentences[i].line)+1, sizeof(char));
        strcpy(cpy, t->sentences[i].line);
        insertWords(bst, cpy);
    }
}

void countWords(Text* t) {
    Bst* bst = createBst();
    fillBstByWords(bst, t);
    InorderTraversal(bst);
    free(bst);
}