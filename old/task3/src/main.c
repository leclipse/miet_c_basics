#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

int comp(const void *a, const void *b) {
    return (*(double *)a - *(double *)b);
}

double frand(double fmin, double fmax) {
    double f = (double)rand() / RAND_MAX;
    return fmin + f * (fmax - fmin);
}

int main(void) {

    const size_t array_size = 10;
    const double array_min = -1000, array_max = 1000;
    double array[array_size];

    srand(time(NULL)); 

    printf("Исходный массив сгенерированный случайно (srand(time(NULL))):\n");
    for (size_t i = 0; i < array_size; ++i) {
        array[i] = frand(array_min, array_max);
        printf("%.2lf ", array[i]);
    }

    qsort(array, array_size, sizeof(array[0]), comp);

    printf("\n\nОтсортированный массив:\n");
    for (size_t i = 0; i < array_size; ++i) {
        printf("%.2lf ", array[i]);
    }

    printf("\n\nВведите число, которое в дальнейшем будет вставлено в массив: ");
    double user_num = 0.0;
    scanf("%lf", &user_num);

    
    printf("\n\nРезультат вставки:\n");
    
    if (user_num <= array[0])
        printf("%lf", user_num);
    printf("%.2lf ", array[0]);
    for (size_t i = 1; i < array_size-1; ++i) {
        static bool num_inserted = false;
        printf("%.2lf ", array[i]);
        
        if (user_num >= array[i-1] && user_num <= array[i+1] && !num_inserted) {
            printf("%.2lf ", user_num);
            num_inserted = true;
        }
    }
    printf("%.2lf ", array[array_size-1]);
    if (user_num > array[array_size-1] && user_num > array[0])
         printf("%lf", user_num);

    return EXIT_SUCCESS;
}