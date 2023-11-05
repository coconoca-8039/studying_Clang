/***************************************************
*
*MCP2515 CAN Send and Recieve Test
*
***************************************************/

// include
#include <mcp_can.h> //https://github.com/coryjfowler/MCP_CAN_lib
#include <SPI.h>

// define
#define UPDATE_INTERVAL_1SEC 10  // 送信周期 10で1秒
#define UPDATE_INTERVAL_10SEC 100  // 送信周期 100で10秒

// prototype
void sendCANMessage();
void receiveCANMessage(MCP_CAN& can, unsigned long& id, byte& length, byte* rxBuf);

//構造体で定義したい
unsigned long rxId;
byte len;
byte rxBuf[8];
byte txBuf0[] = {0xA1,0xA2,0xA3,0xCB,0xB5,0xB6,0xA7,0xA8};
byte txBuf1[] = {0xAA,0xEE,0xfd,0xfc,0xfb,0xfa,0xf9,0xf8};

// インスタンス作成
MCP_CAN CAN0(10);// CAN0 CS: pin 10
MCP_CAN CAN1(9); // CAN1 CS: pin 9

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
    // Serial.println(millis_buf);

    // 割り切れる時に処理を実行
    if (count % UPDATE_INTERVAL_1SEC == 0) {
        sendCANMessage();
    }

  receiveCANMessage(CAN1, rxId, len, rxBuf);

}

// 送信処理
void sendCANMessage(){
    CAN0.sendMsgBuf(0x100, 0, 8, txBuf0);
    CAN0.sendMsgBuf(0x101, 0, 8, txBuf1);
    // Serial.println("Send ID: 0x100,0X101");
}

// 受信処理
void receiveCANMessage(MCP_CAN &can, unsigned long &id, byte &length, byte *rxBuf) {
  if(can.checkReceive() == CAN_MSGAVAIL){
    can.readMsgBuf(&id, &length, rxBuf);
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
