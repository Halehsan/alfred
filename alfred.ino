#include <SoftwareSerial.h>

// Bluetooth module connection
SoftwareSerial Bluetooth(3, 2); // RX, TX

// Motor A connections - right
const int in1_A= 8;
const int in2_A = 3;
const int in3_B = 4;
const int in4_B = 5;



// Motor B connections - left
const int in1_C = 12;
const int in2_C= 6;
const int in3_D = 13;
const int in4_D = 9;

// Motor speeds and delay time
const int A_speed = 100;
const int B_speed = 100;
const int C_speed = 100;
const int D_speed = 100;

const int time_delay = 1000;

void setup() {
  // Initialize the motors and Bluetooth communication
  initialize_motors();
  motor_function(0, 0,0,0); 
  Bluetooth.begin(9600);
  Serial.begin(9600); 
}

void initialize_motors() {
  // Set all the motor control pins to output
  pinMode(in1_A, OUTPUT);
  pinMode(in2_A, OUTPUT);
  pinMode(in3_B, OUTPUT);
  pinMode(in4_B, OUTPUT);
  
  pinMode(in1_C, OUTPUT);
  pinMode(in2_C, OUTPUT);
  pinMode(in3_D, OUTPUT);
  pinMode(in4_D, OUTPUT);

  // Stop all motors initially
  motor_function(0, 0,0,0);
}

void run_motor_sequence() {
  // Example movement commands using the motor_function

  motor_function(A_speed, B_speed, C_speed,D_speed);// Forward
  delay(time_delay);
  motor_function(0, 0, 0, 0); // Stop
  delay(time_delay);
  motor_function(-A_speed, -B_speed, -C_speed, -D_speed); // Backward
  delay(time_delay);
  motor_function(-A_speed, B_speed, -C_speed, D_speed); // Turn left
  delay(time_delay);
  motor_function(0, 0, 0, 0); // StopS
  delay(time_delay);
  motor_function(A_speed, -B_speed, C_speed, -D_speed); // Turn right
  delay(time_delay);
  motor_function(0, 0, 0, 0); // Stop
}


void motor_function(int A_speed, int B_speed, int C_speed, int D_speed) {
  // A 
  if (A_speed > 0) {
    analogWrite(in1_A, A_speed);
    digitalWrite(in2_A, LOW);
  } else if (A_speed < 0) {
    digitalWrite(in1_A, LOW);
    analogWrite(in2_A, -A_speed);
  } else {
    digitalWrite(in1_A, LOW);
    digitalWrite(in2_A, LOW);
  }
  
  // B 
  if (B_speed > 0) {
    analogWrite(in3_B, B_speed);
    digitalWrite(in4_B, LOW);
  } else if (B_speed < 0) {
    analogWrite(in3_B, -B_speed);
    digitalWrite(in4_B, LOW);
  } else {
    digitalWrite(in3_B, LOW);
    digitalWrite(in4_B, LOW);
  }

  //C
    if (C_speed > 0) {
    analogWrite(in1_C, C_speed);
    digitalWrite(in2_C, LOW);
  } else if (C_speed < 0) {
    analogWrite(in1_C, -C_speed);
    digitalWrite(in2_C, LOW);
  } else {
    digitalWrite(in1_C, LOW);
    digitalWrite(in2_C, LOW);
  }

  //D
    if (D_speed > 0) {
    analogWrite(in3_D, D_speed);
    digitalWrite(in4_D, LOW);
  } else if (D_speed < 0) {
    analogWrite(in3_D, -D_speed);
    digitalWrite(in4_D, LOW);
  } else {
    digitalWrite(in3_D, LOW);
    digitalWrite(in4_D, LOW);
  }
}

void bluetooth_command(String command) {
  char cmd = command.charAt(0);

  switch (cmd) {
    case 'F': // Move forward
      motor_function(A_speed, B_speed, C_speed, D_speed);
      break;
    case 'B': // Move backward
      motor_function(-A_speed, -B_speed, -C_speed, -D_speed);
      break;
    case 'L': // Turn left
      motor_function(-A_speed, B_speed, -C_speed, D_speed);
      break;
    case 'R': // Turn right
      motor_function(A_speed, -B_speed, C_speed, -D_speed);
      break;
    case 'S': // Stop
      motor_function(0, 0, 0, 0);
      break;
    case 'Q': // Sequence
      run_motor_sequence();
      break;
    default:
      Serial.println("Invalid command received.");
      break;
  }
}


void loop() {
  
    if (Bluetooth.available()) {
    String command = Bluetooth.readStringUntil('\n'); 
    bluetooth_command(command);


  }
}
