// LEDのピン番号を定義
#define LED1 3
#define LED2 5
#define LED3 6
#define LED4 13
#define MAX_CASE 3  // LEDの最大個数
#define UPDATE_INTERVAL 10  // LEDの点滅周期 10で1秒 100で10秒

#define NUM_LEDS 3  // LEDの数
int ledPins[NUM_LEDS] = {3, 5, 6};

// プロトタイプ宣言
void cycleLEDs(int currentCase);
void updateCurrentCase(int &currentCase);
void blink_led13(unsigned char &count, int &state);
int blink(int pin, int state);

void setup(){
    // LEDを出力モードに設定
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    Serial.begin(9600);
}

void loop(){
    // staticを付けて変数の値を保持
    static unsigned char count = 0;
    static unsigned long millis_buf = 0;
    static int currentCase = 0;
    static int state = HIGH;

    //100ミリ秒経過したら次の処理に移行する

    while ((millis() - millis_buf) < 100){
        ;
    }
    millis_buf = millis();
    Serial.println(millis_buf);

    count++;

    if (count % UPDATE_INTERVAL == 0) {
        updateCurrentCase(currentCase);
    }

    //cycleLEDs(currentCase);  // LED3つの制御
    toggleLEDs(currentCase);
    blink_led13(count, state);
}

void updateCurrentCase(int &currentCase) {
    currentCase++;
    if (currentCase > MAX_CASE) {
        currentCase = 0;
    }
}

// void cycleLEDs(int currentCase){
//    switch(currentCase){
//         case 0:
//             digitalWrite(LED1, HIGH);
//             digitalWrite(LED2, LOW);
//             digitalWrite(LED3, LOW);
//             break;
//         case 1:
//             digitalWrite(LED1, LOW);
//             digitalWrite(LED2, HIGH);
//             digitalWrite(LED3, LOW);
//             break;
//         case 2:
//             digitalWrite(LED1, LOW);
//             digitalWrite(LED2, LOW);
//             digitalWrite(LED3, HIGH);
//             break;
//     } 
// }

void toggleLEDs(int currentCase){
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i == currentCase) {
            digitalWrite(ledPins[i], HIGH);  // 点灯
        } else {
            digitalWrite(ledPins[i], LOW);  // 消灯
        }
    }
}

void blink_led13(unsigned char &count, int &state){
    if((count % UPDATE_INTERVAL) == 0){
      state = blink(LED4, state);
    }
}

int blink(int pin, int state){
    digitalWrite(pin, state);
    return state = HIGH - state;
}