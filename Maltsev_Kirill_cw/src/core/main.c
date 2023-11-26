#include <stdlib.h>

#include "structures.h"
#include "removeDuplicates.h"
#include "allocator.h"
#include "input.h"
#include "output.h"

int main() {
    int testType;
    getTestType(&testType);

    if (textWillBeEntered(testType)) {
        Text* text = createText();
        char* input = getInput(&(text->sentencesNumber));
        
        splitText(text, input);

        removeDuplicates(text);
        
        allocator(text, testType);
        free(text);
    }
    return 0;
}