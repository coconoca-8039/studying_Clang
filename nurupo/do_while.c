#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define KAIGYO printf("\n");

int main(void){
    int i = 0;
    char buf[100];

    do{
        printf("i : %d\n", i);
        i += 1;
    }while(i < 4);
    printf("end : %d\n", i);
    KAIGYO;

    // int age = 0;
    // do{
    //     printf("年齢を入力してください > \n");
    //     if(!fgets(buf, sizeof buf, stdin)){
    //         break;
    //     }
    //     age = atoi(buf);
    // }while(age < 20);

    int a = 1;
    printf("out a %d\n", a);

    do{
        int a = 2;
        printf("in a %d\n", a);
    }while(0);
    KAIGYO;

    {
        printf("こんな書き方も可能\n");
    }

    return 0;
}