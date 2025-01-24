#include <Servo.h>

// Initialize servo
Servo turnServo;
const int servoPin = 3;

// Initialize motor pins
const int Motor_In_1 = 6;
const int Motor_In_2 = 7;
const int Motor_Encoder_A = 10; // isnt really needed for now

// Define PWM output value
const int8_t pwmOutput = 255; // Adjust this value as needed (0-255) // max voltage, ~122 is the 0, anything under is reverse adn above is forward

void setup() {
  // Attach servo
  turnServo.attach(servoPin); //once we use a servo

  //setting outputs
  pinMode(Motor_In_1, OUTPUT);
  pinMode(Motor_In_2, OUTPUT);
  pinMode(Motor_Encoder_A, OUTPUT);

  // Set motor directions in setup!
  digitalWrite(Motor_In_1, LOW);
  digitalWrite(Motor_In_2, HIGH);
}

void loop() {
  // Set motor speed
  analogWrite(Motor_Encoder_A, pwmOutput); // go forward

  // Move servo to 90 degrees keep motor direciton
  turnServo.write(90);
  delay(1000);

  // Move servo to 0 degrees and flip motor direction
  turnServo.write(0);
  digitalWrite(Motor_In_1, HIGH);
  digitalWrite(Motor_In_2, LOW);
  delay(1000); // go back to the loop!
}
