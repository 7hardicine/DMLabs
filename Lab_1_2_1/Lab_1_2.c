#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>

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

int input_uint(char query[])
{
	printf("%s ", query);
	int number;
	while (scanf_s("%d", &number) == 0 || number < 0)
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
	int i = input_uint("������� ����� ����, ������� ������ �������� �� ���������������:");
	a = toggleBit(a, i);
	printf_s("a = %d\n", a);

	system("pause");
}