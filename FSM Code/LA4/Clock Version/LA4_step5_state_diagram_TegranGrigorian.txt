/*********************************************************************************************************
Student: Tegran Grigorian
Course: EGR185-401
 
Date: 2/5/2025
Assignment: Serial Communication Project
Instructor: Beniam Tewolde
Description: this program will toggle between a fast led blinking state and a slow led blinking state by using 
arduino clock
*******************************************************************************************************************
*/
//ports
const int ledPin = 13;       
const int buttonPin = 8;     

//led state
enum State {
  SLOW,
  FAST
};

//le varibles
State currentState = SLOW;  
bool currentButton = false;       
bool lastButton = false;     
unsigned long oldTime = 0; 
bool ledState = LOW;              

void setup() {
  pinMode(ledPin, OUTPUT);        
  pinMode(buttonPin, INPUT);      
  Serial.begin(9600);             
  Serial.println("slow");
}

void loop() {

  bool currentButton = digitalRead(buttonPin);

  if (currentButton == HIGH && lastButton == LOW) {  // toggle the state

    if (currentState == SLOW) {
      currentState = FAST;
      Serial.println("fast");
    } else {
      currentState = SLOW;
      Serial.println("Bslow");
    }
    delay(200);  //optionales because it would freak out sometimes
  }

  lastButton = currentButton;

  switch (currentState) {
    case SLOW:
      led(1000);  
      break;

    case FAST:
      led(200);   
      break;
  }
}

//no allowed to use delay
void led(int interval) {
  unsigned long current = millis();  

  
  if (current - oldTime >= interval) {
    oldTime = current;  

    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}