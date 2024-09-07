# Payload-Release-System
This is a prototype payload release system that I built using esp32 and sg90 servo to control servo wirelessly using wifi.
(ONLY FOR LoRa V3 Users:

- Use  board = Heltec Wifi LoRa 32 (v3) in Arduino IDE
- Install COM driver for serial connection with LoRa
- USB Driver = SiLabs CP2104 Driver (https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) download either universal windows driver or windows driver
                whatever works for you
- Library= Esp32servo by kevin Harrington
- Baudrate = 115200
- Here is the pinout for the Heltec LoRa V3 Module for reference
  <img width="529" alt="LoRA v3 pin layout" src="https://github.com/user-attachments/assets/6bbee77c-91fa-4b76-a147-01c8d4fec5b6">


  Servo Types:
  You can use any kind of servos as per your need.
  I tested with these two servos, sg90 and MG996R
  ![20240907_005543486_iOS](https://github.com/user-attachments/assets/1c985b1c-6e94-4086-867a-19d592b1eb32)
