#include <stdio.h>
#include <stdint.h>
#define NEWLINE printf("\n");
#define PRINT(x) do {\
                printf("%d\n", x); \
                printf("%d\n", x); \
                }while (0)

int main(){
    // gcc -E  advanced_define.c advanced_define
    PRINT(1);
    int n = 0;
    PRINT(++n);  //  printf("%d\n", ++n); printf("%d\n", ++n);

    return 0;
}