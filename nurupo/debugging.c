// printfによるデバッグ
// デバッガーによるデバッグ

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define KAIGYO printf("\n");

int main(void){
    int i = 1;
    //int *p = NULL;
    int *p = &i;

    printf("%d\n", *p);

    return 0;
}