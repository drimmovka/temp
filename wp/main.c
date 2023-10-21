#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void split(char*);
char* get_text();
char* get_line(unsigned long int*);
int check_last_line(char*);
char* concatenate(char*, char*, int);

int main() {
    char* text = get_text();
    printf("----------\n");
    split(text);
}

void split(char* text) {
    char* sep = ".;?";
    char* substr;
    
    substr = strtok(text, sep);

    while (substr != NULL) {
        printf("%s\n", substr);
        substr = strtok(NULL, sep);
    }
}

char* get_text() {
    unsigned long int text_size = 1;
    int capacity = 1;
    char* text = (char*) malloc(sizeof(char));
    
    while (1) {
        unsigned long int line_size = 1;
        char* line = get_line(&line_size);
        text_size += line_size - 1;
        if (text_size >= capacity) {
            capacity = (int) pow(2, ceil(log2(text_size)));
            text = (char*) realloc(text, capacity * sizeof(char));
        }
        
        text = concatenate(text, line, capacity * sizeof(text));
        if (check_last_line(line)) {
            break;
        }
    }
    return text;
}


char* get_line(unsigned long int* line_size) {
    int capacity = 1;
    char* line = (char*) malloc(sizeof(char));
    char ch = getchar();
    while (ch != '\n') {
        line[(*line_size)-1] = ch;
        if ((*line_size) >= capacity) {
            capacity *= 2;
            line = (char*) realloc(line, capacity * sizeof(char));
        }
        (*line_size)++;
        ch = getchar();
    }
    return line;
}


int check_last_line(char* line) {
    char* check_sentence = "Dragon flew away!";
    int j = 16;
    for (unsigned long int i=strlen(line)-1; i>=0; i--) {
        if (line[i] == check_sentence[j]) {
            j--;
            if (j == -1) return 1;
        } else {
            break;
        }
    }
    return 0;
}


char* concatenate(char* string1, char* string2, int result_size) {
    unsigned long int length1 = strlen(string1);
    unsigned long int length2 = strlen(string2);

    char *result = malloc(result_size);

    memcpy(result, string1, length1);
    memcpy(result + length1, string2, length2 + 1);    

    return result;
}