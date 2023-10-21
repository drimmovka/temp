#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_text(char*, char**);
char* get_text(int*, int*);

int main() {
    int text_size = 1, array_size = 0;;
    char* text = get_text(&text_size, &array_size);

    printf("%ld\n", strlen(text));
    printf("%d\n", array_size);
    
    char* punctuation = malloc(array_size * sizeof(char));
    char** array = malloc(array_size * sizeof(char*));

    int j = 0;
    for (int i=0; i<text_size-1; i++) {
        if (text[i] == '.' || text[i] == ';' || text[i] == '?') {
            punctuation[j] = text[i];
            j++;
        }
    }

    split_text(text, array);

    for (int i=0; i<array_size; i++) {
        int fl = 0;
        for (int j=0; j<strlen(array[i]); j++) {
            if (array[i][j] != ' ' && array[i][j] != '\n') fl = 1;
            if (fl && array[i][j] != '\n') {
                printf("%c", array[i][j]);
            }
        }
        printf("%c\n", punctuation[i]);
    }
    printf("Dragon flew away!\n");
}


void split_text(char* text, char** array) {
    char* sep = ".;?";
    char* substr;
    
    substr = strtok(text, sep);
    int i = 0;
    while (substr != NULL) {
        array[i] = substr;
        i++;
        substr = strtok(NULL, sep);
    }
}

char* get_text(int* text_size, int* array_size) {
    int capacity = 1;
    char* text = (char*) malloc(sizeof(char));
    char ch = getchar();
    while (ch != '!') {
        text[(*text_size)-1] = ch;
        if ((*text_size) >= capacity) {
            capacity *= 2;
            text = (char*) realloc(text, capacity * sizeof(char));
        }
        (*text_size)++;
        if (ch == '.' || ch == ';' || ch == '?') {
            (*array_size)++;
        }
        ch = getchar();
    }
    return text;
}
