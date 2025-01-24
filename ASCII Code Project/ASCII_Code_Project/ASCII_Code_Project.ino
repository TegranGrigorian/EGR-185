/*********************************************************************************************************

Student: Tegran Grigorian

Course: EGR185-401
  
Date: 1/13/2025

Assignment: Serial Communication Project
Instructor: Beniam Tewolde

Description: This program runs on an arduino and will wait for a user input, then pass it off to a function to blink an led. This led will blink
how many seconds the user has inputted.
*******************************************************************************************************************
*/
#define LED 13
char input = '1';
int16_t flashTime = 500; // 500 ms delay
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  Serial.println("Enter in number");//prompt user to enter number
  
}

void loop() {
  if (Serial.available() > 0) { // if serial is open, wait for user response
   	input = Serial.read();
    Serial.println("User input recivied!");
    Serial.print(input);
    Serial.println(" Seconds");
  }
  if (input > '0' && input <= '9') {  //procede and process
   	flashTime = (input - '0')  * 1000;
  }
  flash(flashTime); // flash LED for that amount of time in  secodns
}

void flash(int16_t time) {
  digitalWrite(LED, HIGH); // turm led on
  delay(time); //wait for 'time' ms
  digitalWrite(LED,LOW); //turn off led
  delay(time); //wait for 'time' ms
}
