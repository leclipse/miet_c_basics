#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

// x= a+b/с+d   
int main(void) {
    
    int64_t a = 0, b = 0, c = 0, d = 0;
    
    printf("Введите через пробел числа a b c d: ");
    scanf("%ld %ld %ld %ld", &a, &b, &c, &d);

    if (c + d == 0) {
        printf("Ошибка! Деление на 0.");
        return EXIT_FAILURE;
    }

    double answer = (double)(a + b) / (double)(c + d);
    printf("Результат исчисления a+b/с+d = %lf", answer);
    return EXIT_SUCCESS;
}