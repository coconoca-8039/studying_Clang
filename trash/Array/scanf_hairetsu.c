#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "subfile.c"

int main(void){
    int num = 0 ;
    printf("配列の要素数は何個ですか");
    scanf("%d", &num);

    int array[num];
    int i = 0;
    printf("配列に%d個数値を入力してください\n", num);
    // 自分で指定した要素数の分だけscanfをして数値を入れ込む
    for(i = 0; i < num; i++){
        printf("%d番目の値は?", i);
        scanf("%d", &array[i]);
    }
    
    printf("入力した値を出力します\n");
    for(i = 0; i < num; i++){
        printf("array[%d]:%d\n", i, array[i]);
    }
    
    return 0;
}