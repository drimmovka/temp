#include <stdlib.h>
#include <wchar.h>
#include <wctype.h>

#include "structures.h"
#include "bst.h"

void insertWords(Bst* bst, wchar_t* line) {
    wchar_t* delim = L"., \f\n\r\t\v";
    wchar_t* token;
    wchar_t* ptr;

    token = wcstok(line, delim, &ptr);
    while (token != NULL) {
        while (iswspace(*token)) {
    		token++;
		}
        insert(bst, token);
        token = wcstok(NULL, delim, &ptr);        
    }
}

void fillBstByWords(Bst* bst, Text* t) {
    for (int i=0; i<t->sentencesNumber; i++) {
        wchar_t* cpy = (wchar_t*) calloc(wcslen(t->sentences[i].line)+1, sizeof(wchar_t));
        wcscpy(cpy, t->sentences[i].line);
        insertWords(bst, cpy);
    }
}

void countWords(Text* t) {
    Bst* bst = createBst();
    fillBstByWords(bst, t);
    InorderTraversal(bst);
    free(bst);
}