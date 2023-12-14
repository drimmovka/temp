#include "sorts.h"

#include <stdlib.h>

#include "util/vector.h"
#include "words.h"

int compare_avglen(const void* _word1, const void* _word2) {
    return ((*(String**)_word1)->avglen > (*(String**)_word2)->avglen) - ((*(String**)_word1)->avglen < (*(String**)_word2)->avglen);
}

int compare_len(const void* _str1, const void* _str2) {
    return ((*(String**)_str1)->len < (*(String**)_str2)->len) - ((*(String**)_str1)->len > (*(String**)_str2)->len);
}

// test error
int compare_word_count(const void* _str1, const void* _str2) {
    if ((*(String**)_str1)->words == (*(String**)_str2)->words)
        return ((*(String**)_str1)->len > (*(String**)_str2)->len) - ((*(String**)_str1)->len < (*(String**)_str2)->len);
    else
        return ((*(String**)_str1)->words > (*(String**)_str2)->words) - ((*(String**)_str1)->words < (*(String**)_str2)->words);
}

void sort_avgwordlen(Text** _text) {
    for (unsigned int i = 0; i < (*_text)->len; i++) {
        Words* _tmp = *from_string_with_sep(&(*_text)->body[i]);
        (*_text)->body[i]->avglen = avg_len(_tmp);
        free_words(&_tmp);
    }

    qsort((*_text)->body, (*_text)->len, sizeof(String*), compare_avglen);
}

void sort_text_by_woeds(Text** _text) {
    qsort((*_text)->body, (*_text)->len, sizeof(String*), compare_word_count);
}

void sort_text_all(Text** _text) {
    for (unsigned int i = 0; i < (*_text)->len; i++)
        if ((*_text)->body[i]->len != 0)
            sort_words(&(*_text)->body[i]);
}

void sort_words(String** _str) {
    Words* _words = *from_string_with_sep(_str);
    qsort(_words->words->body, _words->words->len, sizeof(String*), compare_len);
    free(*_str);
    *_str = *to_string(&_words);
    free_words(&_words);
}
