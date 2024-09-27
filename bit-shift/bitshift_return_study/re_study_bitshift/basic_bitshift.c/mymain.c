#include "myheader.h"
#include "myfunction.c"
#include <stdio.h>

// インクルードの練習
// 同じディレクトリにmyheader.hとmyfunction.cを入れておくこと

int main() {
    greet();
    int result = add(5, 3);
    printf("The result of adding 5 and 3 is: %d\n", result);

    // マクロを使用
    printf("The value of PI is: %f\n", PI);
    printf("The square of 4 is: %d\n", SQUARE(4));

    return 0;
}