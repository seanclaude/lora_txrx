#include <ESP8266WiFi.h>
#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 5
//#define rst 16
#define rst 15
#define dio0 2

int counter = 0;

void send_packet(void) {
  Serial.print("Sending packet: ");
  Serial.println(counter);

  //Send LoRa packet message to receiver
  LoRa.beginPacket();
  LoRa.print("Ganti BN/GPS");
  LoRa.endPacket();

  counter++;
  //LoRa.sleep();
}

void setup() 
{
  // https://www.instructables.com/id/5-Quirks-of-Using-the-ESP8266/?fbclid=IwAR0MsRAcyEfZBElME0NCyNI_gUJcv2b9OyjSvpPiFQUH4rcUnrmjo5jOPfE
  // turn off wifi AP
  WiFi.mode(WIFI_OFF);
  
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(923E6)) {
    Serial.println(".");
    delay(500);
  }
  LoRa.setSyncWord(0xF8);
  LoRa.enableCrc();
  LoRa.setSpreadingFactor(12);
  //LoRa.dumpRegisters(Serial);
  Serial.println("LoRa Initializing OK!");
  send_packet();
  
  ESP.deepSleep(60e6); // 60e6 is 60 microseconds
}


void loop(){

}