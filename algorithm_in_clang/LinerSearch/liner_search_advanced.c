#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

int search(int array2[], int num2, int ans2){
    int i = 0;
    array2[num2] = ans2;  // 配列の最後尾にans2を代入してしまう 番兵というらしい
    while(1){
        if(array2[i] == ans2){
            break;
        }else{
            i++;
        }        
    }
    if(i == num2){
        return -1;
    }else{
        return i;
    }
}

int main(void){
    int num = 0;
    int ans = 0;
    int array[num];
    int i = 0;

    printf("配列の要素数は?\n");
    scanf("%d", &num);
    for(i = 0; i < num; i++){
        printf("%d番目 : ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("探す数は?\n");
    scanf("%d", &ans);
    int result = search(array, num, ans);
    if(result == -1){
        printf("お探しの数値はありません\n");
    }else{
        printf("%dは%d番目にあります\n", ans, result+1);
    }
}