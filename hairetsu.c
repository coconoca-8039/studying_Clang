#include <stdio.h>

int main(void){
    int array1[5] = {1, 2, 3, 4, 5};
    int array2[5];
    int i;
    printf("第1回\n");
    for(i = 0; i < 5; i++){
        printf("array2[%d]:\n", i, array2[i]);
    }
    for(i = 0; i <5; i++){
        array2[i] = array1[i];
    }
    printf("第2回\n");
    for(i = 0; i < 5; i++){
        printf("array2[%d]:\n", i, array2[i]);
    }
    return 0;
}