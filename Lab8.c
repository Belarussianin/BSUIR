//Lab8 #12. В текстовом окне задан многострочный текст. Слова отделяются друг от друга пробелами.
//Каждое предложение в тексте заканчивается точкой. Выделять слова с удвоенной гласной.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#define I 1
#define J 1300
//////////////////////////////////////////////// При запуске в Clion, файл исходного кода конвертировать в UTF-16
void emphasizing(char*, int);
int isVowel(char);

int main() {
    setlocale(LC_ALL, "RU");
    system("chcp 1251");
    char** ln_text = (char **)calloc(I, sizeof(char*));
    for (int i = 0; i < I; i++) {
        ln_text[i] = (char*)calloc(J, sizeof(char));
        //fgets(ln_text[i], J, stdin);
    }
    printf("\n");
    ln_text[0] = "Таким образом, дальнейшее развитие различных форм деятельности напрямую зависит от кластеризации усилий. "
                 "И нет сомнений, что тщательные исследования конкурентов, вне зависимости от их уровня, должны быть превращены в посмешище, хотя само их существование приносит несомненную пользу обществу. "
                 "Сложно сказать, почему ключевые особенности структуры проекта и по сей день остаются уделом либералов, которые жаждут быть функционально разнесены на независимые элементы. "
                 "Но укрепление и развитие внутренней структуры предоставляет широкие возможности для вывода текущих активов. "
                 "Также как понимание сути ресурсосберегающих технологий требует анализа первоочередных требований.";

    for (int i = 0; i < I; i++) {
        emphasizing(ln_text[i], J);
    }

    //Освобождаем память
//    for (int i = 0; i < I; i++) {
//        free(ln_text[i]);
//    }
    //free(ln_text);
    return 0;
}

void emphasizing(char *ln_text, int Columns) {
    int status = 0, count = 0;
    int words[J];
    for (int j = 0; j < J; ++j) {
        words[j] = 0;
    }

    for (int j = 0; j < Columns; j++) {
        if (isalpha((unsigned char) ln_text[j]) != 0) {
            count++;
            if (isVowel(ln_text[j]) && isVowel(ln_text[j + 1]) && ln_text[j] == ln_text[j + 1]) {
                status = 1;
            }
        } else {
            if (status) words[j - count - 1] = words[j - 1] = 1;
            count = 0, status = 0;
        }
    }

    count = 0;
    for (int j = 0; j < Columns; j++) {
        if (count == I) break;
        if (ln_text[j] == '\0') count++;
        if (words[j] == 1) {
            printf("%c%c", (char) ln_text[j], '!');
        } else {
            printf("%c", (char) ln_text[j]);
        }
    }

//    for (int j = 0; j < Columns; j++) {
//        printf("%d", words[j]);
//    }
}

int isVowel(char symbol) {
    char vowels[20] = { 'а','у','о','ы','и','э','я','ю','ё','е','А','У','О','Ы','И','Э','Я','Ю','Ё','Е' }; //Ошибку Character too large for enclosing character literal type, при возникновении, игнорировать.
    for (int i = 0; i < 20; ++i) {
        if (symbol == vowels[i]) return 1;
    }
    return 0;
}