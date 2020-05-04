// Motor A connections
int enA = 11;
int in1 = 12;
int in2 = 13;
// Motor B connections
int enB = 10;
int in3 = 8;
int in4 = 7;
// Motor C connections
int enC = 9;
int in5 = 5;
int in6 = 4;
// Motor D connections
int enD = 6;
int in7 = 3;
int in8 = 2;

int incomingByte = 0; // for incoming serial data


void setup() {

  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps

  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(enC, OUTPUT);
  pinMode(enD, OUTPUT);
  
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}



void loop() {

   if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);
  analogWrite(enC, 255);
  analogWrite(enD, 255);
  
  if (incomingByte == '8') {
  // Forward A & B & C & D
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(10);
  }

   if (incomingByte == '2') {
  // Backwards A & B & C & D
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(10);
  }

   if (incomingByte == '4') {
  // Left A & B & C & D
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
  delay(10);
  }

  if (incomingByte == '6') {
  // Right A & B & C & D
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  delay(10);
  }

  if (incomingByte == '5') {
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  delay(10);
  }
   }}
/*
//UNEDITED
// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}*/
