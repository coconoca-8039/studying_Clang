// const int pwmPin = 2; // PWMピン

// void setup() {
//   Serial.begin(115200);
//   pinMode(pwmPin, INPUT);
// }

// void loop() {
//   unsigned long duration = pulseIn(pwmPin, HIGH);
//   Serial.print("High pulse duration: ");
//   Serial.println(duration);

//   delay(300);
// }

// const int pwmPin = 2; // PWMピン

// void setup() {
//   Serial.begin(115200);
//   pinMode(pwmPin, INPUT);
// }

// void loop() {
//   unsigned long duration = pulseIn(pwmPin, HIGH);
//   Serial.print("High pulse duration: ");
//   Serial.println(duration);
//   int ppm = ((duration - 2 * 1000) * 5000) / (1004 * 1000 - 2 * duration); // この式はMH-Z19CのPWM出力仕様に基づいています。

//   // 濃度を出力する
//   Serial.print("CO2 concentration: ");
//   Serial.print(ppm);
//   Serial.println(" ppm");

//   delay(300); // ここでのディレイはセンサーが次の値を生成するのを待つために使用します。
// }

const int pwmPin = 2; // PWMピン

void setup() {
  Serial.begin(115200);
  pinMode(pwmPin, INPUT);
}

void loop() {
  unsigned long th = pulseIn(pwmPin, HIGH, 2000000); // タイムアウトを2秒に設定
  unsigned long tl = pulseIn(pwmPin, LOW, 2000000);  // タイムアウトを2秒に設定
  
  // エラー確認
  if (th == 0 || tl == 0) {
    Serial.println("Error reading pulse.");
    return; // 次のループまで待つ
  }

  Serial.println(th);
  Serial.println(tl);
  
  // マイクロ秒からミリ秒へ変換
  float th_ms = th / 1000.0;
  float tl_ms = tl / 1000.0;

  // CO2濃度を計算
  float ppm = (5000.0 * (th_ms - 2)) / (th_ms + tl_ms - 4);

  // 濃度を出力する
  Serial.print("CO2 concentration: ");
  Serial.print(ppm);
  Serial.println(" ppm");

  delay(50); // 次の読み取りまで待つ
}
