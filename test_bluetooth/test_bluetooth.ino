// #include <SoftwareSerial.h>

// //Create software serial object to communicate with HC-05
// SoftwareSerial mySerial(3, 2); //HC-05 Tx & Rx is connected to Arduino #3 & #2

// void setup()
// {
//   //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
//   Serial.begin(9600);
  
//   //Begin serial communication with Arduino and HC-05
//   mySerial.begin(9600);

//   Serial.println("Initializing...");
//   Serial.println("The device started, now you can pair it with bluetooth!");
// }

// void loop()
// {
//   if(Serial.available()) 
//   {
//     mySerial.write(Serial.read());//Forward what Serial received to Software Serial Port
//   }
//   if(mySerial.available()) 
//   {
//     Serial.write(mySerial.read());//Forward what Software Serial received to Serial Port
//   }
//   delay(20);
// }
#include <SoftwareSerial.h>

// ledPins
constexpr int  ledPin = 13; 

SoftwareSerial BTSerial(2, 3); // RX, TX

void setup() {

  pinMode(ledPin, OUTPUT);

  Serial.begin(9600);

  BTSerial.begin(9600);

  digitalWrite(ledPin, LOW);
}

void loop() {

  if (BTSerial.available()) {
    char command = BTSerial.read();

    Serial.println(command);

    switch (command) {
      case '1': 
        digitalWrite(ledPin, HIGH);
        break;
      case '0': 
        digitalWrite(ledPin, LOW);
        break;
      default:
        break;
    }
  }
}
