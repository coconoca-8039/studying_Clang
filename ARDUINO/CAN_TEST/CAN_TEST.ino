/***************************************************
*
*MCP2515 CAN Send and Recieve Test
*MCP2515はSPI通信
*BME280はI2C通信
*QMC5883はI2C通信
*
***************************************************/

// include
#include <mcp_can.h> // https://github.com/coryjfowler/MCP_CAN_lib
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
// #include "modifyCANData.h"
// #include "modifyCANData.cpp"
#include <DFRobot_QMC5883.h>

// define
#define UPDATE_INTERVAL_1SEC 10  // 送信周期 10で1秒
#define UPDATE_INTERVAL_10SEC 100  // 送信周期 100で10秒

// prototype
void sendCANMessage1Sec();
void sendCANMessage10Sec();
void receiveCANMessage(MCP_CAN& can, unsigned long& id, byte& length, byte* rxBuf);
void modifyCANDatatxBuf0(byte *txBuf0);
void modifyCANDatatxBuf1(byte *txBuf1);
void modifyCANDatatxBuf2(byte *txBuf2);
void modifyCANDatatxBuf3(byte *txBuf3);
void readBME280Data();

// グローバル宣言
uint16_t globalTempInt = 0;
uint16_t globalHumidInt = 0;
uint16_t globalPressInt = 0;

