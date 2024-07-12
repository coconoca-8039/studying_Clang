#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define NEWLINE printf("\n");
#define PRINT(x) printf("%d\n", x);

struct animal{
    int age;
    double weight;

};

typedef struct {
    int age;
    double weight;
}Dog;

int main(void){
    // struct animal kotoha; // 初期化していないので意味不明な数字が入る
    // struct animal cat = {0};  // これで構造体変数を全て初期化
    
    struct animal cat = {20, 40.3};
    
    struct animal dragon;
    dragon.age = 200;
    dragon.weight = 339;

    memset(&cat, 0, sizeof(struct animal));  // memsetでも初期化することが可能

    printf("age[%d] weight[%f]\n", cat.age, cat.weight);
    NEWLINE;

    Dog Koto = {9, 3};
    printf("age[%d] weight[%f]\n", Koto.age, Koto.weight);

    return 0;
}