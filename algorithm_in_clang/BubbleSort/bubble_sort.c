#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// バブルソート
// 配列を引数として渡すと、それはポインタとして先頭要素が渡される

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void show(int x[], int length){
    for(int i = 0; i < length; i++){
        printf("%d ", x[i]);
    }
    NEWLINE;
}

void bubble(int y[], int length){
    int i = 0;  // 巡回用の変数
    int j = 0;  // 比較用の変数
    for(i = 0; i < length - 1; i++){
        for(j = length - 1; j > i; j--){  // 右端から比較し始めるからj=4
            if(y[j-1] > y[j]){
                swap(&y[j], &y[j-1]);  // 外部の関数で変数を変更するにはポインタで渡す必要がある
            }
        }
    }
}

int main(void){
    int array[7]= {5, 2, 4, 3, 1, 33, 44};
    int length = sizeof(array) / sizeof(array[0]);
    printf("▪️配列の要素数 : %d\n", length);
    printf("▪1回目の出力\n");
    show(array, length);

    printf("▪バブルソート後\n");
    bubble(array, length);
    show(array, length);

}