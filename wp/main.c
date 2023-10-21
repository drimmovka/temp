#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split_text(char*, char**);
char* get_text(int*, int*);
void fill_punctuation(char*, char*, int);
void output_sentences(char**, char*, int n);
int check_sentence(char*);

int main() {
    int text_size = 1, n = 0;
    char* text = get_text(&text_size, &n);
    
    char* punctuation = malloc(n * sizeof(char));
    fill_punctuation(text, punctuation, text_size);
    
    char** sentences = malloc(n * sizeof(char*));
    split_text(text, sentences);

    output_sentences(sentences, punctuation, n);
}


int check_sentence(char* sentence) {
    return 1;
    int count_upper = 0;
    for (int i=0; i<strlen(sentence); i++) {
        int code = (int) sentence[i];
        if (65 <= code && code <= 90) count_upper++;
    }
    return (count_upper > 1);
}

void output_sentences(char** sentences, char* punctuation, int n) {
    int m = 0;
    for (int i=0; i<n; i++) {        
        if (1) {
            m++;
            int flag = 0;
            for (int j=0; j<strlen(sentences[i]); j++) {
            if (sentences[i][j] != ' ' && sentences[i][j] != '\n')
                flag = 1;
            if (flag && sentences[i][j] != '\n') 
                printf("%c", sentences[i][j]);
        }
        printf("%c\n", punctuation[i]);
        }
    }
    printf("Dragon flew away!\n");
    printf("Количество предложений до %d и количество предложений после %d\n", n, m);
}


void fill_punctuation(char* text, char* punctuation, int text_size) {
    int j = 0;
    for (int i=0; i<text_size-1; i++) {
        if (text[i] == '.' || text[i] == ';' || text[i] == '?') {
            punctuation[j] = text[i];
            j++;
        }
    }
}

void split_text(char* text, char** sentences) {
    char* sep = ".;?";
    char* substr;
    
    substr = strtok(text, sep);
    int i = 0;
    while (substr != NULL) {
        sentences[i] = substr;
        i++;
        substr = strtok(NULL, sep);
    }
}

char* get_text(int* text_size, int* n) {
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
            (*n)++;
        }
        ch = getchar();
    }
    return text;
}
