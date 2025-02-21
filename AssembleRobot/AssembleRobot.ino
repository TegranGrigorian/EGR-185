#include <Servo.h>

// Ports
const int8_t Motor_In_1 = 8;
const int8_t Motor_In_2 = 7;
const int8_t Motor_Encoder_A = 6; // PWM pin
// const int8_t Button_Pin = 8;
// const int8_t Debug_LED = 13;

// Servo
Servo Turn_Servo;
const int8_t Servo_Pin = 11;

unsigned long Motor_State_Time = 0;
unsigned long Turn_State_Time = 0;
bool isTurning = false;
bool manualMode = false;
int speed = 0;
int angle = 1500;
// Robot States
enum State {
  STOP,
  DRIVE_FORWARD,
  DRIVE_REVERSE,
  TURN_LEFT,
  TURN_RIGHT,
  MANUAL_CONTROL
};

State Robot_State = DRIVE_FORWARD;

void setup() {
  pinMode(Motor_In_1, OUTPUT);
  pinMode(Motor_In_2, OUTPUT);
  pinMode(Motor_Encoder_A, OUTPUT);
  // pinMode(Button_Pin, INPUT_PULLUP);
  // pinMode(Debug_LED, OUTPUT);

  Turn_Servo.attach(Servo_Pin);

  Serial.begin(9600);

  Robot_State = DRIVE_FORWARD; // it will drive forward on startup, you can change this to be stop fi want
  Motor_State_Time = millis(); //start robot clock
}
int command = 0;
void loop() {
  // int command = Serial.read(); //read a chracter from the users input
  // reply only when you receive data:
      if (Serial.available() > 0) {
        // read the incoming byte:
        command = Serial.read();

        // say what you got:
        Serial.print("I received: ");
        Serial.println(command, DEC);
      }
  switch (command) {
    case 48:
      speed = 0;
      Serial.println("0");
      break;
    case 49:
      speed = 28.3;
            Serial.println("1");
      break;
    case 50:
      speed = 28.3  * 2;
      Serial.println("2");

      break;
    case 51:
      speed = 28.3 * 3;
      Serial.println("3");
      break;
    case 52:
      speed = 28.3 * 4;
            Serial.println("4");
      break;
    case 53:
      speed = 28.3 *  5;
            Serial.println("5");
      break;
    case 54:
      speed = 28.3 * 6;
            Serial.println("6");
      break;
    case 55:
      speed = 28.3 * 7;
           Serial.println("7");
      break;

    case 56:
      speed = 28.3 * 8;
            Serial.println("8");
      break;
    case 57:
      speed = 255;
            Serial.println("9");
      break;
    case 108:
      angle += 55.5 ;
      Serial.println("Left");
      break;
    case 114:
      angle -= 55.5 ;
      Serial.println("Right");
      break;
    case 102:
      Robot_State = DRIVE_FORWARD;
      break;
    case 98:
      Robot_State = DRIVE_REVERSE;
    case 115:
     angle = 1500; 
    }
    switch(Robot_State){
      case DRIVE_FORWARD:
        // Serial.println("Forward");
        driveForward(speed);
        break;
      case DRIVE_REVERSE:
              Serial.println("REverse");

        driveReverse(speed);
        break;
      
    }
    Turn_Servo.write(angle);
}

void stopMotor() {
  digitalWrite(Motor_In_1, LOW);
  digitalWrite(Motor_In_2, LOW);
  analogWrite(Motor_Encoder_A, 0);
}

void driveForward(int8_t speed) {
  analogWrite(Motor_Encoder_A, speed);
  digitalWrite(Motor_In_1, HIGH);
  digitalWrite(Motor_In_2, LOW);
}

void driveReverse(int8_t speed) {
  analogWrite(Motor_Encoder_A, speed);
  digitalWrite(Motor_In_1, LOW);
  digitalWrite(Motor_In_2, HIGH);
}

void turnServo(int angle) {
  Turn_Servo.write(90 + angle); // 90 is straight, -angle left, +angle right
}
