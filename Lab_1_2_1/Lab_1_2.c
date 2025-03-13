#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

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
	{ {15, 2, 0, 11}, {6, 0, 0, 7}, {10, 3, 0, 2} };

	for (int i = 0; i < 3; i++)
	{
		tests[i].final = toggleBit(tests[i].a, tests[i].k);
		printf_s("a = %d, k = %d, result = %d, waiting result = %d\n", \
			tests[i].a, tests[i].k, tests[i].final, tests[i].waiting_final);
	}
}

extern int toggleBit(int bits, int bitNumber)
{
	GetBit(bits, bitNumber) == 1 ? (bits = bits & (~(1 << bitNumber))) : (bits = bits | (1 << bitNumber));
	return bits;
}

int GetBit(int num, int i)
{
	int bit = 0;
	(num & (1 << i)) > 0 ? bit = 1 : bit;
	return bit;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Testing();

	system("pause");
}