#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define KAIGYO printf("\n");

// プリプロセッサ指令を用いて構造体を定義する

#define decl_tuple(Name, T1, T2) typedef struct{ \
    int first; \
    int second; \
}Name; \

Tuple calc(int a){
    Tuple result = {a * 2, a * 4, };
    return result;
}

int main(void){
    Tuple result = calc(2);
    printf("first : %d\nsecond : %d\n", result.first, result.second);
    return 0;
}