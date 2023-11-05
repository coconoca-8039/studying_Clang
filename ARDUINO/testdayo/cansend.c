#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_BME280.h>
#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN(9);  // CANモジュールのCSピン

Adafruit_BME280 bme; // BME280センサオブジェクトの初期化

typedef struct {
    unsigned char data[8];
    unsigned long lastSentTimestamp;
    unsigned long sendInterval;
    unsigned long canId; // 29ビットのCAN IDを格納
} DataPacket;

DataPacket dataPackets[] = {
    {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0, 1000, 0x18FFFFFF},  // data1
    {{0x00, 0xFF, 0x22, 0xAA, 0x44, 0xBB, 0x66, 0xCC}, 0, 1000, 0x18FFFFFE},  // data2
    {{0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}, 0, 1000, 0x18FFFFFD}   // data3
};

void setup() {
    Serial.begin(115200);
    Wire.begin();

/*
    if (!bme.begin(0x76)) {  // BME280の初期化
        Serial.println("Could not find a valid BME280 sensor, check wiring!");
        while (1);
    }
*/

    if (CAN.begin(MCP_ANY, CAN_500KBPS, MCP_8MHZ) == CAN_OK) {
        Serial.println("CAN Init OK");
    } else {
        Serial.println("CAN Init Failed");
    }

    for (int i = 0; i < sizeof(dataPackets) / sizeof(DataPacket); i++) {
        dataPackets[i].lastSentTimestamp = millis();
    }
}

void incrementData1Byte1() {
    //dataPackets[0].data[0] = (dataPackets[0].data[0] + 1) % 0x100;
}

void incrementData2Byte1() {
    //dataPackets[1].data[1] = (dataPackets[1].data[1] + 1) % 0x100;
}

void readBME280Data() {
    int temperature = bme.readTemperature(); // Celsius
    int humidity = bme.readHumidity(); // %
    long pressure = bme.readPressure() / 100.0F; // hPa

    dataPackets[2].data[0] = temperature;
    dataPackets[2].data[1] = humidity;
    dataPackets[2].data[2] = pressure & 0xFF; // 下位バイト
    dataPackets[2].data[3] = (pressure >> 8) & 0xFF; // 上位バイト
}

void loop() {
    unsigned long currentMillis = millis();

    //readBME280Data();  // BME280からデータを読み取る

    for (int i = 0; i < sizeof(dataPackets) / sizeof(DataPacket); i++) {
        if (currentMillis - dataPackets[i].lastSentTimestamp >= dataPackets[i].sendInterval) {
            if (i == 0) {
                incrementData1Byte1();
            }
            if (i == 1) {
                incrementData2Byte1();
            }
            
            CAN.sendMsgBuf(dataPackets[i].canId, 0, 8, dataPackets[i].data);  // CANデータの送信
            Serial.println("Data sent!");
            dataPackets[i].lastSentTimestamp = currentMillis;
        }
    }
}