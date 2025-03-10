#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

int OppositeBit(int a, int i)
{
	int x = 1 << i;
	GetBit(a, i) == 1 ? (a = a & (!(x))) : (a = a | x);
	return a;
}

int GetBit(int num, int i)
{
	int bit = 0;
	(num & (1 << i)) > 0 ? bit = 1 : bit;
	return bit;
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

	int a = input_uint("Введите число a:");
	int i = input_uint("Введите номер бита, который хотите заменить на противоположный:");
	a = OppositeBit(a, i);
	printf_s("a = %d\n", a);

	system("pause");
}