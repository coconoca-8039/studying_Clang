/*
このファイルはCAN_ALIVE.inoとGPS_CATCH.inoを組み合わせたもの
Serial Monitorが9600であることに注意すること

Satellites:         8                          衛星の補足数
HDOP:               1.3                        水平精度低下率
Latitude:           38.xxxxxx                  緯度
Longitude:          140.xxxxxx                 軽度
Location Age:       1049                       最終更新タイミング[msec]
Date & Time:        02/18/2024 19:52:06 1070   時刻
Altitude:           214.90                     標高
Course:             27.00                      移動方向
Speed:              0.57                       速度
Course Cardinal:    NNE                        北（N）東（E）南（S）西（W）
Distance to Tokyo:  xxx                        目標座標との距離
Course to Tokyo:    xxx.xx                     目標座標との角度
Cardinal to Tokyo:  SSW                        目標座標との角度

1777DDDD
1888DDDD
*/

#include <TinyGPSPlus.h>
#include <SoftwareSerial.h>
#include <mcp_can.h>
#include <SPI.h>
#include <Wire.h>

// define
#define UPDATE_INTERVAL_1SEC 10  // 送信周期 10で1秒
#define UPDATE_INTERVAL_10SEC 100  // 送信周期 100で10秒

// prototype

//基本情報
unsigned long rxId;
byte len;
byte rxBuf[8];
byte CAN_1777DDDD[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};
byte CAN_1888DDDD[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;

// インスタンス作成
MCP_CAN CAN2(10);// CAN0 CS: pin 10 送信
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup() {
  Serial.begin(9600);
  ss.begin(GPSBaud);
  Wire.begin();

  Serial.println(F("GPS Data:"));
  Serial.println(F("---------"));

  // init CAN2 bus, baudrate: 250kbps@8MHz
  if(CAN2.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK){
    Serial.println("CAN2: Init OK!");
    CAN2.setMode(MCP_NORMAL);
  } else{ 
    Serial.println("CAN2: Init Fail!");
  }

  Serial.println("");

}

void loop() {
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
      modifyCANDataCAN_1777DDDD(CAN_1777DDDD);
      // modifyCANDataCAN_1888DDDD(CAN_1888DDDD);
      
      // 送信
      sendCANMessage1Sec();
      // テストコード
      }

    if (count % UPDATE_INTERVAL_10SEC == 0){  // 10秒毎
      // 変更・取得 
      // modifyCANDataCAN_1777DDDD(CAN_1777DDDD);
      // 送信
      sendCANMessage10Sec();
      }

  receiveCANMessage(CAN2, rxId, len, rxBuf);

}

static void smartDelay(unsigned long ms) {
  unsigned long start = millis();
  do {
    while (ss.available())
      gps.encode(ss.read());
  } while (millis() - start < ms);
}

static void printFloat(float val, bool valid, int len, int prec) {
  if (!valid) {
    while (len-- > 1)
      Serial.print('*');
    Serial.print(' ');
  } else {
    Serial.print(val, prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1);
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i = flen; i < len; ++i)
      Serial.print(' ');
  }
  smartDelay(0);
}

static void printInt(unsigned long val, bool valid, int len) {
  char sz[32] = "*****************";
  if (valid)
    sprintf(sz, "%ld", val);
  sz[len] = 0;
  for (int i = strlen(sz); i < len; ++i)
    sz[i] = ' ';
  if (len > 0)
    sz[len - 1] = ' ';
  Serial.print(sz);
  smartDelay(0);
}

static void printDateTime(TinyGPSDate &d, TinyGPSTime &t) {
  if (!d.isValid()) {
    Serial.print(F("********** "));
  } else {
    char sz[32];
    sprintf(sz, "%02d/%02d/%02d ", d.month(), d.day(), d.year());
    Serial.print(sz);
  }

  if (!t.isValid()) {
    Serial.print(F("******** "));
  } else {
    char sz[32];
    int hour = t.hour() + 9;
    if (hour >= 24) hour -= 24;
    sprintf(sz, "%02d:%02d:%02d ", hour, t.minute(), t.second());
    Serial.print(sz);
  }

  printInt(d.age(), d.isValid(), 5);
  smartDelay(0);
}

static void printStr(const char *str, int len) {
  int slen = strlen(str);
  for (int i = 0; i < len; ++i)
    Serial.print(i < slen ? str[i] : ' ');
  smartDelay(0);
}

