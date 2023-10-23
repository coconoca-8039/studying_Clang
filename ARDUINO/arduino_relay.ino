// Arduinoでリレーを制御するためのプログラム

int LED_SOCKET = 7;
//int interval_on = 5000;
//int interval_off = 5000;

void setup() {
  pinMode(LED_SOCKET, OUTPUT);
  Serial.begin(9600);  // シリアル通信の開始
}

void loop() {
  digitalWrite(LED_SOCKET, HIGH);   // LEDを点灯
  Serial.println("LED ON");         // "LED ON"とシリアルモニタに出力
  
  for (int i = 0; i < 600; i++) {
    delay(100);
  }

  digitalWrite(LED_SOCKET, LOW);   // LEDを消灯
  Serial.println("LED OFF");        // "LED OFF"とシリアルモニタに出力
  
  for (int i = 0; i < 400; i++) {
    delay(100);
  }
}