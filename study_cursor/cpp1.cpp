#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Animal{
    public:
        Animal(string n, string k) : name(n), sound(k){}
    
    virtual void makeSound(){
        cout << name << "は" << sound << "と鳴いた" << endl;
    }

    protected:
        string name;
        string sound;
};

class Dog : public Animal{
    public:
        Dog(string n) : Animal(n, "BowBow"){}
};

class Cat : public Animal{
    public:
        Cat(string n) : Animal(n, "NeowNeow"){}
};

int main(){
    Dog Kotoha("Kotoha");
    Kotoha.makeSound();
    NEWLINE;
    Cat Hanon("Hanon");
    Hanon.makeSound();
    NEWLINE;
    Animal* pet1 = new Dog("Tsushi");
    pet1->makeSound();
    delete pet1;
}