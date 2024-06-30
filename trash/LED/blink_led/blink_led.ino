// LED1のピン番号を定義
#define LED1 13 

void setup(){
    // LED1を出力モードに設定
    pinMode(LED1, OUTPUT);
}

void loop(){
    static int state1 = HIGH; // LEDの初期状態を点灯とする
    state1 = blink(LED1, state1); // LEDの状態を切り替える
    delay(1000); // 1秒待機
}

int blink(int pin, int state){
    digitalWrite(pin, state); // LEDの状態を設定
    return state = HIGH - state; // 現在の状態から逆の状態に変更して返す
}