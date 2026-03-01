#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <limits.h>
#include <assert.h>

int64_t* find_min(int64_t *array, size_t len) {
    assert(array != NULL);
    if (len == 0) return NULL;

    int64_t* mn_ptr = array; 
    for (size_t i = 1; i < len; ++i) {
        if (*mn_ptr > array[i]) {
            mn_ptr = array + i;
        }
    }
    return mn_ptr;
}

void process_task(int64_t *arr, size_t len) {
    int64_t* min_p = find_min(arr, len);
    if (!min_p) return;

    printf("Минимум: %ld\n", *min_p);

    int64_t* second_part = min_p + 1;
    size_t second_len = len - (min_p - arr) - 1;

    if (second_len > 0) {
        int64_t max_val = *second_part;
        for (size_t i = 1; i < second_len; ++i) {
            if (second_part[i] > max_val) 
                max_val = second_part[i];
        }
        printf("Максимум во второй половинке: %ld\n", max_val);
    } else {
        puts("Вторая половинка пуста.");
    }
}

int main(void) {
    srand((unsigned)time(NULL)); 

    const size_t n1 = 10, n2 = 12;
    int64_t A[n1], B[n2];

    for (size_t i = 0; i < n1; ++i) A[i] = rand() % 2000 - 1000;
    for (size_t i = 0; i < n2; ++i) B[i] = rand() % 2000 - 1000;

    puts("Исходный массив A:");
    for (size_t i = 0; i < n1; ++i) printf("%ld\t", A[i]);

    puts("\nИсходный массив B:");
    for (size_t i = 0; i < n2; ++i) printf("%ld\t", B[i]);

    puts("\nМассив A:");
    process_task(A, n1);
    
    puts("\nМассив B:");
    process_task(B, n2);

    return EXIT_SUCCESS;
}