#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 10

void init();
void output(int*);
int mas[SIZE];
int mas2[SIZE];

int main() {
    int j = 0;
    init(SIZE);   // Fill array with nums from -5 to 5
    output(mas);  // Output of array mas
    for (int i = 0; i < SIZE; i++) { // Fill mas2 with -nums
        if(mas[i] < 0) {
            mas2[j] = mas[i];
            j++;
        }
    }
    for (int i = 0; i < SIZE; i++) { // Fill mas2 with zero's
        if(mas[i] == 0) {
            mas2[j] = mas[i];
            j++;
        }
    }
    for (int i = 0; i < SIZE; i++) { // Fill mas2 with +nums
        if(mas[i] > 0) {
            mas2[j] = mas[i];
            j++;
        }
    }
    output(mas2); // Output of array mas2
    return 0;
}

void init() {
    srand( time(NULL) );
    for (int i = 0; i < SIZE; i++) {
        mas[i] = rand() % 10 - 5;
    }
}

void output(int* mas) {
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", mas[i]);
    }
    printf("\n");
}
