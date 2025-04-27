#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

#define ROWS 3
#define COLS 4

int main() {
    system("chcp 65001");

    int matrix[ROWS][COLS];
    int vector[COLS];
    int result[ROWS];

    printf("Введіть матрицю (%d x %d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i+=1){
        for (int j = 0; j < COLS; j+=1){
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Введіть вектор (%d елементів):\n", COLS);
    for (int i = 0; i < COLS; i+=1){
        scanf("%d", &vector[i]);
    }

    for (int i = 0; i < ROWS; i+=1) {
        result[i] = 0;
        for (int j = 0; j < COLS; j+=1){
            result[i] += matrix[i][j] * vector[j];
        }
    }

    int min = INT_MAX, index = -1;
    for (int i = 0; i < ROWS; i+=1) {
        if (result[i] < 0 && result[i] < min) {
            min = result[i];
            index = i;
        }
    }

   
    printf("\nРезультат множення:\n");
    for (int i = 0; i < ROWS; i+=1){
        printf("%d ", result[i]);
    }

    if (index != -1){
        printf("\n\nНайменший від’ємний елемент: %d (номер %d)\n", min, index+1);
    }
    else{
        printf("\n\nВід’ємних елементів немає.\n");
    }

    return 0;
}