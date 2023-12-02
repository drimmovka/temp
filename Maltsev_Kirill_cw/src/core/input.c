#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "structures.h"

void getTestType(int* testType) {
    wscanf(L"%d", testType);
}

wchar_t* getInput(int* sentencesNumber) {
    
    int text_size = 0;
    int capacity = 0;
    wchar_t* t = NULL;

    int newLineCount = 0;
    wchar_t ch = getwchar(); // skipping the first '\n'
    while (newLineCount < 2) {
        ch = getwchar();
        if (ch == '\n') newLineCount++;
        else newLineCount = 0;
        
        if (text_size + 1 >= capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            t = (wchar_t*) realloc(t, capacity * sizeof(wchar_t));
        }
        
        if (ch == L'.') {
            (*sentencesNumber)++;
        }

        t[text_size] = ch;
        text_size++;
    }
    t[text_size-2] = L'\0';
    return t;
}

void splitText(Text* t, wchar_t* input) {
    t->sentences = (Sentence*) malloc(t->sentencesNumber * sizeof(Sentence));
    wchar_t* delim = L".";
    wchar_t* token;
    wchar_t* ptr;

    token = wcstok(input, delim, &ptr);
    int i = 0;
    while (token != NULL) {
        while (iswspace(*token)) {
    		token++;
		}
        t->sentences[i].line = (wchar_t*) calloc(wcslen(token)+2, sizeof(wchar_t));
        wcscpy(t->sentences[i].line, token);
        t->sentences[i].line[wcslen(token)] = L'.';
        t->sentences[i].sentenceSize = wcslen(t->sentences[i].line);
        i++;
        token = wcstok(NULL, delim, &ptr);
    }
}