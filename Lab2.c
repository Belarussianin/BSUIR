#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//050504 Кашевский Арсений
//9. Рассортировать элементы главной диагонали матрицы 10x10 по возрастанию.
const int size = 155; //Не ставить больше 155 для правильного вывода матрицы в консоли
int matrix[size][size];
int diag[size];
void init_matrix();
void output_matrix();
void sort_matrix();
void sort(int*); //https://prog-cpp.ru/sort-bubble

int main() {
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
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Для разноцветного вывода диагонали (д)
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (i == j) {
				SetConsoleTextAttribute(hConsole, rand() % 14 + 2); // (д)
			}
			printf(" %d", matrix[i][j]);
			SetConsoleTextAttribute(hConsole, 15); // (д)
		}
		printf("\n");
	}
	SetConsoleTextAttribute(hConsole, 15); // (д)
}
