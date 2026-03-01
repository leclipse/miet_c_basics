#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>
#include <string.h>


static bool is_stopword(const char* word) {
    assert(word != NULL);
    if (word[0] == '!' || word[0] == '.')
        return true;
    return false;
}

#include <ctype.h>

static char* getword_n(char* text, size_t len) {
    assert(text != NULL && len != 0);

    size_t cur_len = 0;
    char* word_begin = NULL;
    for (int i = 0; ; i++) {
        if (isalpha(text[i])) {
            if (cur_len == 0) word_begin = &text[i];
            cur_len++;
        } else {
            if (cur_len == len) {
                return word_begin;
            }
            if (text[i] == '\0') break;
            cur_len = 0;
        }
    }
    return NULL;
}


int main(void) {
    const size_t num_of_lines = 20, num_of_chars_in_line = 100;
    char input_buffer[20][100];
    size_t line_i = 0;

    for (size_t i = 0; i < num_of_lines; ++i) {
        memset(input_buffer[i], '\0', num_of_chars_in_line);
    }

    size_t target_len = 0;
    printf("Введите длину искомого слова: ");
    if (scanf("%zu", &target_len) != 1) return EXIT_FAILURE;

    puts("Внимание! Количество символов в каждой строке не превышает 100.");
    do {
        printf("> ");
        scanf(" %99[^\n]", input_buffer[line_i]);
    } while(!is_stopword(input_buffer[line_i]) && ++line_i < num_of_lines);

    for (size_t i = 0; i < line_i; ++i) {
        size_t num_of_blanks = 0;
        char* last_blank_ptr = input_buffer[i];
        while (last_blank_ptr = strchr(last_blank_ptr, ' ')) {
            num_of_blanks++; 
            last_blank_ptr++;
        }

        printf("Строка %zu: пробелов = %zu, слова длины %zu: ", i, num_of_blanks, target_len);

        char* current_ptr = input_buffer[i];
        char* found_word;
        bool is_found = false;

        while (found_word = getword_n(current_ptr, target_len)) {
            printf("[%.*s] ", (int)target_len, found_word);
            current_ptr = found_word + target_len;
            is_found = true;
        }

        if (!is_found) {
            printf("не найдены");
        }
        printf("\n");
    }

    return EXIT_SUCCESS;
}
