#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

static const size_t ROWS = 8;
static const size_t COLS = 12;
static const size_t LINE_LEN = 97;

static inline void print_matrix_ptr(int64_t *matrix, size_t y_size, size_t x_size) {
    for (size_t j = 0; j < LINE_LEN; ++j) putchar('-');
    puts("");

    for (size_t i = 0; i < y_size; ++i) {
        if (i == y_size / 2) { 
            for (size_t j = 0; j < LINE_LEN; ++j) putchar('-');
            puts("");
        }
        printf("| ");
        for (size_t j = 0; j < x_size; ++j) {
            printf("%ld\t", *(matrix + i * x_size + j));
        }
        printf("|");
        puts("");
    }

    for (size_t j = 0; j < LINE_LEN; ++j) putchar('-');
    puts("");
}

static void filter_lower_task(void) {
    int64_t matrix[ROWS][COLS];
    int64_t results[ROWS * COLS];
    size_t count = 0;
    static const int64_t threshold = 500;

    for (size_t i = 0; i < ROWS; ++i) {
        for (size_t j = 0; j < COLS; ++j) {
            matrix[i][j] = rand() % 2000 - 1000;
        }
    }

    printf("Исходная матрица (%zu x %zu):\n", ROWS, COLS);
    print_matrix_ptr(&matrix[0][0], ROWS, COLS);

    for (size_t i = ROWS / 2; i < ROWS; ++i) {
        for (size_t j = 0; j < COLS; ++j) {
            if (matrix[i][j] < threshold) {
                results[count++] = matrix[i][j];
            }
        }
    }

    printf("\nНайдено элементов в нижней половине меньше %ld: %zu\n", threshold, count);
    for (size_t i = 0; i < count; ++i) {
        printf("%ld ", results[i]);
        if ((i + 1) % 10 == 0) puts(""); 
    }
    puts("\n");
}

int main(void) {
    srand((unsigned)time(NULL));

    printf("<<< ----- ОБРАБОТКА МАТРИЦЫ (НИЖНЯЯ ЧАСТЬ) ----- >>> \n\n");
    filter_lower_task();

    return EXIT_SUCCESS;
}