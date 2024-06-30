// メイン
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include "subfile.c"

struct Student{
    int year;
    char name[64];
    double weight;
    double height;
    // struct Student Kotoha;
};

struct {
    int year;
    char name[64];
    double weight;
    double height;
}Tarou, Hanako;

struct Fruits{
    int apple;
    int orange;
    int banana;  
};

struct Test{
    char name[32];
    int kokugo;
    int sansu;
    int eigo;
};

struct Test student[3] = {
    {"kotoha", 40, 50, 60},
    {"hanon", 55, 65, 75},
    {"capi", 80, 90, 100}
};

// プロトタイプ宣言
void price(struct Fruits store1);
void line(void);
void show(void);

// This is the main loop
int main(void){
    printf("%10s %10s %10s %10s\n", "名前", "国語", "算数", "英語");
    line();
    show();
    line();
    return 0;
}

void line(void){
    int i;
    for(i = 0; i < 50; i++){
        printf("-");
    }
    printf("\n");
    return;
}

void show(void){
    int i;
    for(i = 0; i < 3; i++){
        printf("%8s %8d %8d %8d\n",
        student[i].name, student[i].kokugo, student[i].sansu, student[i].eigo);
    }
    return;
}

void price(struct Fruits store1){
    printf("apple:%d\n", store1.apple);
    printf("orange:%d\n", store1.orange);
    printf("banana:%d\n", store1.banana);
    return;
    // 以下をメイン関数内に入れると使用できる関数
    // struct Fruits store1 = {1000, 2000, 3000};
    // price(store1);
}