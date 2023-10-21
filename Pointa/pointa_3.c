#include <stdio.h>

struct Fruits{
    char name[128];
    int price;
    int zaiko;
};

typedef struct{
    int math;
    int english;
}siken;


int main(void){
    struct Fruits store = {"apple", 150, 500};
    struct Fruits *p;
    p = &store;
    printf("名前 : %s\n", (*p).name);
    printf("価格 : %d\n", p->price);  // アロー演算子でもいける
    printf("在庫 : %d\n", p->zaiko);

    // ここから下は復習を兼ねているだけ
    siken kotoha = {100, 99};
    siken *po;
    po = &kotoha;
    printf("数学 : %d\n", po->math);
    printf("英語 : %d\n", po->english);

    return 0;
}