//構造体で定義したい
unsigned long rxId;
byte len;
byte rxBuf[8];
byte txBuf0[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
byte txBuf1[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
byte txBuf2[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
byte txBuf3[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// インスタンス作成
MCP_CAN CAN0(10);// CAN0 CS: pin 10
MCP_CAN CAN1(9); // CAN1 CS: pin 9
Adafruit_BME280 bme;
DFRobot_QMC5883 compass(&Wire, QMC5883_ADDRESS);

void setup()
{
  Serial.begin(115200);

  // init CAN0 bus, baudrate: 250kbps@8MHz
  if(CAN0.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK){
    Serial.println("CAN0: Init OK!");
    CAN0.setMode(MCP_NORMAL);
  } else{ 
    Serial.println("CAN0: Init Fail!");
  }

  // init CAN1 bus, baudrate: 250kbps@8MHz
  if(CAN1.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK){
    Serial.println("CAN1: Init OK!");
    CAN1.setMode(MCP_NORMAL);
  }else{ 
    Serial.println("CAN1: Init Fail!");
  }

  // init BME280
  if (!bme.begin(0x77)) { // このアドレスはSDOをGNDに接続した場合のもの。SDOを3.3Vに接続した場合は0x77に変更すること
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1);
  }
  Serial.println("BME280: Init OK!");

  // init QMC5880
  while (!compass.begin()){
    Serial.println("Could not find a valid 5883 sensor, check wiring!");
  }
  if(compass.isHMC()){
    Serial.println("HMC5883: Init OK!");
  }else if(compass.isQMC()){
    Serial.println("IQMC5883: Init OK!");
  }else if(compass.isVCM()){
    Serial.println("VCM5883L: INit OK!");
  }

}

void loop(){

  static unsigned char count = 0;
  static unsigned long millis_buf = 0;

  //100ミリ秒経過したら次の処理に移行する
    while ((millis() - millis_buf) < 100){
        ;
    }
    millis_buf = millis();
    count++;

    // 割り切れる時に処理を実行
    if (count % UPDATE_INTERVAL_1SEC == 0){  // 1秒毎
      // 変更・取得
      modifyCANDatatxBuf0(txBuf0);
      modifyCANDatatxBuf1(txBuf1);
      readBME280Data();
      // 送信
      sendCANMessage1Sec();
      }
    if (count % UPDATE_INTERVAL_10SEC == 0){  // 10秒毎
      // 変更・取得 
      modifyCANDatatxBuf2(txBuf2);
      modifyCANDatatxBuf3(txBuf3);
      // 送信
      sendCANMessage10Sec();
      }

  receiveCANMessage(CAN1, rxId, len, rxBuf);

}

///////////////////////////////////////////////////////////////////////////////////
// データの取得
void readBME280Data(){
    float temperature = 0;
    float humidity = 0;
    float pressure = 0;

    temperature = bme.readTemperature();
    humidity = bme.readHumidity();
    pressure = bme.readPressure() / 100.0F;

    uint16_t tempInt = (int16_t)(temperature * 100); // 気温を100倍して整数に
    uint16_t humidInt = (int16_t)(humidity * 100); // 湿度を100倍して整数に
    uint16_t pressInt = (int16_t)(pressure); // 気圧をそのまま整数に（精度要検討）

    globalTempInt = tempInt;
    globalHumidInt = humidInt;
    globalPressInt = pressInt;

    // 確認用に残しておく
    Serial.println("Temperature = " + String(temperature) + " *C");
    Serial.println("Humidity = " + String(humidity) + " %");
    Serial.println("Pressure = " + String(pressure) + " hPa");
    // Serial.println(tempInt);
    // Serial.println(humidInt);
    // Serial.println(pressInt);
}

///////////////////////////////////////////////////////////////////////////////////
// 送信データの変更
void modifyCANDatatxBuf0(byte *txBuf0){
  // 1sec
    static int i  = 0;
    txBuf0[0] = i;
    i += 1;
    if (i == 10){
      i = 0;
    }
}

void modifyCANDatatxBuf1(byte *txBuf1){
  // 1sec
  // Byte1&2 : 気温　Byte3&4 : 湿度　Byte5&6 : 気圧
    // 気温データの格納
    txBuf1[0] = globalTempInt >> 8; // 上位バイト
    txBuf1[1] = globalTempInt & 0xFF; // 下位バイト

    // 湿度データの格納
    txBuf1[2] = globalHumidInt >> 8; // 上位バイト
    txBuf1[3] = globalHumidInt & 0xFF; // 下位バイト

    // 気圧データの格納
    txBuf1[4] = globalPressInt >> 8; // 上位バイト
    txBuf1[5] = globalPressInt & 0xFF; // 下位バイト

    // 残りのバイトはデフォルト値または他のデータで埋める
    txBuf1[6] = 0xFF;
    txBuf1[7] = 0xFF;
    ;
}

void modifyCANDatatxBuf2(byte *txBuf2){
  // 10sec
    ;
}

void modifyCANDatatxBuf3(byte *txBuf3){
  // 10sec
    ;
}

///////////////////////////////////////////////////////////////////////////////////
// 送信処理 1sec
void sendCANMessage1Sec(){
    // 2つ目の引数を0にすると短いIDしか使えなくなるから注意
    CAN0.sendMsgBuf(0x1234ABCD, 1, 8, txBuf0);  // 
    CAN0.sendMsgBuf(0xAA1234AA, 1, 8, txBuf1);  // 
}

// 送信処理 10sec
void sendCANMessage10Sec(){
    // CAN0.sendMsgBuf(0x11AAAABB, 1, 8, txBuf2);
    // CAN0.sendMsgBuf(0x22BBBBCC, 1, 8, txBuf3);
}

///////////////////////////////////////////////////////////////////////////////////
// 受信処理
void receiveCANMessage(MCP_CAN &can, unsigned long &id, byte &length, byte *rxBuf) {
    if(can.checkReceive() == CAN_MSGAVAIL){
    can.readMsgBuf(&id, &length, rxBuf);

    // 最上位ビットを強制的に0に設定
    // 32ビットのうち最上位の3ビットをアンド演算でクリア
    id &= 0x1FFFFFFF;

    Serial.print("Receive ID: ");
    Serial.print(id, HEX);
    Serial.print(" Data: ");
    for(byte i = 0; i < length; i++){
      Serial.print(rxBuf[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
  }
}
