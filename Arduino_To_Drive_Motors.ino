#include<SoftwareSerial.h>

SoftwareSerial mySUART(2, 3);  // SRX = Din-2, STX = Dpin-3
const int SPEED=255;
const int motorPin1 = 9; 
const int motorPin2 = 8; 
const int motorEnablePin = 10; 
//led passive
const int led1 = 4; //red
const int led2 = 12; //green
const int led3 = A0; //blue
const int motorPin3 = 11;
const int motorPin4 = 5;
const int motorEnableAPin = 6;

int prev = 0; // Initialize prev to 0
int count = 0;

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorEnablePin, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(motorEnableAPin, OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  Serial.begin(115200);
  mySUART.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    char x = Serial.read();
    // Implement serial command processing here if needed
  }
  if (mySUART.available() > 0) {
    char data = mySUART.read();
    processCommand(data);
  }
}

void processCommand(char cmd) {
  if (cmd == prev) {
    return;
  }

  if(cmd=='2')
  {
    forward();
  }
  else if(cmd=='1')
  {
    backward();
  }
  else if(cmd=='3')
  {
    right();
  }
  else if(cmd=='4')
  {
    left();
  }
  else
  {
    stopmo();
  }
  count++;
  if (count > 8) {
    prev = 0;
    count = 0;
  } else {
    prev = cmd - '0'; 
  }
}


inline void stopmo()
{
  digitalWrite(motorEnablePin,LOW);
  digitalWrite(motorEnableAPin,LOW);
}

void backward()
{
  green();
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(motorEnablePin, SPEED);
  analogWrite(motorEnableAPin, SPEED);
  delay(1000);
  digitalWrite(motorEnablePin, LOW);
  digitalWrite(motorEnableAPin, LOW);
  off();
}
void forward()
{
  red();
  Serial.println("Forward");
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(motorEnablePin, SPEED);
  analogWrite(motorEnableAPin, SPEED);
  delay(1000);
  digitalWrite(motorEnablePin, LOW);
  digitalWrite(motorEnableAPin, LOW);
  off();
}
void right()
{
  blue();
  digitalWrite(motorPin1, LOW);
  digitalWrite(motorPin2, HIGH);
  digitalWrite(motorPin3, HIGH);
  digitalWrite(motorPin4, LOW);
  analogWrite(motorEnablePin, SPEED);
  analogWrite(motorEnableAPin, SPEED);
  delay(200);
  digitalWrite(motorEnablePin, LOW);
  digitalWrite(motorEnableAPin, LOW);
  off();

  
}
void left()
{
  blue();
  digitalWrite(motorPin1, HIGH);
  digitalWrite(motorPin2, LOW);
  digitalWrite(motorPin3, LOW);
  digitalWrite(motorPin4, HIGH);
  analogWrite(motorEnablePin, SPEED);
  analogWrite(motorEnableAPin, SPEED);
  delay(200);
  digitalWrite(motorEnablePin, LOW);
  digitalWrite(motorEnableAPin, LOW);
  off();
}
inline void red()
{
  digitalWrite(led1,LOW);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
}
inline void blue()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,LOW);
}
inline void green()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,LOW);
  digitalWrite(led3,HIGH);
}
inline void off()
{
  digitalWrite(led1,HIGH);
  digitalWrite(led2,HIGH);
  digitalWrite(led3,HIGH);
}
