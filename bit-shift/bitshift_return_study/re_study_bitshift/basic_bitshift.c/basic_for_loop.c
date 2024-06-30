#include <stdio.h>
#define NEWLINE printf("\n");

int main() {
    // 1から5までの数を出力する
    for (int i = 1; i <= 5; i++){
        printf("%d ", i);
    }
    NEWLINE;
    NEWLINE;

    // 多重ループ
    for (int i = 1; i <= 5; i++){
        for (int j = 1; j <= 5; j++){
            printf("%d", i * j);
        }
        printf("\n");
    }
    NEWLINE;

    for (int i = 1; i <=10; i++){
        if (i == 5){
            printf("SKIP\n");
            continue;
        }
        if (i == 8){
            printf("END\n");
            break;
        }
        printf("%d\n", i);
    }

    return 0;
}