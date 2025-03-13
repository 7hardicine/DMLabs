#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 32

void toBinary(int a)
{
	int Result[MAX_SIZE];
	int size = 0;
	while (a != 0)
	{
		Result[size] = a % 2;
		a = a / 2;
		size++;
	}
	for (int i = size - 1; i >= 0; i--)
	{
		printf_s("%d", Result[i]);
	}
}

struct test
{
	int a;
	int waiting_final;
};

void Testing()
{
	struct test tests[3] =
	{ {7, 111}, {2, 10}, {10, 1010}};

	for (int i = 0; i < 3; i++)
	{		
		printf_s("a = %d, waiting result = %d, result = ", \
			tests[i].a, tests[i].waiting_final);
		toBinary(tests[i].a);  
		puts("");
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