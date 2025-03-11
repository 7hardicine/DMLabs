#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#include <math.h>

// ����� ������� �����, ���� �������� ����� ����� ������ �� 1

void MoveBitAndSquare(int a)
{
	int mask = 1 << (sizeof(a) - 1);
	while ((a & mask) == 0)
	{
		mask = mask >> 1;
	}
	printf_s("%d\n", (mask << 1)*(mask << 1));
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
	MoveBitAndSquare(a);

	system("pause");
}