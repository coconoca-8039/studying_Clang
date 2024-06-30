#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

int main(void){
    int sw;
    int n1 = 15;
    int n2 = 77;
    int *p;

    printf("n1は%dでn2は%dです\n", n1, n2);
    printf("変更するのは n1 or n2\n");
    scanf("%d", &sw);

    if(sw == 1){
        p = &n1;  // pにn1のアドレスを代入
    }else{
        p = &n2;  // pにn2のアドレスを代入
    }

    *p = 99;  // pが指すオブジェクトに99を代入

    printf("n1は%dでn2は%dです\n", n1, n2);

    // コンパイル時ではなく、プログラム実行時に値が決定される

    return 0;
}
