#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubble(int y[], int num3){
    int i = 0;
    int j = 0;
    for(i = 0; i < num3 - 1; i++){
        for(j = num3 -1; j > i; j--){
            if(y[j-1] > y[j]){
                swap(&y[j], &y[j-1]);
            }
        }
    }
}

void show(int x[], int num2){
    int i;
    for(i = 0; i < num2; i++){
        printf("%d ", x[i]);
    }
    NEWLINE;
}

int main(void){
    int num = 0;
    printf("要素数を入力してください\n");
    scanf("%d", &num);

    int array[num];
    int i = 0;
    
    for(i = 0; i < num; i++){
        scanf("%d", &array[i]);
    }

    printf("▪1回目の出力\n");
    show(array, num);

    printf("▪バブルソート後\n");
    bubble(array, num);
    show(array, num);

}