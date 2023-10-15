#include <stdio.h>

int main(void){
    /*
    int i, j;
    for(i = 1; i <= 9; i++){
        printf("%dの段", i);
        for(j = 1; j <= 9; j++){
            printf("%4d", i * j);
        }
        printf("\n");
    }
    
    //出力結果
    //1の段   1   2   3   4   5   6   7   8   9
    //2の段   2   4   6   8  10  12  14  16  18
    //3の段   3   6   9  12  15  18  21  24  27
    //4の段   4   8  12  16  20  24  28  32  36
    //5の段   5  10  15  20  25  30  35  40  45
    //6の段   6  12  18  24  30  36  42  48  54
    //7の段   7  14  21  28  35  42  49  56  63
    //8の段   8  16  24  32  40  48  56  64  72
    //9の段   9  18  27  36  45  54  63  72  81
    */


   /*
    int height = 0; 
    int width = 0;
    int i, j;
    printf("縦の長さは?");
    scanf("%d", &height);
    printf("横の長さは?");
    scanf("%d", &width);
    for(i = 1; i <= height; i++){
        for(j = 1; j <= width; j++){
            printf("⚫︎");
        }
        printf("\n");
    }

    //出力結果
    //縦の長さは?2
    //横の長さは?7
    //⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎
    //⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎
    */


   /*
    int length = 0;
    printf("一辺の長さは?");
    scanf("%d", &length);
    int i = 0;
    int j = 0;
    for(i = 1; i <= length; i++){
        for(j = 1; j <= (length - i); j++){
            printf("  ");
        }
        for(j =1; j<= i; j++){
            printf("⚫︎");
        }
        printf("\n");
    }

    //出力結果
    //一辺の長さは?7
    // ⚫︎
    // ⚫︎⚫︎
    // ⚫︎⚫︎⚫︎
    // ⚫︎⚫︎⚫︎⚫︎
    // ⚫︎⚫︎⚫︎⚫︎⚫︎
    // ⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎
    // ⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎⚫︎
    */


    int stage = 0;
    printf("ピラミッドの段数は");
    scanf("%d", &stage);
    int i = 0;
    int j = 0;
    for (i = 1; i <= stage; i++){
        for(j = 1; j <= stage -1; j++){
            printf("   ");
        }
        for(j = 1; j <= (i-1)*2 + 1; j++){
            printf("⚫︎");
        }
        printf("\n");
    }
    //出力結果(本当はピラミッドみたいになるはずだった)
    // ピラミッドの段数は5
    //          ⚫︎
    //          ⚫︎ ⚫︎ ⚫︎
    //          ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎
    //          ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎
    //          ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎ ⚫︎
    
    return 0;
}