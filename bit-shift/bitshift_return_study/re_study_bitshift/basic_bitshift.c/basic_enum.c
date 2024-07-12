#include <stdio.h>
#include <stdint.h>
#define NEWLINE printf("\n");
#define PRINT(x) printf("%d\n", x);

enum {
    // 何も割り振らないと上から1, 2, 3となる
    ZERO,
    ONE,
    TWO,
};

enum  Food{
    RICE = 123,
    BRED = 456,
    MEAT,  // 457になる
};

typedef enum {
    age = 23,
    xxx = 3,
} Human;

typedef enum {
    CAT,
    DOG,
    DRAGON
} AnimalType;

void printAnimal(AnimalType animal) {
    switch (animal) {
        case CAT:
            printf("This is a cat.\n");
            break;
        case DOG:
            printf("This is a dog.\n");
            break;
        case DRAGON:
            printf("This is a dragon.\n");
            break;
        default:
            printf("Unknown animal.\n");
            break;
    }
}

int main(void){
    printf("ZERO %d\n", ZERO);
    printf("ONE %d\n", ONE);
    printf("TWO %d\n", TWO);
    printf("RICE %d\n", RICE);
    printf("BRED %d\n", BRED);
    printf("MEAT %d\n", MEAT);
    enum Food food = RICE;
    printf("food %d\n", food);
    Human Kotoha;
    printf("Kotoha %d\n", age);

    AnimalType myAnimal = CAT;
    printAnimal(myAnimal);
    myAnimal = DRAGON;
    printAnimal(myAnimal);

}