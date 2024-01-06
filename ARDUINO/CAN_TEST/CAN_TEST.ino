/***************************************************
*
*MCP2515 CAN Send and Recieve Test
*MCP2515はSPI通信
*BME280はI2C通信 ID:0x77
*QMC5883はI2C通信 ID:0x0D
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
#include <DFRobot_QMC5883.h>  // https://github.com/DFRobot/DFRobot_QMC5883/blob/master/DFRobot_QMC5883.h

// define
#define UPDATE_INTERVAL_1SEC 10  // 送信周期 10で1秒
#define UPDATE_INTERVAL_10SEC 100  // 送信周期 100で10秒

// prototype
void sendCANMessage1Sec();
void sendCANMessage10Sec();
void receiveCANMessage(MCP_CAN& can, unsigned long& id, byte& length, byte* rxBuf);
void modifyCANDataCAN_1234ABCD(byte *CAN_1234ABCD);  
void modifyCANDataCAN_AA1234AA(byte *CAN_AA1234AA);  
void modifyCANDataCAN_CCCC2222(byte *CAN_CCCC2222);  
void modifyCANDataCAN_CCCC4444(byte *CAN_CCCC4444);  
void readBME280Data();
void readQMC5883Data();

// グローバル宣言
// 気温・湿度・気圧
uint16_t globalTempInt = 0;
uint16_t globalHumidInt = 0;
uint16_t globalPressInt = 0;
// XYZ
int16_t globalXAxis = 0;
int16_t globalYAxis = 0;
int16_t globalZAxis = 0;

//構造体で定義したい
unsigned long rxId;
byte len;
byte rxBuf[8];
byte CAN_1234ABCD[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  // 1から9までの数字を順番に動かすだけ
byte CAN_AA1234AA[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  // 気温・湿度・気圧
byte CAN_CCCC2222[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  // XYZセンサ
byte CAN_CCCC4444[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};  // 未定

// インスタンス作成
MCP_CAN CAN0(10);// CAN0 CS: pin 10 送信
MCP_CAN CAN1(9); // CAN1 CS: pin 9 受信
Adafruit_BME280 bme;
DFRobot_QMC5883 compass(&Wire, QMC5883_ADDRESS);

void setup()
{
  Serial.begin(115200);
  Wire.begin();

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
  while (!compass.begin()) {
    Serial.println("Could not find a valid QMC5883 sensor, check wiring!");
    delay(1000);
    yield();
  }
  if (compass.isQMC()) {
    //compass.setRange(QMC5883_RANGE_2GA);
    //compass.setMeasurementMode(QMC5883_CONTINOUS);
    //compass.setDataRate(QMC5883_DATARATE_50HZ);
    //compass.setSamples(QMC5883_SAMPLES_8);
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
      modifyCANDataCAN_1234ABCD(CAN_1234ABCD);
      modifyCANDataCAN_AA1234AA(CAN_AA1234AA);
      readBME280Data();
      modifyCANDataCAN_CCCC4444(CAN_CCCC4444);
      readQMC5883Data();
      // 送信
      sendCANMessage1Sec();
      // テストコード
      }

    if (count % UPDATE_INTERVAL_10SEC == 0){  // 10秒毎
      // 変更・取得 
      modifyCANDataCAN_CCCC2222(CAN_CCCC2222);
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
    // Serial.println("Temperature = " + String(temperature) + " *C");
    // Serial.println("Humidity = " + String(humidity) + " %");
    // Serial.println("Pressure = " + String(pressure) + " hPa");
    Serial.print("temp: ");
    Serial.println(tempInt);
    Serial.print("humi: ");
    Serial.println(humidInt);
    Serial.print("press: ");
    Serial.println(pressInt);
}

void readQMC5883Data(){
    sVector_t magData = compass.readRaw();

    float XAxis = magData.XAxis;
    float YAxis = magData.YAxis;
    float ZAxis = magData.ZAxis;

    globalXAxis = XAxis;
    globalYAxis = YAxis;
    globalZAxis = ZAxis;

    // 磁気データをシリアルモニタに出力
    Serial.print("X: ");
    Serial.print(magData.XAxis);
    Serial.print(" Y: ");
    Serial.print(magData.YAxis);
    Serial.print(" Z: ");
    Serial.println(magData.ZAxis);
}

///////////////////////////////////////////////////////////////////////////////////
// 送信データの変更
void modifyCANDataCAN_1234ABCD(byte *CAN_1234ABCD){
  // 1sec周期で送信
    static int i  = 0;
    CAN_1234ABCD[0] = i;
    i += 1;
    if (i == 10){
      i = 0;
    }
}

void modifyCANDataCAN_AA1234AA(byte *CAN_AA1234AA){
  // 1secで送信
  // Byte1&2 : 気温　Byte3&4 : 湿度　Byte5&6 : 気圧
    // 気温データの格納
    CAN_AA1234AA[0] = globalTempInt >> 8; // 上位バイト
    CAN_AA1234AA[1] = globalTempInt & 0xFF; // 下位バイト

    // 湿度データの格納
    CAN_AA1234AA[2] = globalHumidInt >> 8; // 上位バイト
    CAN_AA1234AA[3] = globalHumidInt & 0xFF; // 下位バイト

    // 気圧データの格納
    CAN_AA1234AA[4] = globalPressInt >> 8; // 上位バイト
    CAN_AA1234AA[5] = globalPressInt & 0xFF; // 下位バイト

    // 残りのバイトはデフォルト値または他のデータで埋める
    CAN_AA1234AA[6] = 0xFF;
    CAN_AA1234AA[7] = 0xFF;
}

void modifyCANDataCAN_CCCC2222(byte *CAN_CCCC2222){
    // 1secで送信
    // Byte1&2 : X方向　Byte3&4 : Y方向　Byte5&6 : Z方向
    // X方向の格納
    CAN_CCCC2222[0] = globalXAxis >> 8;
    CAN_CCCC2222[1] = globalXAxis & 0xFF;

    // Y方向の格納
    CAN_CCCC2222[2] = globalYAxis >> 8;
    CAN_CCCC2222[3] = globalYAxis & 0xFF;

    // Z方向の格納
    CAN_CCCC2222[4] = globalZAxis >> 8;
    CAN_CCCC2222[5] = globalZAxis & 0xFF;

    // 残りのバイトはデフォルト値または他のデータで埋める
    CAN_CCCC2222[6] = 0xFF;
    CAN_CCCC2222[7] = 0xFF;
    ;
}

void modifyCANDataCAN_CCCC4444(byte *CAN_CCCC4444){
  // 10sec
    ;
}

///////////////////////////////////////////////////////////////////////////////////
// 送信処理 1sec
void sendCANMessage1Sec(){
    // 2つ目の引数を0にすると短いIDしか使えなくなるから注意
    CAN0.sendMsgBuf(0x1234ABCD, 1, 8, CAN_1234ABCD);  // 
    CAN0.sendMsgBuf(0xAA1234AA, 1, 8, CAN_AA1234AA);  // 
    CAN0.sendMsgBuf(0xCCCC2222, 1, 8, CAN_CCCC2222);  //
}

// 送信処理 10sec
void sendCANMessage10Sec(){
    // CAN0.sendMsgBuf(0x22BBBBCC, 1, 8, CAN_CCCC4444);
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