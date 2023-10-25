#include <stdio.h>
#include <stdint.h>

int main(void){
    
    for (int i =0; i < 4; i++){
        printf("%d\n", i);
    }

    printf("\n");
    for(int j = 0; j < 8; j += 2){
        printf("%d\n", j);
    }

    printf("\n");
    for(int i =0; i < 6; i++){
        if(i % 2 == 0){
            printf("kotocahn\n");
        }else{
            printf("hanon\n");
        }
    }

    printf("\n");
    for(int k = 0; k < 4; k++){
        switch (k){
            case 0: printf("kotoha\n"); break;
            case 2: printf("hanonchan\n"); break;
            default: printf("capi\n"); break;
        }
    }

    printf("\n");
    int sum = 0;
    for(int i = 1; i <= 9; i++){
        sum += i;
    }
    printf("%d\n", sum);

    printf("\n");
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            printf("%d ", i * j);
        }
        printf("\n");
    }

    printf("\n");
    const char *str = "kotoha";
    for(const char *p = str; *p; p++){
        printf("%c\n", *p);
    }

    return 0;
}