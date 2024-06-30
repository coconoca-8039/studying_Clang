#include <stdio.h>
#include <stdint.h>
#define NEWLINE printf("\n");

#define EXPR (1 + 1)  // 括弧をつけておくこと
#define RPXE int a = 1

#define DEF_VAR(type, var, value) type var = value

#define INFO printf("Kotoha\n"); \
            printf("kawaii\n"); \
            printf("hanifes\n");

#undef ONE
#define ONE 1234
// #undef ONE  // defineを無効にできる

#if 1  // 0にすると実行されない
#define TWO 2
#endif

#define DOIT 1000
#ifdef DOIT
#define THREE 3
#endif

#ifndef TRY
#define FOUR 4
#endif

// DOITが定義されていない or TRYが定義されている
#if defined(DOIT) || defined(TRY)
#define FIVE 5
#endif

int main() {
    // マクロ
    int result = EXPR;
    printf("%d\n", result);  // 2

    result = 2 * EXPR;
    printf("%d\n", result);  // 4

    // int a = 1;に置き換わる
    DEF_VAR(int, a, 1);  
    printf("%d\n", a);  // 1

    INFO;

    printf("%d\n", ONE);
    printf("%d\n", TWO);
    printf("%d\n", THREE);
    printf("%d\n", FOUR);
    printf("%d\n", FIVE);

    /*****************************/
    /*
    define
    ・テキスト置換であるため型情報がない
    ・スコープはない　ファイル全体で使用可能
    
   const
   ・変数を定数として定義
   ・スコープはある

    コンパイルの前後のどちらで置き換わるか程度
    constの方が自由度高いし、デバッグ時にもわかりやすいかもね

   */
    

    /*const*/

    return 0;
}