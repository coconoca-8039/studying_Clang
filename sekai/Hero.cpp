#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Charactor{
    public:
        Charactor(string n) : name(n), baseDamage(0){}
    
    virtual void attack(){
        cout << name << "の攻撃" << endl;
    }

    void setDamage(int damage) {
        baseDamage = damage;  // 単純にbaseDamageを設定
        cout << "攻撃力を" << baseDamage << "に変更" << endl;
    }

    void setDamage(int damage, double multiplier) {
        baseDamage = static_cast<int>(damage * multiplier);  // damageとmultiplierの積を設定
        cout << "攻撃力を" << baseDamage << "に変更" << endl;
    }

    void enhance(){
        auto increaseDamage = [this](){
            this->baseDamage += 10;
            cout << "攻撃力を" << baseDamage << "に増強しました" << endl;
        };
        increaseDamage();
    }

    protected:
        string name;
        int baseDamage;
};

class Hero : public Charactor{
    public:
        Hero(string n) : Charactor(n){}
        
        void attack() override{
            // オーバーライドで使用できる変数は基底クラスでprotectedされているメンバ変数だけ
            cout << name << "の攻撃 : " << baseDamage << endl;
        }

        void attack(int damege, double multi){
            cout << name << "の攻撃 : " << damege * multi << endl;
        }

    private:
};

class Mage : public Charactor{
    public:
        Mage(string n) : Charactor(n){}

        void attack() override{
            cout << name << "の魔法攻撃 : " << baseDamage << endl;
        }

        void attack(int damege, double multi){
            cout << name << "の魔法攻撃 : " << damege * multi << endl;
        }
};

int main(){
    Hero Himmel("ヒンメル");
    Himmel.attack();
    Himmel.setDamage(1000);
    Himmel.attack();
    Himmel.attack(5, 3);
    NEWLINE;

    Mage Frieren("フリーレン");
    Frieren.attack();
    Frieren.setDamage(123);
    Frieren.attack();
    Frieren.attack(23, 3.14);
    Frieren.enhance();
    Frieren.attack();
    NEWLINE;
}
