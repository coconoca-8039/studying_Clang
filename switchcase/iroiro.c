#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");
typedef unsigned char uchar;

struct Person{
    // メンバー変数
    int age;
    unsigned int height;
    short weight;
}kotoha;

typedef struct{
    int age;
    unsigned int height;
    short weight;
}Kotototo;

int main(void){
    
    struct Person kotochan;
    kotochan.age = 20;
    kotochan.height = 150;
    kotochan.weight = 40;
    printf("%d %d %d", kotochan.age, kotochan.height, kotochan.weight);
    
}