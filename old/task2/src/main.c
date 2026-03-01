#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

static bool check_k(int64_t k) {
    if (k > 1000 || k < 0) {
        printf("The number K is out of range. Please enter it again.");
        return false;
    }
    return true;
}

int main(void) {

    int64_t k = 0;

    do {
        scanf("%ld", &k);
    } while(!check_k(k));

    printf("K = %ld\n", k);

    int64_t in_buffer = 0, sum = 0;
    while (sum < k) {
        scanf("%ld", &in_buffer);
        sum += in_buffer;
        printf("%ld\n", sum);
    }
    return EXIT_SUCCESS;
}