#include <stdlib.h>
#include <locale.h>
#include <wchar.h>


#include "structures.h"
#include "removeDuplicates.h"
#include "allocator.h"
#include "input.h"
#include "output.h"

int main() {
    setlocale(LC_CTYPE, "");
    int testType;
    getTestType(&testType);

    if (textWillBeEntered(testType)) {
        Text* text = createText();
        wchar_t* input = getInput(&(text->sentencesNumber));
        
        splitText(text, input);

        removeDuplicates(text);
        
        allocator(text, testType);
        free(text);
    }
    return 0;
}