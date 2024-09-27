#include <stdio.h>
#include <stdint.h>
#define NEWLINE printf("\n");
#define PRINT(x) printf("%d\n", x);

int main(){
    int nums[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int size = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i <= size; i++){
        int tmp = nums[i];
        if ((tmp % 3 == 0) && (tmp % 5 == 0)){
            printf("%d ", i + 1);
            printf("fizzbuzz\n");
        }else if (tmp % 3 == 0){
            printf("%d ß", i + 1);
            printf("fizz\n");
        }else if(tmp % 5 == 0){
            printf("%d ", i + 1);
            printf("buzz\n");
        }else{
            printf("%d\n", i + 1);
        }
    }

    /*
    for (int i = 1; i <= 15; i++){
        if (i % 3 == 0 && i % 5 == 0) printf("fizzbuzz\n");
        else if (i % 3 == 0) printf("fizz\n");
        else if (i % 5 == 0) printf("buzz\n");
        else PRINT(i);
    }
    */
   
    /*
   for (int i = 1; i <= 15; i++){
        (i % 3 == 0 && i % 5 == 0) ? printf("fizzbuzz\n") :
        (i % 3 == 0) ? printf("fizz\n") :
        (i % 5 == 0) ? printf("buzz\n") :
        printf("%d\n", i);
    }
   */

    return 0;
}