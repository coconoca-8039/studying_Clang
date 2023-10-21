#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "subfile.c"

// ポインタはあくまでアドレスしか持てない
// ポインタに*をつけると、それが指すモノを表す
// ポインタに数値を代入することはできない　*p = 10とかはできない
// ＆アンド演算子をつけることでその変数のアドレスを取り出すことができる

/*
int main(void){
    // ポインタの基本
    int apple = 10;
    int *p;
    p = &apple;
    printf("%d\n", *p);
    return 0;
}
*/

// 別の関数から値を操作するための関数
void keisan(int *x){
    *x = 205;
};

int main(void){
    int apple = 100;
    printf("1回目:%d\n", apple);

    keisan(&apple);  // アンドをつけてアドレスそのものを渡す(参照渡し)
    printf("書き換えました\n");
    printf("2回目:%d\n", apple);

    return 0;
}


