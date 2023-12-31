// LEDのピン番号を定義
#define LED1 30
#define LED2 31
#define LED3 32
#define LED4 33
#define LED5 34
#define LED6 35
#define LED7 36
#define LED8 37
#define MAX_CASE 8  // LEDの最大個数
#define UPDATE_INTERVAL 1  // LEDの点滅周期 10で1秒 100で10秒
#define NUM_LEDS 8  // LEDの数
int ledPins[NUM_LEDS] = {30, 31, 32, 33, 34, 35, 36, 37};
unsigned int currentMinute = 0;  // Start of Timer

// プロトタイプ宣言
void updateCurrentCase(int &currentCase);
void blink_led13(unsigned char &count, int &state);
int blink(int pin, int state);

void setup(){
    // LEDを出力モードに設定
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED4, OUTPUT);
    pinMode(LED5, OUTPUT);
    pinMode(LED6, OUTPUT);
    pinMode(LED7, OUTPUT);
    pinMode(LED8, OUTPUT);
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

    toggleLEDs(currentCase);
}

void updateCurrentCase(int &currentCase) {
    currentCase++;
    if (currentCase > MAX_CASE) {
        currentCase = 0;
    }
}

void toggleLEDs(int currentCase){
    for (int i = 0; i < NUM_LEDS; i++) {
        if (i == currentCase) {
            digitalWrite(ledPins[i], HIGH);  // 点灯
        } else {
            digitalWrite(ledPins[i], LOW);  // 消灯
        }
    }
}
