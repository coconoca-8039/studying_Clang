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

// define
#define UPDATE_INTERVAL_1SEC 10  // 送信周期 10で1秒
#define UPDATE_INTERVAL_10SEC 100  // 送信周期 100で10秒

// prototype
void sendCANMessage1Sec();
void sendCANMessage10Sec();
void receiveCANMessage(MCP_CAN& can, unsigned long& id, byte& length, byte* rxBuf);
// void modifyCANDataCAN_1234ABCD(byte *CAN_1234ABCD);  
// void modifyCANDataCAN_AA1234AA(byte *CAN_AA1234AA);  
// void modifyCANDataCAN_CCCC2222(byte *CAN_CCCC2222);  
// void modifyCANDataCAN_CCCC4444(byte *CAN_CCCC4444);  

//基本情報
unsigned long rxId;
byte len;
byte rxBuf[8];
byte CAN_7777DDDD[] = {0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF};

// インスタンス作成
MCP_CAN CAN2(10);// CAN0 CS: pin 10 送信

void setup()
{
  Serial.begin(115200);
  Wire.begin();

  // init CAN2 bus, baudrate: 250kbps@8MHz
  if(CAN2.begin(MCP_ANY, CAN_250KBPS, MCP_8MHZ) == CAN_OK){
    Serial.println("CAN2: Init OK!");
    CAN2.setMode(MCP_NORMAL);
  } else{ 
    Serial.println("CAN2: Init Fail!");
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
      modifyCANDataCAN_7777DDDD(CAN_7777DDDD);
      // 送信
      sendCANMessage1Sec();
      // テストコード
      }

    if (count % UPDATE_INTERVAL_10SEC == 0){  // 10秒毎
      // 変更・取得 
      
      // 送信
      sendCANMessage10Sec();
      }

  receiveCANMessage(CAN2, rxId, len, rxBuf);

}

///////////////////////////////////////////////////////////////////////////////////
// 送信データの変更
void modifyCANDataCAN_7777DDDD(byte *CAN_7777DDDD){
  // 1sec周期で送信
    static int i  = 0;
    CAN_7777DDDD[0] = i;
    i += 1;
    if (i == 99){
      i = 0;
    }
}

///////////////////////////////////////////////////////////////////////////////////
// 送信処理 1sec
void sendCANMessage1Sec(){
    CAN2.sendMsgBuf(0x7777DDDD, 1, 8, CAN_7777DDDD);  // 
}

// 送信処理 10sec
void sendCANMessage10Sec(){
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