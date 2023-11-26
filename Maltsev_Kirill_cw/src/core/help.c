#include <stdio.h>

void help() {
    printf("The program implements the following functions:\n");
    printf("-) (removeDuplicates): text preprocessing.\n");
    printf("0) (printText): text output after preprocessing.\n");
    printf("1) (countWords): print out each word (case-sensitive) and the number of its repetitions in the text.\n");
    printf("2) (replaceNonAlphaWithCode): replace each character that is not a letter with its code.\n");
    printf("3) (sortByLatinSymbols): sort sentences by the number of Latin letters in the sentence.\n");
    printf("4) (removeUpperAndSpecialSymbolsCase): delete all sentences that contain special characters and do not contain capital letters. Special characters include: #$^%c@\n", '%');
    printf("5) (help): output help about the functions that the program implements.\n");
}