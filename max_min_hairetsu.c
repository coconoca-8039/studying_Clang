#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "subfile.c"

int main(void){
    int test[5];
    int i;
    for(i = 0; i < 5; i++){
        printf("%d番目の生徒の点数:", i);
        scanf("%d", &test[i]);
    }
    int min = test[0];  // 初期化で0を入れるとmin = test[i]が駄目になくなる
    int max = test[0];
    for (i = 0; i < 5; i++){
        if(test[i] > max) max = test[i];
        if(test[i] < min) min = test[i];
    }
    printf("最高点: %d\n", max);
    printf("最低点: %d\n", min);
    return 0;
}