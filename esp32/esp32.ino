// void setup (){

// }

// void loop(){
    
// }

#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("ESP32test"); // Bluetooth device name
  Serial.println("The device started, now you can pair it with Bluetooth!");
}

void loop() {
  if (Serial.available()) {
    SerialBT.write(Serial.read());
  }
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  }
  delay(20);
}

// int ledpin = 2;

// void setup(){
//     Serial.begin(115200);
//     pinMode(ledpin, OUTPUT);
//     Serial.println("done");

// }
// void loop(){
//     digitalWrite(ledpin,HIGH);
//     Serial.println("LED is ON");
//     delay(1000);

// }
