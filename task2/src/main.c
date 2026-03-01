
#include <llibs.h>
#include <main.h>

// temporary
#include <stdio.h>

lexit lmain(li32 argc, lstr* argv) {
	(void)argc; (void)argv; // useless;

	li64 d1 = 0, d2 = 0, step = 0;

	printf("Введите верхнее и нижнее значение диапазона (через пробел): ");
	scanf("%lld %lld", &d1, &d2);

	printf("Введите шаг(гр): ");
	scanf("%lld", &step);

	if(d1 == d2 || step > d2 - d1) {
		fprintf(stderr, "Ошибка! Указан неверно шаг или диапазон.");
		return LEXIT_SUCCESS;
	}


	if (d2 < d1) {
		fprintf(stderr, "Ошибка! Правый диапазон меньше левого.");
		return LEXIT_SUCCESS;
	}


	printf("Вес(гр)\tСтоимость(руб)\n");
	for (; d1 <= d2; d1 += step) {
		printf("%lld\t%lld\n", d1, d2);
	}

	return LEXIT_SUCCESS;
}
