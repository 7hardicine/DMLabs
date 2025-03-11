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

int input_uint(char query[])
{
	printf("%s ", query);
	int number;
	while (scanf_s("%d", &number) == 0 || number < 0)
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

	int b1 = input_uint("Введите число b1:");
	int b2 = input_uint("Введите число b2:");
	int result = xorBitSet(b1, b2);
	printf_s("a = %d\n", result);

	system("pause");
}