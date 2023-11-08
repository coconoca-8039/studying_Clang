// MH-Z19CのPWM出力ピンをArduinoのD2ピンに接続したと仮定します。
int pwmPin = 7;

unsigned long th, tl, ppm;

void setup() {
  Serial.begin(115200); // シリアル通信を開始する
  pinMode(pwmPin, INPUT); // PWMピンを入力として設定
}

void loop() {
  // PWM波形を読み取る
  th = pulseIn(pwmPin, HIGH, 1004000); // HIGHが続く時間（マイクロ秒）
  tl = pulseIn(pwmPin, LOW, 1004000); // LOWが続く時間（マイクロ秒）
  //th = pulseIn(pwmPin, HIGH); // HIGHが続く時間（マイクロ秒）
  //tl = pulseIn(pwmPin, LOW); // LOWが続く時間（マイクロ秒）

  Serial.print("th : ");
  Serial.println(th);
  Serial.print("tl : ");
  Serial.println(tl);
  
  // CO2濃度をppmで計算（MH-Z19Cの仕様に基づく）
  ppm = 5000 * (th - 2 * 1000) / (th + tl - 4 * 1000); 
  Serial.print("ppm : ");
  Serial.println(ppm);

  // 結果をシリアルモニタに表示
  Serial.print("CO2 Concentration is ");
  Serial.print(ppm);
  Serial.println(" ppm");

  // センサーからの次の読み取りまでに1秒待つ
  delay(1000);
}