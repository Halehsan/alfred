
// Motor A connections- right
int enA = 5;
int in1 = 7;
int in2 = 6;

// Motor B connections- left
int enB = 10;
int in4 = 9;
int in3 = 8;


void setup() {

  initializeMotors();
  motor_function(0,0);
}

void initializeMotors() {

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
