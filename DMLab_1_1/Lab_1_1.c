#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

int MoveBitAndReplace(int a)
{
	int k = input_uint("������� �� ������� �������� ������ �������� �����:");
	int number = a << k;
	bool mask = 1;
	for (int i = 0; i < k; i++)
	{
		number = number | (mask << i);
	}
	return number;
}

int input_uint(char query[])
{
	printf("%s ", query);
	int number;
	while (scanf_s("%d", &number) == 0 || number <= 0)
	{
		while (getchar() != '\n');
		puts("�� ����� ���-�� �� ���, ��������� �������...");
	}
	return number;
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a = input_uint("������� ����� a:");
	int a_moved = MoveBitAndReplace(a);
	printf_s("a = %d\n", a_moved);

	system("pause");
}