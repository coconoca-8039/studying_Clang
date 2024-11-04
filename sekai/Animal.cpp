#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Animal{
    public:
        Animal(string animal_name) : name(animal_name){}
    
    virtual void makeSound(){
        cout << name << "が鳴いている" << endl;
    }

    // void makeSound(int volume){
    //     makeSound();
    //     cout << name << "が" << volume << "で鳴いている" << endl;
    // }

    protected:
        string name;
};

// 継承
class Cat : public Animal{
    public:
        Cat(string animal_name, int cat_volume) : Animal(animal_name), volume(cat_volume){}

        // オーバーライド
        void makeSound() override{
            cout << name << "がニャーニャーと鳴いている" << endl;
        }

        // オーバーロード
        void makeSound(int volume){
            cout << name << "がボリューム" << volume << "でニャーニャーと鳴いている" << endl;
        }
    
    private:
        int volume;
};

int main(){
    Cat cat("タマ", 120);
    cat.makeSound();    // オーバーライド nameがニャーニャーと鳴いている
    cat.makeSound(12);  // オーバーロード nameがボリューム3でニャーニャーと鳴いている

    Cat rinu("莉犬", 10);
    rinu.makeSound(2000);
}