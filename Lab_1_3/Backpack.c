#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 16

int Backpack(int A[], int max, int size)
{
	int var_count = 1 << size;
	int max_weight_index = 0;
	int max_weight = 0;
	for (int i = 0; i < var_count; i++)
	{
		int S = 0;
		int sdvig = 1;
		for (int j = 0; j < size; j++)
		{
			int temp = i & sdvig;
			temp >= 1 ? S += A[j] : S;
			sdvig = sdvig << 1;
		}
		if (S <= max && S > max_weight)
		{
			max_weight_index = i;
			max_weight = S;
		}
		printf_s("#%d S = %d\n", i, S);
	}

	printf_s("Не превысив допустимый вес в рюкзак можно впихнуть предметы: ");
	int sdvig = 1;
	for (int i = 0; i < size; i++)
	{
		int temp = max_weight & sdvig;
		temp >= 1 ? printf_s("#%d с весом %d ", i, A[i]) : temp;
		sdvig = sdvig << 1;
	}
	puts("");
}

void main()
{
	setlocale(LC_ALL, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int max, size;
	puts("Введите кол-во предметов:");
	scanf_s("%d", &size);
	int A[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		printf_s("Предмет №%d = ", i + 1);
		scanf_s("%d", &A[i]);
	}
	puts("Введите максимальный вес рюкзака:");
	scanf_s("%d", &max);
	Backpack(A, max, size);

	system("pause");
}