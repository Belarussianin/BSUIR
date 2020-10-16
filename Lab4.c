#include <stdlib.h>
#include <stdio.h>

void bubble(int*, int);
int* init(int*);
void output(int*);

int main() {
	int mas[10]; // Obiavliaem massiv
	init(mas);   // Zapolniaem massiv chislami ot -10 do 9
	bubble(mas, 10); // Sortiruem metodom bubbl'a
	output(mas); // Vivodim massiv
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

int* init(int* mas) {
	srand( time(NULL) );
	for (int i = 0; i < sizeof(mas); i++) {
		mas[i] = rand() % 20 - 10;
	}
	return mas;
}

void output(int* mas) {
	for (int i = 0; i < sizeof(mas); i++) {
		printf("%d ", mas[i]);
	}
}
