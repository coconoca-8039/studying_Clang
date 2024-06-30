#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#define NEWLINE printf("\n");

int main(void){
    
    int count = 10;
    int *ptr;
    ptr = &count;
    printf("%d\n", *ptr);  // 値
    printf("%d\n", &ptr);  // アドレス


}