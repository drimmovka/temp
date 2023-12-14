#include "exec_command.h"

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>

#include "regex_task.h"
#include "sorts.h"
#include "util/config.h"
#include "util/error.h"
#include "util/io.h"
#include "util/vector.h"

#define REGEX_MAX 256

void print_help();

void exec_command() {
    setlocale(LC_ALL, LOCALE);
    wchar_t* regex;
    static Text* text;
    int command;

    if (!wscanf(L"%d", &command))
        ERROR("Command should be a number", 2);
    getwchar();  // skip newline

    if (command == 5) {
        print_help();
        return;
    }
    text = *new_text(MIN_VECTOR_SIZE);
    switch (command) {
        case 0:
            read_text(&text);
            break;
        case 1:
            regex = calloc(REGEX_MAX, sizeof(wchar_t));
            if (regex == NULL)
                ERROR("Failed to allocate regex string", 1);
            wscanf(L"%ls ", regex);
            read_text(&text);
            regex_task(&text, regex);
            free(regex);
            break;
        case 2:
            read_text(&text);
            sort_avgwordlen(&text);
            break;
        case 3:
            read_text(&text);
            sort_text_all(&text);
            break;
        case 4:
            read_text(&text);
            for (unsigned int i = 0; i < text->len; i++)
                if (text->body[i]->words < 2 || text->body[i]->words > 5)
                    clear(&text->body[i]);
            break;
        case 9:
            read_text(&text);
            sort_text_by_woeds(&text);
            break;
        default:
            ERROR("Wrong command", 2);
            break;
    }
    output_text(&text);
    free_text(&text);
}

void print_help() {
    puts(
        "commands:\n"
        " - 0  | remove duplicates\n"
        " - 1  | filter by regex\n"
        " - 2  | sort by avg word len\n"
        " - 3  | sort words by len (descending)\n"
        " - 4  | remove sentences with less than 2\n"
        "      | or more than 5 words\n"
        " - 5  | this message\n");
}
