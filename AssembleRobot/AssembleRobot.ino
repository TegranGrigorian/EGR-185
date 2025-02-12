#include <Servo.h>

// Ports
const int8_t Motor_In_1 = 6;
const int8_t Motor_In_2 = 7;
const int8_t Motor_Encoder_A = 10; // PWM pin
const int8_t Button_Pin = 8;
const int8_t Debug_LED = 13;

// Servo
Servo Turn_Servo;
const int8_t Servo_Pin = 9;

unsigned long Motor_State_Time = 0;
unsigned long Turn_State_Time = 0;
bool isTurning = false;
bool manualMode = false;

// Robot States
enum State {
  STOP,
  DRIVE_FORWARD,
  TURN_LEFT,
  TURN_RIGHT,
  MANUAL_CONTROL
};

State Robot_State = STOP;

void setup() {
  pinMode(Motor_In_1, OUTPUT);
  pinMode(Motor_In_2, OUTPUT);
  pinMode(Motor_Encoder_A, OUTPUT);
  pinMode(Button_Pin, INPUT_PULLUP);
  pinMode(Debug_LED, OUTPUT);

  Turn_Servo.attach(Servo_Pin);

  Serial.begin(9600);
  Serial.println("Robot will begin driving forward soon");

  Robot_State = DRIVE_FORWARD; // it will drive forward on startup, you can change this to be stop fi want
  Motor_State_Time = millis(); //start robot clock
}

void loop() {
  if (digitalRead(Button_Pin) == LOW) {
    manualMode = !manualMode;
    delay(200); // debouncer
  }

  digitalWrite(Debug_LED, manualMode ? HIGH : LOW); //no way I used the ? for the first time 😊😊😊😊

  if (manualMode && Serial.available() > 0) {
    char command = Serial.read(); //read a chracter from the users input
    switch (command) {
      case 'w':
        driveForward(200);
        break;
      case 's':
        stopMotor();
        break;
      case 'a':
        turnServo(-30);
        break;
      case 'd':
        turnServo(30);
        break;
      case 'q':
        Turn_Servo.write(90);
        break;
    }
  } else if (manualMode == false) {
    switch (Robot_State) {
      case DRIVE_FORWARD:
        driveForward(200);
        if (millis() - Motor_State_Time >= 2000) {
          stopMotor();
          Robot_State = TURN_LEFT;
          Turn_State_Time = millis();
          isTurning = true;
        }
        break;

      case TURN_LEFT:
        if (isTurning) {
          turnServo(-30);
          isTurning = false;
          Turn_State_Time = millis();
        }
        if (millis() - Turn_State_Time >= 1000) {
          Turn_Servo.write(90);
          Robot_State = DRIVE_FORWARD;
          Motor_State_Time = millis();
        }
        break;

      case TURN_RIGHT:
        if (isTurning) {
          turnServo(30);
          isTurning = false;
          Turn_State_Time = millis();
        }
        if (millis() - Turn_State_Time >= 1000) {
          Turn_Servo.write(90);
          Robot_State = DRIVE_FORWARD;
          Motor_State_Time = millis();
        }
        break;

      case STOP:
        stopMotor();
        break;
    }
  }
}

void stopMotor() {
  digitalWrite(Motor_In_1, LOW);
  digitalWrite(Motor_In_2, LOW);
  analogWrite(Motor_Encoder_A, 0);
}

void driveForward(int8_t speed) {
  analogWrite(Motor_Encoder_A, speed);
  digitalWrite(Motor_In_1, HIGH);
  digitalWrite(Motor_In_2, HIGH);
}

void turnServo(int angle) {
  Turn_Servo.write(90 + angle); // 90 is straight, -angle left, +angle right
}
