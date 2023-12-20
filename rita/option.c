#include <wchar.h>
#include <wctype.h>
#include <stdlib.h>
#include <locale.h>

#include "preprocessing.h"
#include "palindrome.h"
#include "replace_special_symbol.h"
#include "sort_latin.h"
#include "delete_cyrillic_latin.h"
#include "list_option.h"

int get_option(void) {
    int option;
    wscanf(L"%d%*c", &option);
    return option;
}

int option_exsist(int option) {
    if (option <= 5 && option >= 0) {
        return 1;
    }
    else {
        return 0;
    }
}

void running_option(int option) {
    switch (option)
    {
    case 0:
        preprocessing();
        break;
    case 1:
        palindrome();
        break;
    case 2:
        replace_special_symbol();
        break;
    case 3:
        sort_latin();
        break;
    case 4:
        delete_cyrillic_latin();
        break;
    case 5:
        list_option();
        break;
    }
}
