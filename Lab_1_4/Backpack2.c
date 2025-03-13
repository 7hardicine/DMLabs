#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <Windows.h>
#define MAX_SIZE 16

int Backpack(int A[], int B[], int max, int size)
{
	int S1 = 0, S2 = 0;
	int var_count = 1 << size;
	int max_weight_index = 0;
	int max_weight = 0;
	int max_count = 0;
	for (int i = 0; i < var_count; i++)
	{
		S1 = 0;
		S2 = 0;
		for (int j = 0; j < size; j++)
		{
			GetBit(i, j) == 1 ? S1 += A[j], S2 += B[j] : S1;
		}
		(S1 <= max && S1 > max_weight && S2 > max_count) ? max_weight_index = i, max_weight = S1, max_count = S2 : max_weight;
		printf_s("#%d S1 = %d S2 = %d \n", i, S1, S2);
	}

	printf_s("Не превысив допустимый вес в рюкзак можно впихнуть предметы: ");
	for (int i = 0; i < size; i++)
	{
		GetBit(max_weight_index, i) == 1 ? printf_s("#%d с весом %d и стоимостью %d ", i + 1, A[i], B[i]) :
			i;
	}
	puts("");
	printf_s("Конечная стоимость и вес будут: %d деняк, %d кг\n", S2, S1);
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
	puts("Введите кол-во предметов:");
	scanf_s("%d", &size);
	int A[MAX_SIZE];
	int B[MAX_SIZE];
	for (int i = 0; i < size; i++)
	{
		printf_s("Предмет №%d:\nВес = ", i + 1);
		scanf_s("%d", &A[i]);
		printf_s("Цена = ");
		scanf_s("%d", &B[i]);
	}
	puts("Введите максимальный вес рюкзака:");
	scanf_s("%d", &max);
	Backpack(A, B, max, size);

	system("pause");
}