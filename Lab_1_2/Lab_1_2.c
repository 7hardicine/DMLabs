#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#include <math.h>

// Взять квадрат числа, если сдвинуть самый левый разряд на 1

int MoveBitAndSquare(int a)
{
	bool mask = pow(2, sizeof(a));
	printf_s("%d", mask);
	for (int i = 0; i < sizeof(a) * 8; i++)
	{
		if ((mask >> i) == (bool)a)
		{
			printf("Да %d", i);
		}
	}
}

int input_uint(char query[])
{
	printf("%s ", query);
	int number;
	while (scanf_s("%d", &number) == 0 || number <= 0)
	{
		while (getchar() != '\n');
		puts("Вы ввели что-то не так, повторите попытку...");
	}
	return number;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a = input_uint("Введите число a:");
	MoveBitAndSquare(a);

	system("pause");
}