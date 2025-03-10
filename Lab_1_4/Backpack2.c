#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 16

int Backpack(int A[], int B[], int max, int size)
{
	int var_count = 1 << size;
	int max_weight_index = 0;
	int max_weight = 0;
	for (int i = 0; i < var_count; i++)
	{
		int S = 0;
		for (int j = 0; j < size; j++)
		{
			GetBit(i, j) == 1 ? S += A[j] : S;
		}
		(S <= max && S > max_weight) ? max_weight_index = i, max_weight = S : max_weight;
		printf_s("#%d S = %d\n", i, S);
	}

	printf_s("�� �������� ���������� ��� � ������ ����� �������� ��������: ");
	for (int i = 0; i < size; i++)
	{
		GetBit(max_weight_index, i) == 1 ? printf_s("#%d � ����� %d; ", i + 1, A[i]) : i;
	}
	puts("");
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

	int max, size;
	puts("������� ���-�� ���������:");
	scanf_s("%d", &size);
	int A[MAX_SIZE];
	int B[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		printf_s("������� �%d:\n��� = ", i + 1);
		scanf_s("%d", &A[i]);
		printf_s("���� = ");
		scanf_s("%d", &B[i]);
	}
	puts("������� ������������ ��� �������:");
	scanf_s("%d", &max);
	Backpack(A, B, max, size);

	system("pause");
}