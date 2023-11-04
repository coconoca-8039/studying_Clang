#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

// C言語基礎：ポインタの基礎
// basics of C pointer
// *をつけるとその値を持ってこれる

void setTen(int *x){
    // 参照呼び出し
    *x = 10;
}

void min_max(int x, int y, int *minP, int *maxP){
    if(x < y){
        *minP = x;
        *maxP = y;
    }else{
        *minP = y;
        *maxP = x;
    }
}

int main(void){

    int a = 0;
    int b = 0; 
    int min = 0;
    int max = 0;

    while(1){
        scanf("%d %d", &a, &b);
        if(a == 9999) break;
        min_max(a, b, &min, &max);
        printf("min = %d, max = %d\n", min, max);
    }

    // // 参照呼び出し
    // int a = 20;
    // setTen(&a);  // アドレスを渡す
    // printf("%d\n", a);

    return 0;

    // int a = 0;
    // int *b = &a;
    // int c = 5;
    // int *d = &c;
    // printf("a = %d, b = %x\n", a, b);       // a = 0, b = 6fb3eebc
    // printf("a = %d, *b = %d\n", a, *b);     // a = 0, *b = 0
    // a = a + 15;
    // printf("a = %d, *b = %d\n", a, *b);     // a = 15, *b = 15
    // *b = 25;
    // printf("a = %d, *b = %d\n", a, *b);     // a = 25, *b = 25
    // printf("c = %d, *c = %d\n", c, *d);     // c = 5, *c = 5

}