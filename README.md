# lora_txrx
Simple lora transmitter and receiver based on RFM95 and ESP8266.

This project demonstrates how the ESP8266 can be used in conjunction with the RFM95 lora transceiver to transmit and receive arbitary messages from one device to another.

The transmitter transmits a specific message after which it enters deep sleep mode. On waking from deep sleep, the same message is retransmitted.

The receiver is set to receive message from the transmitter by setting the same sync word (default: 0xF8). 

A SSD1306 OLED display is used to display various parameters and the message when received. Dickbutt is shown as an alternative to the Adafruit display initialisation image. 

## Dependencies
### Required dependencies
- Arduino library for sending and receiving data using LoRa radios, [arduino-LoRa](https://github.com/sandeepmistry/arduino-LoRa)

### Optional dependencies
 - Arduino library for SSD1306 monochrome 128x64 and 128x32 OLEDs,  [Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)
 - Adafruit GFX graphics core library, [Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)


