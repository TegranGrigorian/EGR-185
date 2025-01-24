/*********************************************************************************************************

Student: Tegran Grigorian

Course: EGR185-401

Date: 1/13/2025

Assignment: Morse Code Project
Instructor: Beniam Tewolde

Description: This program will output my initals 'TTG' on an arduino by blinking a LED, the time unit is 500ms
*******************************************************************************************************************/
  #define LED 13
  #define LED2 A0
  unsigned char i = 0;
  int16_t timeUnit = 500; // 500 ms delay
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
    pinMode(LED, OUTPUT);
    digitalWrite(LED, LOW);
    digitalWrite(LED2, LOW);
  }

  void loop() {
    morseInital();
  }
  void morseInital() {
    //letter for 'T'
    dash();
    Serial.println("Letter- 'T' created");
    
    //blank space between letters
    delay(timeUnit * 2); // 1000 ms because in the function dash, we get a 500 ms delay so 1000 + 500 = 1500
    
    //another T
    dash();
    Serial.println("Letter- 'T' created");

    //blank space between letters
    delay(timeUnit * 2); // 1000 ms because in the function dash, we get a 500 ms delay so 1000 + 500 = 1500
    
    //letter for 'G'
    dash();
    dash();
    dot();
    Serial.println("Letter- 'G' created");

    //gap between next letter
    delay(timeUnit * 2);

    //gap to next word to continue the loop
    delay(timeUnit * 4);
    Serial.println("restart");
  }

  void dot() {
    digitalWrite(LED, HIGH); //turn on
    delay(timeUnit);
    digitalWrite(LED, LOW); //after delay turn off led
    delay(timeUnit);
  }

  void dash() {
    digitalWrite(LED, HIGH);//turn on
    delay(timeUnit * 3); // 1500 ms delay
    digitalWrite(LED, LOW); // turn off
    delay(timeUnit);
  }