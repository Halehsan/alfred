
// Motor A connections- right
int enA = 5;
int in1 = 7;
int in2 = 6;

// Motor B connections- left
int enB = 10;
int in4 = 9;
int in3 = 8;


void setup() {

  initialize_motors();
  motor_function(0,0);
  run_motor_sequence();
}

void initialize_motors() {

  // Set all the motor control pins to output
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);

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

    
  analogWrite(enB, abs(left_speed));
  analogWrite(enA, abs(right_speed));

  // A - left side 
  
  if (left_speed > 0) {

    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);

  } else if (left_speed < 0) {
    
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
  } else {

    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
  }
  

  // B - right side 

  if (right_speed > 0) {
    // Forward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);

  } else if (right_speed < 0) {
    // Backward
    digitalWrite(in2, HIGH);
    digitalWrite(in1, LOW);

  } else {
    // Stop
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);

  }

 
}




void loop() {
  //...

}
