#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

// 1. 接続
// BME280のVDDをArduinoの3.3Vに接続します。
// BME280のGNDをArduinoのGNDに接続します。
// BME280のSDI (これはSDAとしても知られています) をArduinoのA4に接続します。
// BME280のSCK (これはSCLとしても知られています) をArduinoのA5に接続します。
// BME280のCSBをArduinoの3.3Vに接続して、I2Cモードを選択します。
// BME280のSDOはI2Cアドレス選択のためのピンです。GNDに接続するとアドレスは0x76、3.3Vに接続するとアドレスは0x77になります。
// あなたのセンサーの設定や他のI2Cデバイスとの競合を避けるために適切なアドレスを選択してください。

Adafruit_BME280 bme; 

void setup() {
  Serial.begin(9600);
  
  if (!bme.begin(0x77)) { // このアドレスはSDOをGNDに接続した場合のものです。SDOを3.3Vに接続した場合は0x77に変更してください。
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
}

void loop() {
  Serial.print("Temperature = ");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  Serial.print("Humidity = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  Serial.println();
  delay(2000); // 2秒待つ
}