#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 16

int Backpack(int A[], int max, int size)
{
	int mask = 0;
	int size_ = 1 << size;
	for (int i = 0; i < size_; i++)
	{
		int S = 0;
		int sdvig = 1;
		for (int j = 0; j < size; j++)
		{
			int temp = mask & sdvig;
			temp >= 1 ? S += A[j] : S;
			sdvig = sdvig << 1;
		}
		printf_s("S = %d mask = %d\n", S, mask);
		mask += 1;
	}
}

int GetBit()
{

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
	for (int i = 0; i < size; i++)
	{
		printf_s("������� �%d = ", i + 1);
		scanf_s("%d", &A[i]);
	}
	puts("������� ������������ ��� �������:");
	scanf_s("%d", &max);
	Backpack(A, max, size);

	system("pause");
}