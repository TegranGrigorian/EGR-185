#include <Servo.h>
#define MIN 0
#define MAX 180

//serov
int angle = 90;
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //ports
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);  
  
  //servo
  servo.attach(9);
  servo.write(90);
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(6, 128);
  servo.write(angle);
  Serial.println("Forward");
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  delay(1000);

  Serial.println("Backwards");
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  delay(1000);

  Serial.println("STOP");
  analogWrite(6, 0);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  angle += 10;
  if (angle > MAX) {
    angle = MIN;
  }
  delay(1000);
}

