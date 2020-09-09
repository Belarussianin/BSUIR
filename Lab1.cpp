#include <stdio.h>
#include <stdlib.h>
#include <clocale>
//050504 ��������� �������
//9. �������������� �������� ������� ��������� ������� 10x10 �� �����������.
//����� �����, ���� ��������.
const int size = 10;
int matrix[size][size];
int diag[size];
void init_matrix();
void output_matrix();
void sort_matrix();
void sort(int*); //https://prog-cpp.ru/sort-bubble

int main() {
	setlocale(LC_ALL, ".OCP");
	init_matrix();
	sort_matrix();
	output_matrix();
	//system("chcp 65001");
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
	// ��� ���� ���������
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
		{
			if (diag[j - 1] > diag[j]) // ���� ������� ������� ������ �����������
			{
				int temp = diag[j - 1]; // ������ �� �������
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