#include <iostream>
#include <string>
using namespace std;
#define NEWLINE std::cout << std::endl

class Instrument{
    public:
        Instrument(string n) : name(n), volume(0), pitch(0){}
    
    virtual void play(){
        cout << name << "の演奏" << endl;
    }

    void setVolume(){
        volume = 10;
        pitch = 20;
        cout << name << " 音量 : " << volume << " 音階 : " << pitch << endl;
    }

    void setVolume(int vol){
        volume = vol;
        cout << name << " 音量 : " << volume << endl;
    }

    void setVolume(int volume, int pitch){
        this->volume = volume;
        this->pitch = pitch;
        cout << name << " 音量 : " << volume << " 音階 : " << pitch << endl;
    }
    
    protected:
        string name;
        int volume;
        int pitch;
};

class Piano : public Instrument{
    public:
        Piano(string n) : Instrument(n){}

    void play() override{
        cout << name << "がメロディを奏でる" << " 音量 : " << volume << " 音階 : " << pitch << endl;
    }

};

class Guitar : public Instrument{
    public:
        Guitar(string n) : Instrument(n){}
    
    void play() override{
        cout << name << "がバッキング" << " 音量 : " << volume << " 音階 : " << pitch << endl;
    }
};

int main(){
    Piano piano("ピアノ");
    piano.play();                   // ピアノがメロディを奏でる 音量 : 0 音階 : 0
    NEWLINE;
    piano.setVolume(66);            // ピアノ音量 : 66
    piano.play();                   // ピアノがメロディを奏でる 音量 : 66 音階 : 0
    NEWLINE;
    piano.setVolume(77, 88);       // ピアノ 音量 : 77 音階 : 88
    piano.play();                   // ピアノがメロディを奏でる 音量 : 77 音階 : 0
    NEWLINE;
    piano.setVolume();
    piano.play();
    NEWLINE;

    Guitar guitar("ギター");
    guitar.play();
    NEWLINE;
    guitar.setVolume(100, 100);
    guitar.play();
}
