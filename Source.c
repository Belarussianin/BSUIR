// ��� ���������� ������ a1, an. ����� � ���������� ����� ��������, ������������ �������� � ���������� �����������.
// Lab4 �7 ����
/*#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

void init(int n);

int* mas;

int main() {
	system("chcp 1251");
	int n, max = 0, mult = 0, cor = 0;
	while (1) {
		printf("������� ������ �������: ");
		scanf_s("%d", &n);
		if (n > 1) { break; }
		system("cls");
	}
	init(n);
	for (int i = 1; i < n; i++) {
		mult = mas[i] * mas[i - 1];
		if (mult > max) {
			max = mult;
			cor = i;
		}
	}
	printf("����� �������� ������������ �������� � ���������� �����������: mas[%d] = %d,\n������������(max) %d = mas[%d] = %d * mas[%d] = %d\n", cor, mas[cor], max, cor, mas[cor], cor - 1, mas[cor - 1]);
	free(mas);
	return 0;
}

void init(int n) {
	int i, elem;
	mas = (int*)malloc(n * sizeof(int));
	srand(time(NULL));
	for (i = 0; i < n; i++) {
		printf("mas[%d] = ", i);
		scanf("%d", &mas[i]);
	}
}
*/

/*
//���� ��� ������������� ������� � � �. ������� �� ������ ��� ���� ��������, ��� ������� �[i] * �[i] > 10. 
// ���������� ����� ��� � ����� ���� ������������.
//Lab...
#include <stdio.h>
#include <stdib.h>
#define SIZE 15

int a[SIZE], b[SIZE];
int summ = 0, count = 0;

int main() {
	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		a[i] = rand() % 25 - 10;
		b[i] = rand() % 5;
	}
	for (int i = 0; i < SIZE; i++) {
		if (a[i] * b[i] > 10) {
			summ += a[i] * b[i];
			count++;
			printf("%d: Index: [%d] %d * %d = %d\n", count, i, a[i], b[i], a[i] * b[i]);
		}
	}
	printf("Count of pairs: %d\nSumm of a[i] * b[i] = %d", count, summ);
	return 0;
}
*/
/*
//�������� ���������, ������� � ������ ����� A(N, M) ������� ��� ��������, ������ �����, ���������� � ����������.
//���������� ����� ����� ���������.
//Lab4 #15 Nastya
//https://stackoverflow.com/questions/16883037/remove-secure-warnings-crt-secure-no-warnings-from-projects-by-default-in-vis
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int main() {
	int num = 0, count = 0;
	int matrix[SIZE][SIZE];

	srand(time(NULL));
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = rand() % 90 + 10;
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}

	printf("Enter number from 10 to 100: ");
	while (!scanf("%d", &num));

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (matrix[i][j] == num) { count++; }
		}
	}

	printf("Count of equal numbers in matrix: %d", count);
	return 0;
}
*/
/*
//�������������� ���������� ������ �� ����������� (��������) ��������� (����� ��������).
//Lab5 #9 Nastya
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void bubble(int*, int);

int main() {
	int mas[SIZE];

	srand(time(NULL));
	printf("Array:\n");
	for (int i = 0; i < SIZE; i++) {
		mas[i] = rand() % 90 + 10;
		printf("%d ", mas[i]);
	}
	printf("\nSorted array:\n");

	bubble(mas, SIZE);

	for (int i = 0; i < SIZE; i++) {
		printf("%d ", mas[i]);
	}
	return 0;
}

void bubble(int* mas, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = (size - 1); j > i; j--) {
			if (mas[j - 1] > mas[j]) {
				int temp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = temp;
			}
		}
	}
}
*/
//������������� ������ ������� � �������� n*m �� �������� 
//Laba Yarik'a
#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 15

void bubble(int*, int);
void reverse(int*, int);

int main() {
	int mas[N][M];

	srand(time(NULL));
	printf("Array:\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			mas[i][j] = rand() % 100;
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
	printf("\nSorted array:\n");

	for (int i = 0; i < N; i++) {
		bubble(mas[i], M);
		reverse(mas[i], M);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			printf("%d ", mas[i][j]);
		}
		printf("\n");
	}
	return 0;
}

void bubble(int* mas, int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = (size - 1); j > i; j--) {
			if (mas[j - 1] > mas[j]) {
				int temp = mas[j - 1];
				mas[j - 1] = mas[j];
				mas[j] = temp;
			}
		}
	}
}

void reverse(int* mas, int size) {
	int i1 = 0, i2 = size - 1, temp;
	for (; i1 < i2; i1++, i2--)             // ���� ���� i1 < i2, �.�. ���� ������� (����� � ������)
	{                                       // �� ��������
		temp = mas[i1];                     // ���������� �������� �������� �� ������� i1 � kk
		mas[i1] = mas[i2];                  // ������� � ������� � �������� i1 �������� �������� � �������� i2 
		mas[i2] = temp;                     // ������������ �������� �� kk � ������� � �������� i2
	}
}