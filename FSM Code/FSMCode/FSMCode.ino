enum stateForFSM {
  LED_OFF,
  LED_ON
};
enum stateForFSM currentState;
unsigned long startTime, currentTime;

void setup() {
  // put your setup code here, to run once:
  currentState = LED_ON;
  pinMode(13, OUTPUT);
  startTime = millis();
}

void loop() {
  // put your main code here, to run repeatedly:
  currentTime = millis(); // have the timer start at teh beginign of the loop

  switch (currentState) {
    case LED_ON:
      //do stuff
      break;
    case LED_OFF:
      //do stuff
      break;
  }
}