///////////////////////////////////////////////////////////////////////////////////
// 送信データの変更
void modifyCANDataCAN_1777DDDD(byte *CAN_1777DDDD){
  // 1sec周期で送信
  // Serial.print(F("Satellites:      "));
  // printInt(gps.satellites.value(), gps.satellites.isValid(), 5);
  // Serial.println(F(" (Number of satellites in view)"));

  // Serial.print(F("HDOP:            "));
  // printFloat(gps.hdop.hdop(), gps.hdop.isValid(), 6, 1);
  // Serial.println(F(" (Horizontal Dilution of Precision)"));

  // 
  // Serial.print(F("Latitude:        "));
  // printFloat(gps.location.lat(), gps.location.isValid(), 11, 6);
  // Serial.println(F(" (Latitude in degrees)"));

  // 
  Serial.print(F("Longitude:       "));
  printFloat(gps.location.lng(), gps.location.isValid(), 12, 6);
  Serial.println(F(" (Longitude in degrees)"));
  double latitude = gps.location.lng();
  uint32_t latitude_value = static_cast<uint32_t>(latitude * 1000000);

  CAN_1777DDDD[0] = (latitude_value >> 24) & 0xFF; // 上位バイト
  CAN_1777DDDD[1] = (latitude_value >> 16) & 0xFF; // 次のバイト
  CAN_1777DDDD[2] = (latitude_value >> 8) & 0xFF;  // 次のバイト
  CAN_1777DDDD[3] = latitude_value & 0xFF;         // 下位バイト

  // Serial.print(F("Location Age:    "));
  // printInt(gps.location.age(), gps.location.isValid(), 5);
  // Serial.println(F(" (Time since last GPS fix in milliseconds)"));

  // Serial.print(F("Date & Time:     "));
  // printDateTime(gps.date, gps.time);
  // Serial.println(F(" (Date and time of last GPS fix)"));

  // 
  // Serial.print(F("Altitude:        "));
  // printFloat(gps.altitude.meters(), gps.altitude.isValid(), 7, 2);
  // Serial.println(F(" (Altitude in meters)"));

  // Serial.print(F("Course:          "));
  // printFloat(gps.course.deg(), gps.course.isValid(), 7, 2);
  // Serial.println(F(" (Course in degrees)"));

  // Serial.print(F("Speed:           "));
  // printFloat(gps.speed.kmph(), gps.speed.isValid(), 6, 2);
  // Serial.println(F(" (Speed in km/h)"));

  // Serial.print(F("Course Cardinal: "));
  // printStr(gps.course.isValid() ? TinyGPSPlus::cardinal(gps.course.deg()) : "*** ", 6);
  // Serial.println(F(" (Cardinal direction of course)"));

  // Serial.println();

  // 東京都庁との距離と方角を計算して表示
  static const double TOKYO_LAT = 35.6895, TOKYO_LON = 139.6917;
  unsigned long distanceKmToTokyo =
  (unsigned long)TinyGPSPlus::distanceBetween(
    gps.location.lat(),
    gps.location.lng(),
    TOKYO_LAT, 
    TOKYO_LON) / 1000;
  // Serial.print(F("Distance to Tokyo: "));
  // printInt(distanceKmToTokyo, gps.location.isValid(), 9);
  // Serial.println(F(" km"));

  double courseToTokyo =
  TinyGPSPlus::courseTo(
    gps.location.lat(),
    gps.location.lng(),
    TOKYO_LAT, 
    TOKYO_LON);
  // Serial.print(F("Course to Tokyo: "));
  // printFloat(courseToTokyo, gps.location.isValid(), 7, 2);
  // Serial.println(F(" degrees"));

  const char *cardinalToTokyo = TinyGPSPlus::cardinal(courseToTokyo);
  // Serial.print(F("Cardinal to Tokyo: "));
  // printStr(gps.location.isValid() ? cardinalToTokyo : "*** ", 6);
  // Serial.println();

  // Serial.println();
  // smartDelay(4000);

  // if (millis() > 5000 && gps.charsProcessed() < 10)
    // Serial.println(F("No GPS data received: check wiring"));
}

void modifyCANDataCAN_1888DDDD(byte *CAN_1888DDDD){
  // 1sec周期で送信
    static int i  = 0;
    CAN_1888DDDD[0] = i;
    i += 1;
    if (i == 99){
      i = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////
// 送信処理 1sec
void sendCANMessage1Sec(){
    CAN2.sendMsgBuf(0x1777DDDD, 1, 8, CAN_1777DDDD);
    //CAN2.sendMsgBuf(0x1888DDDD, 1, 8, CAN_1888DDDD);
}

// 送信処理 10sec
void sendCANMessage10Sec(){
    //CAN2.sendMsgBuf(0x1777DDDD, 1, 8, CAN_1777DDDD);
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

