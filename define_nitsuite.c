#include <stdio.h>
#include <stdint.h>
#include "header.h"

// トークン
// マクロ置換　マクロ
#define EXPR (1 + 1)
#define TEST int a = 100

#define DEF_VAR(type, var, value) type var = value

#define INFO printf("hello\n"); \
    printf("good\n"); \
    printf("world\n");

// これでONEというトークンを無効化することができる
#define ONE 1
#undef ONE  
// 先にundefして確実にdefineできるようにすることもできる
#undef TWO
#define TWO 2 

// 1にしないとエラーになるけどif文を作ることも可能
#if 1 
#define THREE 3
#endif

// defineされているか調べると気は
// ifndefも可能
// if defined()にすることも可能
#ifdef DOIT
#define EEE
#endif

#if defined(KOTO) || defined(HANO) // こういうのも可能
#define CAPI // 定義されない
#endif

// printfをするだけのdefine
#define PRINT_INT(var) printf(#var " = %d\n", var)

int main(){

    int result = EXPR;
    printf("%d\n", result);

    TEST;
    printf("%d\n", a);

    DEF_VAR(int, abc, 1000);
    printf("%d\n", abc);

    INFO;

    printf("%d\n", THREE);

    int xxxx = 12345;
    PRINT_INT(xxxx);

    return 0;
}