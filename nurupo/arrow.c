#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#define KAIGYO printf("\n");

struct Head{
    int eyes;
};

struct Animal{
    int age;
    struct Head *head;
};

int main(){
    struct Head head = {.eyes = 4};
    struct Animal animal = {.age = 20, .head = &head};
    struct Animal *p = &animal;
    
    printf("eyes: %d\n", p->head->eyes);

    return 0;
}