# Payload-Release-System
This is a prototype payload release system that I built using esp32 and sg90 servo to control servo wirelessly using wifi.

[[(ONLY FOR LoRa V3 Users:

- Use  board = Heltec Wifi LoRa 32 (v3) in Arduino IDE
- Install COM driver for serial connection with LoRa
- USB Driver = SiLabs CP2104 Driver (https://www.silabs.com/developers/usb-to-uart-bridge-vcp-drivers?tab=downloads) download either universal windows driver or windows driver
                whatever works for you
- Library= Esp32servo by kevin Harrington
- Baudrate = 115200
- Here is the pinout for the Heltec LoRa V3 Module for reference]]
  <img width="529" alt="LoRA v3 pin layout" src="https://github.com/user-attachments/assets/6bbee77c-91fa-4b76-a147-01c8d4fec5b6">


For regular Esp32 Users:


  Servo Types:

  You can use any kind of servos as per your need.
  I tested with these two servos, sg90 and MG996R
 ![20240907_005543486_iOS](https://github.com/user-attachments/assets/07b70fb5-1ed6-4252-b21d-158f8d1a8e8f)

Hook:

I made this custom hook and attached a velcro. The other side of velcro can to attached to the drone or other parts. If the payload is heavy and you are using the big servo, the velcro can be replaced with hooks depends on your need.
![20240907_005604495_iOS](https://github.com/user-attachments/assets/62d6101d-ca7f-457e-9cb1-ef2c6e1cc8af)


Esp32:

Make sure to install esp32 servo library and use it while working with the esp32 wifi and servos.


Working Mechanism:

The servo motor in this project is controlled wirelessly using an ESP32 microcontroller connected to a Wi-Fi network. The ESP32 hosts a web server that serves a web page with a slider interface to the user. When the user accesses this web page through a browser on any device connected to the same Wi-Fi network, they can move the slider to set the servo motor's position. This change in slider value triggers a JavaScript function that sends an HTTP request to the ESP32, passing the new servo position as a parameter. The ESP32 receives this request and processes it in the handleSetServo() function, which reads the position value, validates it, and then adjusts the servo motor accordingly using the myservo.write(position) command. By hosting the web interface, the ESP32 allows for remote control of the servo motor wirelessly, enabling the user to interact with the hardware from any device with network access.







