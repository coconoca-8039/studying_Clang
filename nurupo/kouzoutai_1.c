#include <stdio.h>
#include <string.h>

struct animal{
    int age;
    double weight;    
};

int main(void){

    struct animal cat;
    printf("cat age[%d] weight[%lf]\n", cat.age, cat.weight);
    // このまま出力すると変な値が入っている 
    //cat age[-2139848748] weight[0.000000]

    struct animal dog = {0};
    printf("dog age[%d] weight[%lf]\n", dog.age, dog.weight);
    // = {0} にすると初期化される
    //dog age[0] weight[0.000000]

    struct animal monkey = {20, 40,3};
    printf("monkey age[%d] weight[%lf]\n", monkey.age, monkey.weight);
    // monkey age[20] weight[40.000000]

    struct animal fish = {
        .age = 22,
        .weight = 234,
    };
    printf("fish age[%d] weight[%lf]\n", fish.age, fish.weight);
    // ageとweightの順番は反対でもOK
    // fish age[22] weight[234.000000]

    struct animal human;
    memset(&human, 0, sizeof(struct animal));
    printf("human age[%d] weight[%lf]\n", human.age, human.weight);
    // memsetでも初期化できる
    // human age[0] weight[0.000000]

    return 0;
}