#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define KAIGYO printf("\n");

// C言語の配列とその美しさ

int main(void){
    int ary[3] = {1, 2, 3};
    printf("%d\n", ary[0]);
    printf("%d\n", ary[1]);
    printf("%d\n", ary[2]);
    
    KAIGYO;
    printf("size of int : %ld\n", sizeof(int));  // 4バイト
    printf("size of ary : %ld\n", sizeof(ary));  // 12バイト
    printf("size of ary[0] : %ld\n", sizeof(ary[0]));  // 4バイト
    printf("element of ary[0] : %ld\n", sizeof ary / sizeof ary[0]);  // 3バイト
    KAIGYO;
    
    int *p = ary;
    printf("size of pointa : %ld\n", sizeof p);  // ポインタの8バイトを表示してしまう
    
    KAIGYO;
    int array[] = {4, 5, 6, -1};  // 配列の要素数を省略すると、初期化子リストの要素数がそのまま要素数になる
    // 普通にforを回してみる
    for(int i = 0; i < (sizeof array / sizeof array[0]); i++){
        printf("%d\n", array[i]);
    }
    KAIGYO;
    // ポインタを使用して回してみる
    // p += 1 ではアドレス値が増える
    // *p += 1 では要素の値が増える
    for(int *p = array; *p != -1; p +=1){
        printf("%d\n", *p);
    }
    KAIGYO;

    // 全てに0を入れておく
    int xxx[3] = {0};
    for(int i = 0; i < (sizeof xxx / sizeof xxx[0]); i++){
        printf("xxx : %d\n", xxx[i]);
    }
    KAIGYO;
    // memsetで初期化する方法
    int zzz[3];
    memset(zzz, 0, sizeof zzz);
    for(int i = 0; i < (sizeof zzz / sizeof zzz[0]); i++){
        printf("zzz : %d\n", zzz[i]);
    }


    return 0;
}