// LED1のピン番号を定義
#define LED1 13 

// プロトタイプ宣言
int blink(int pin, int state);
void blink_1sec_led(unsigned char &count, int &state);

void setup(){
    // LED1を出力モードに設定
    pinMode(LED1, OUTPUT);
    Serial.begin(9600);  // シリアル通信の開始
}

void loop(){
    // staticを付けて変数の値を保持します。
    static unsigned char count = 0;
    static unsigned long millis_buf = 0;
    static int state1 = HIGH;

    //　現在の経過時間-この待機処理を通過した時間が1000(ms)になるまで待機
    while ((millis() - millis_buf) < 1000){
        ;
    }
    // 上の待機から抜けた時間を格納
    millis_buf = millis();
    Serial.println(millis_buf);

    //　カウントを取る
    count++;

    // LEDを点灯させる処理
    blink_1sec_led(count, state1);
}

// countの値に応じてLEDを点滅させる関数
void blink_1sec_led(unsigned char &count, int &state){
    if((count % 3) == 0){
      state = blink(LED1, state);
    }
}

int blink(int pin, int state){
    digitalWrite(pin, state);
    return state = HIGH - state;
}