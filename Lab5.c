/*#include <stdlib.h>
#include <stdio.h>

int mas[5][6];   // Obiavliaem massiv
void init();
void output();

int main() {
	init();      // Zapolniaem massiv
	output();    // Vivodim massiv i srednee vseh stolbcov
	return 0;
}

void init() {
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			mas[i][j] = rand() % 19 - 9;
		}
	}
}

void output() {
	int sum = 0;
	int count = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			printf(" %d\t", mas[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < 5; i++) {
			if (mas[i][j] > 0) {
				sum += mas[i][j];
				count++;
			}
		}
		if (count != 0) {
			printf("srednee stolbca %d: %.3f\n", j + 1, (float)sum / count);
		}
		else {
			printf("srednee stolbca %d: %s\n", j + 1, "net polozitelnih");
		}
		sum = 0;
		count = 0;
	}
}*/