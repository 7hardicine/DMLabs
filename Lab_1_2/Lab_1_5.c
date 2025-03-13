#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#include <math.h>

// Взять квадрат числа, если сдвинуть самый левый разряд на 1

int MoveBitAndSquare(int a)
{
	int mask = 1 << (sizeof(a) - 1);
	while ((a & mask) == 0)
	{
		mask = mask >> 1;
	}
	return ((mask << 1)*(mask << 1));
}

struct test
{
	int a;
	int final;
	int waiting_final;
};

void Testing()
{
	struct test tests[3] =
	{ {7, 0, 64}, {2, 0, 16}, {10, 0, 256} };

	for (int i = 0; i < 3; i++)
	{
		tests[i].final = MoveBitAndSquare(tests[i].a);
		printf_s("a = %d, result = %d, waiting result = %d\n", \
			tests[i].a, tests[i].final, tests[i].waiting_final);
	}
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Testing();

	system("pause");
}