#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

extern int xorBitSet(int b1, int b2)
{
	int result = (b1 & ~b2) | (~b1 & b2);
	return result;
}

struct test
{
	int a;
	int k;
	int final;
	int waiting_final;
};

void Testing()
{
	struct test tests[3] =
	{ {7, 3, 0, 4}, {2, 9, 0, 11}, {10, 3, 0, 9} };

	for (int i = 0; i < 3; i++)
	{
		tests[i].final = xorBitSet(tests[i].a, tests[i].k);
		printf_s("a = %d, k = %d, result = %d, waiting result = %d\n", \
			tests[i].a, tests[i].k, tests[i].final, tests[i].waiting_final);
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