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
	{ {1, 5, 0, 63}, {5, 1, 0, 11}, {3, 2, 0, 15} };

	for (int i = 0; i < 3; i++)
	{
		tests[i].final = MoveBitAndReplace(tests[i].a, tests[i].k);
		printf_s("a = %d, k = %d, moved = %d, waiting result = %d\n", \
			tests[i].a, tests[i].k, tests[i].final, tests[i].waiting_final);
	}
}

int MoveBitAndReplace(int a, int k)
{
	int number = a << k;
	bool mask = 1;
	for (int i = 0; i < k; i++)
	{
		number = number | (mask << i);
	}
	return number;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Testing();
	
	system("pause");
}