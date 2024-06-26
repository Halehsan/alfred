#include <SoftwareSerial.h>

// Bluetooth module connection
SoftwareSerial Bluetooth(10, 11); // RX, TX

// Motor A connections- right
// int enA = 5;
const int in1 = 7;
const int in2 = 6;

// Motor B connections- left
// int enB = 10;
const int in4 = 9;
const int in3 = 8;


void setup() {

  initialize_motors();
  motor_function(0,0);
  run_motor_sequence();

// Initialize Bluetooth communication
  Bluetooth.begin(9600);
  Serial.begin(9600); // For debugging
  Serial.println("Initializing...");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void initialize_motors() {

  // Set all the motor control pins to output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // pinMode(enA, OUTPUT);
  // pinMode(enB, OUTPUT);

  // stop
  motor_function(0, 0);


}


void run_motor_sequence() {

  // Example movement commands using the motor_function
  int left_speed = 150;
  int right_speed = 150;
  int time = 1000;
  // forward
  motor_function(left_speed,right_speed);
  delay(time);
  //stop
  motor_function(0, 0); 
  delay(time);
  // backward
  motor_function(-left_speed,-right_speed);  
  delay(time);
  //turn left
  motor_function(-left_speed, right_speed);  
  delay(time);
  //stop
  motor_function(0, 0);  // Stop all motors
  delay(time);
  // turn right
  motor_function(left_speed, -right_speed);  
  delay(time);

  motor_function(0, 0);  // Stop all motors
}


void motor_function(int left_speed, int right_speed) {

    
  // analogWrite(enB, abs(left_speed));
  // analogWrite(enA, abs(right_speed));

  // A - left side 
  
  if (left_speed > 0) {

    analogWrite(in3, left_speed);
    digitalWrite(in4, LOW);

  } else if (left_speed < 0) {
    
    digitalWrite(in3, LOW);
    analogWrite(in4, left_speed);
  } else {

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  
  void bluetooth_command(char command) {

  switch (command) {
    case 'F': // Move forward
      motor_function(left_speed, right_speed);
      break;
    case 'B': // Move backward
      motor_function(-left_speed, -right_speed);
      break;
    case 'L': // Turn left
      motor_function(-left_speed, right_speed);
      break;
    case 'R': // Turn right
      motor_function(left_speed, -right_speed);
      break;
    case 'S': // Stop
      motor_function(0, 0);
      break;
    case 'Q': // Execute sequence
      runMotorSequence();
      break;

  }

  // B - right side 

  if (right_speed > 0) {
    // Forward
    analogWrite(in1, right_speed);
    digitalWrite(in2, LOW);

  } else if (right_speed < 0) {
    // Backward
    analogWrite(in2, right_speed);
    digitalWrite(in1, LOW);

  } else {
    // Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

  }

 
}




void loop() {

    while  (Serial.available() > 0)

       if (Bluetooth.available()) {

            char command = Bluetooth.read();


            bluetooth_command(command);
   }
   
}
