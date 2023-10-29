#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define PRINT_INT(var) printf("%d\n", var)
#define PRINT_CHAR(var) printf("%s\n", var)

// サイズを求めるマクロ
#define numof(ary) (sizeof ary / sizeof ary[0])

void func(int ary[]){
    // 配列を渡しているように見えるが、実態はポインタ
    // func関数とメイン関数内でaryのサイズが異なってしまっている
    // int型のサイズは4Byte
    printf("void func(int ary[])\n");
    printf("ary[0] = %d\n", ary[0]);
    printf("ary[1] = %d\n", ary[1]);
    printf("ary[2] = %d\n", ary[2]);
    printf("sizeof ary in func = %d\n", sizeof ary);  // sizeof ary in func = 8
}

void pointa_func(int *ary){
    // ポインタを渡してみる
    printf("void pointa_func(int *ary)\n");
    printf("p ary[0] = %d\n", ary[0]);
    printf("p ary[1] = %d\n", ary[1]);
    printf("p ary[2] = %d\n", ary[2]);
    printf("sizeof ary in pointa_func = %d\n", sizeof ary);  // sizeof ary in func = 8
}

void arylen(int ary[], int arylen){
    // arylenのサイズに注意
    printf("void arylen(int ary[], int arylen)\n");
    // forループで
    for(int i = 0; i < arylen; i++){
        printf("ary[%d] = %d\n", ary[i]);
    }
}

int main(){
    int ary[] = {1, 2, 3};
    func(ary);
    printf("sizeof ary in main = %d\n", sizeof ary);  // sizeof ary in main = 12
    printf("sizeof int = %ld\n", sizeof(int));  //sizeof int = 4
    printf("sizeof int* = %ld\n", sizeof(int *));  // sizeof int* = 8
    printf("\n");
    pointa_func(ary);
    printf("\n");
    arylen(ary, 3);

    // []を使う人が多いかも
    // 引数名で識別できればポインタで渡しても問題ない
    // 動的にメモリを確保したい時はポインタで確保することが多い

    return 0;
}