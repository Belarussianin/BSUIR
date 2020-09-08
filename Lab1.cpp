#include <stdio.h>
#include <stdlib.h>
#include <clocale>
//050504 Кашевский Арсений
//9. Рассортировать элементы главной диагонали матрицы 10x10 по возрастанию.
//Лютая жесть, зато работает.
const int size = 10;
int matrix[size][size];
int diag[size];
void init_matrix();
void output_matrix();
void sort_matrix();
void sort(int*); //https://prog-cpp.ru/sort-bubble

int main() {
	setlocale(LC_ALL, "Russian");
	init_matrix();
	sort_matrix();
	output_matrix();
	
	return 0;
}

void init_matrix() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			matrix[i][j] = rand() % 10;
		}
	} 
}

void sort(int* diag) {
	// Для всех элементов
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // для всех элементов после i-ого
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
	for (int i = 0; i < size; i++) {
		diag[i] = matrix[i][i];
	}
	sort(diag);
	for (int i = 0; i < size; i++) {
		matrix[i][i] = diag[i];
	}
}

void output_matrix() {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			printf(" %d", matrix[i][j]);
		}
		printf("\n");
	}
}
