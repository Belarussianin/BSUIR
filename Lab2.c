#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//050504 Кашевский Арсений
//9. Рассортировать элементы главной диагонали матрицы 10x10 по возрастанию.
#define SIZE 15 
//Не ставить больше 155 для правильного вывода матрицы в консоли
int matrix[SIZE][SIZE];
int diag[SIZE];
void init_matrix();
void output_matrix();
void sort_matrix();
void sort(int*);

int main() {
	init_matrix();
	sort_matrix();
	output_matrix();
	return 0;
}

void init_matrix() {
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			matrix[i][j] = rand() % 10;
		}
	}
}

void sort(int* diag) {
	// Для всех элементов
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = (SIZE - 1); j > i; j--) // для всех элементов после i-ого
		{
			if (diag[j - 1] > diag[j]) // если текущий элемент меньше предыдущего
			{
				int temp = diag[j - 1]; // меняем их местами
				diag[j - 1] = diag[j];
				diag[j] = temp;
			}
		}
	}
}

void sort_matrix() {
	for (int i = 0; i < SIZE; i++) {
		diag[i] = matrix[i][i];
	}
	sort(diag);
	for (int i = 0; i < SIZE; i++) {
		matrix[i][i] = diag[i];
	}
}

void output_matrix() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Для разноцветного вывода главной диагонали в консоли.
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (i == j) {
				SetConsoleTextAttribute(hConsole, rand() % 14 + 2); //  (меняет цвет вывода консоли)
			}
			printf(" %d", matrix[i][j]);
			SetConsoleTextAttribute(hConsole, 15); //  (меняет цвет вывода консоли)
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, 15); //  (меняет цвет вывода консоли)
}
