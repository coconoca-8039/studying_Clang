#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "subfile.c"

// プロトタイプ宣言
int ave(int x[]);

int main(void){
    int test[5];
    int i = 0;
    for(i = 0; i < 5; i++){
        printf("%d人目の点数:", i + 1);
        scanf("%d", &test[i]);
    }
    int average;
    average = ave(test);
    printf("平均点は%dです", average);
}

int ave(int x[]){
    // int xとtestは全く別の配列であることに注意
    int i;
    int sum = 0;
    for(i = 0; i < 5; i++){
        sum += x[i];  //合計値が入る
    }
    return sum / 5;
}