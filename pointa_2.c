#include <stdio.h>

// 複数の戻り値を返す方法

void keisan(int n1, int n2, int *tasu, int *hiku){
    *tasu = n1 + n2;
    *hiku = n1 - n2;
}

int main(void){
    int num1 = 30;
    int num2 = 10;
    int tasizan = 0;
    int hikizan = 0;
    keisan(num1, num2, &tasizan, &hikizan);
    printf("足し算の結果 : %d\n", tasizan);
    printf("引き算の結果 : %d\n", hikizan);
    return 0;
}