//Lab6 #9. Латинским квадратом порядка n называется квадратная таблица размера n*n,
//каждая строка и каждый столбец которой содержит числа 1,2,…,n.
//Дана целочисленная квадратная матрица; определить, является ли она латинским квадратом.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
int matrix[N][N]; /*= { // Для проверки работы функции, которая определяет, является ли квадратная матрица латинским квадратом.
        {0, 4, 3, 2, 1},
        {2, 1, 0, 4, 3},
        {4, 3, 2, 1, 0},
        {1, 0, 4, 3, 2},
        {3, 2, 1, 0, 4}
}; */
void rand_init();
void output();
short check();

int main() {
    while(1) { // Бесконечный цикл, завершается после нахождения латинского квадрата в случайной квадратной матрице.
        //rand_init();
        output();
        printf("\n");
        if(check() == 1) {
            printf("Correct matrix");
            break;
        }
    }
    return 0;
}

void rand_init() {
    srand( time(NULL));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            matrix[i][j] = rand() % N + 1;
        }
    }
}

void output() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

short check() {
    int count = 0, count2 = 0;
    for(int i = 0; i < N; i++) {                // Цикл для прохода по всем строкам и столцам
        for (int j = 0; j <= N; j++) {          // Цикл для проверки каждого числа из множества 1, 2, N.
            for (int k = 0; k < N; k++) {       // Цикл проверяющий строки и столбцы на кол-во элементов множества
                if(matrix[i][k] == j) count++;
                if(matrix[k][i] == j) count2++; // Если кол-во одного из элементов строки или столбца больше 1, то
            }                                   // функция check() возвращает 0(false)
            if(count > 1) return 0;             // По умолчанию функция возвращает 1(true)
            if(count2 > 1) return 0;
            count = 0;
            count2 = 0;
        }
    }
    return 1;
}