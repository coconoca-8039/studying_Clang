#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "subfile.c"

int GetFatnesss(int t, int w){
    double stdw; //標準体重
    double r; //肥満率

    stdw = (t - 100) * 0.9;
    r = w / stdw;
    return (int)(r * 100);
}

int main(void){
    // printf("harucha\n");
    // printf("%d\n", xxx);
    // printf("%s\n", singer);

    int t = 0;
    int w = 0;

    puts("身長と体重を入力してください");
    scanf("%d%d", &t, &w);
    printf("あなたの肥満度は%d%%です\n", GetFatnesss(t, w) - 100);

}