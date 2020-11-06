//Lab 7 #7.Даны натуральное число n и символы s1,…,sn.
//Удалить из каждой группы идущих подряд цифр, в которой более двух цифр и которой предшествует точка,
//все цифры, начиная с третьей (например, ab+0.1973-1.1 преобразуется в ab+0.10-1.1).
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

int n = 0;
char *str;
char *str2;
void enter_str();
void rand_str();
void del_num();

int main() {
    printf("Enter num of chars: ");
    scanf_s("%d", &n);
    rewind(stdin);

    str = (char*)calloc(n + 1, sizeof(char));

    //rand_str(); //"Случайная" генерация символов
    enter_str(); // Ручной ввод символов

    del_num(); // Преобразовывает str в str2 по условию
    printf("Array of chars2: ");
    puts(str2);

    free(str);
    free(str2);
    return 0;
}

void enter_str() {
    printf("Array of chars: ");
    for (int i = 0; i < n; i++) {
        str[i] = (char)getchar();
    }
    printf("\n");
}

void rand_str() {
    srand(time(NULL));
    printf("Array of chars: ");
    for (int i = 0; i < n; i++) {
        str[i] = (char)(rand() % 12 + 46);
        printf("%c", str[i]);
    }
    printf("\n");
}

void del_num() {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '.' && isdigit(str[i + 1]) && isdigit(str[i + 2])) {
            for (int j = i + 3; j < n; j++) {
                if (isdigit(str[j])) {
                    str[j] = (char)'NULL';
                    count++;
                }
                else {
                    break;
                }
            }
        }
    }
    str2 = (char*) calloc( n + 1 - count, sizeof(char));
    int i2 = 0;

    for (int i = 0; i < n; i++) {
        if (str[i] != (char)'NULL') {
            str2[i2] = str[i];
            i2++;
        }
    }
}
