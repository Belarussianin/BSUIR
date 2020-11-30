//Lab8 #12. В текстовом окне задан многострочный текст. Слова отделяются друг от друга пробелами.
//Каждое предложение в тексте заканчивается точкой. Выделять слова с удвоенной гласной.
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define I 5
#define J 300
char **ln_text;
void emphasizing(int, int);
int isVowel(char);
int isAlpha(unsigned char);

int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    ln_text = (char **)calloc(I, sizeof(char*));
    for (int i = 0; i < I; i++) {
        ln_text[i] = (char*)calloc(J, sizeof(char));
        //fgets(ln_text[i], J, stdin);
    }
    //printf("\n");
    ln_text[0] = "Такиим образом, аа дальнейшее развитие различных форм деятельности напрямую зависит от кластеризации усилий.";
    ln_text[1] = "И нет сомнений, что тщательные исследования конкурентов, вне зависимости от их уровня, должны быть превращены в посмешище, хотя само их существование приносит несомненную пользу обществу.";
    ln_text[2] = "Сложно сказать, почему ключевые особенности структуры проекта и по сей день остаются уделом либералов, которые жаждут быть функционально разнесены на независимые элементы.";
    ln_text[3] = "Но укрепление и развитие внутренней структуры предоставляет широкие возможности для вывода текущих активов.";
    ln_text[4] = "Также как понимание сути ресурсосберегающих технологий требует анализа первоочередных требований.";

    for (int i = 0; i < I; i++) {
        emphasizing(i, J);
        //printf("\n");
    }

    //Освобождаем память
    /*for (int i = 0; i < I; i++) {
        free(ln_text[i]);
    }*/
    free(ln_text);
    return 0;
}

void emphasizing(int index, int Columns) {
    int status = 0, count = 0;
    int words[J];
    for (int j = 0; j < J; ++j) {
        words[j] = 0;
    }

    for (int j = 0; j < Columns; j++) {
        if (ln_text[index][j] == '.') {
            words[j] = 46;
            break;
        }
        if (isAlpha(ln_text[index][j])) {
            count++;
            if (isVowel(ln_text[index][j]) && isVowel(ln_text[index][j + 1]) && ln_text[index][j] == ln_text[index][j + 1]) { //Если гласные и равны
                status = 1;
            }
        }
        else {
            if (status) {
                if ((j - count - 1) <= 0) words[0] = words[j - 1] = 1;
                else words[j - count - 1] = words[j - 1] = 1;
            }
            count = 0, status = 0;
        }
    }

    count = 0;
    int j = 0;
    if (words[0] == 1) {
        printf("%c%c", '!', (char)ln_text[index][0]);
        j++;
    }
    for (; j < Columns; j++) {
        if (count == I) break;
        if (ln_text[index][j] == '\0' || words[j] == 46) count++;
        if (words[j] == 1) {
            printf("%c%c", (char)ln_text[index][j], '!');
        }
        else {
            printf("%c", (char)ln_text[index][j]);
        }
    }
    printf("\n");
}

int isVowel(char symbol) {
    char vowels[20] = { 'а','у','о','ы','и','э','я','ю','ё','е','А','У','О','Ы','И','Э','Я','Ю','Ё','Е' }; //Ошибку Character too large for enclosing character literal type, при возникновении, игнорировать.
    for (int i = 0; i < 20; ++i) {
        if (symbol == vowels[i]) return 1;
    }
    return 0;
}

int isAlpha(unsigned char sym) { //Функция для проверки на русские и английские буквы
    if (((int)sym >= 65 && (int)sym <= 90) || ((int)sym >= 97 && (int)sym <= 122)) return 1;
    if (((int)sym >= 192 && (int)sym <= 255)) return 1;
    return 0;
}
