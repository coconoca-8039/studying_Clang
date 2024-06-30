#include <stdio.h>

typedef struct {
    int apple;
    int orange;
    int banana;
}Fruits;

int main(void){
    // typedef unsigned int seisu;
    // unsigned int number = 15;
    //seisu number = 15;
    //pritnf("%d\n", number);
    
    Fruits store;
    store.apple = 1000;
    printf("リンゴの金額:%d円\n", store.apple);

    return 0;
}