#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

int Task(int a)
{
	int b;
	int mask = 1;
	int even = 0;
	int odd = 0;
	for (int i = 0; i < sizeof(a); i += 2)
	{
		even = even | (mask << i);
		printf_s("%d\n", i);
	}
	b = a & even;
	printf_s("%d\n", even);
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	puts("¬ведите число a:");
	int a;
	scanf_s("%d", &a);
	Task(a);

	system("pause");
}