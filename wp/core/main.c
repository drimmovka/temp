#include <stdio.h>
#include <stdlib.h>

#include "structures.h"
#include "allocator.h"
#include "input.h"
#include "output.h"

int main() {
    int test_type;
    getTestType(&test_type);

    Text* text = createText();
    char* input = getInput(&(text->sentences_number));

    splitText(text, input);

    
    allocator(text, test_type);

    printCourseInfoAndAuthor();
    printText(text);
}