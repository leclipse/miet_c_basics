#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>

#define LINE_LEN 65

static inline void print_matrix_ptr(int64_t *matrix, size_t x_size, size_t y_size) {
    for (size_t j = 0; j < LINE_LEN; ++j) {
        putchar('-');
    }
    puts("");
    for (size_t i = 0; i < y_size; ++i) {
        if (i == 4) {
            for (size_t j = 0; j < LINE_LEN; ++j) {
                putchar('-');
            }
            puts("");
        }
        printf("| ");
        for (size_t j = 0; j < x_size; ++j) {
            printf("%ld\t", *(matrix + i * x_size + j));
        }
        printf("|");
        puts("");
    }
    for (size_t j = 0; j < LINE_LEN; ++j) {
        putchar('-');
    }
}

static inline void print_matrix(int64_t matrix[8][12]) {
    for (size_t j = 0; j < LINE_LEN; ++j) {
        putchar('-');
    }
    puts("");
    for (size_t i = 0; i < 8; ++i) {
        if (i == 4) {
            for (size_t j = 0; j < LINE_LEN; ++j) {
                putchar('-');
            }
            puts("");
        }
        printf("| ");
        for (size_t j = 0; j < 12; ++j) {
            printf("%ld\t", matrix[i][j]);
        }
        printf("|");
        puts("");
    }
    for (size_t j = 0; j < LINE_LEN; ++j) {
        putchar('-');
    }
}

static void task1(void) {
    int64_t matrix[8][12];
    
    for (size_t i = 0; i < 8; ++i) {
        for (size_t j = 0; j < 12; ++j) {
            matrix[i][j] = rand() % 1200 - 200; 
        }
    }

    printf("Исходная, сгенерированная матрица: \n\n");
    
    print_matrix_ptr(&matrix[0][0], 8, 12);
    puts("");

    int64_t half_max_neg = INT64_MIN;
    for (size_t i = 4; i < 8; ++i) {
        for (size_t j = 0; j < 12; ++j) {
            if (matrix[i][j] < 0 && matrix[i][j] > half_max_neg)
                half_max_neg = matrix[i][j];
        }
    }

    printf("\nМаксимальный отрицательный элемент из нижней половины: %ld\n\n", half_max_neg);
}

void task2(void) {
        int64_t matrix[12][16];

    for (size_t i = 0; i < 12; ++i) {
        for (size_t j = 0; j < 16; ++j) {
            matrix[i][j] = rand() % 1200 - 200; 
        }
    }
    
    for (size_t i = 0; i < 12; ++i) {
        for (size_t j = 0; j < 16; ++j) {
            printf("%ld\t", matrix[i][j]);
        }
        puts("");
    }

    printf("\n\nCумма элементов каждого столбца: \n\n");

    for (size_t i = 0; i < 16; ++i) {
        int64_t sum = 0;
        for (size_t j = 0; j < 12; ++j) {
            sum += matrix[j][i];
        }
        printf("%ld\t", sum);
    }
}

int main(void) {

    srand(time(NULL)); 

    printf("<<< ----- ЗАДАЧА 1 ----- >>> \n");
    task1();
    printf("<<< ----- ЗАДАЧА 2 ----- >>> \n");
    task2();


    return EXIT_SUCCESS;
}