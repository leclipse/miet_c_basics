#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

const char* stop_word = "EEENTER";

#define IS_PARAPEN1(c) ((c) == '{' || (c) == '}')
#define IS_PARAPEN2(c) ((c) == '[' || (c) == ']')
#define IS_PARAPEN3(c) ((c) == '(' || (c) == ')')

int main(void) {

    const size_t input_word_len = strlen(stop_word);
    char input_buffer = '\0';
    size_t input_i = 0;

    do  {
        input_buffer = (char)getchar();
        getchar(); // for '\n'

        if (IS_PARAPEN1(input_buffer)) {
            printf("Это фигурная скобка.\n");
        } else 
        if (IS_PARAPEN2(input_buffer)) {
            printf("Это квадратная скобка.\n");
        } else 
        if (IS_PARAPEN3(input_buffer)) {
            printf("Это круглая скобка.\n");
        } else {
            printf("Не скобка\n");
        }

        // continue if word is correct.
        if (stop_word[input_i] == input_buffer) 
            ++input_i; 
        else 
            input_i = 0;

        if (input_word_len == input_i) {
            printf("Было успешно введено стоп-слово: %s", stop_word);
            return EXIT_SUCCESS;
        }
        
    } while (1);

    return EXIT_SUCCESS;
}