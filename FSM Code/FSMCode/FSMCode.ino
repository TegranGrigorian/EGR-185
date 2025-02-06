  enum stateForFSM {
    LED_OFF,
    LED_ON
  };
  enum stateForFSM currentState;
  unsigned long startTime = 0, currentTime;
  uint8_t led1 = 13;
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    currentState = LED_OFF;
    pinMode(led1, OUTPUT);
    startTime = 0;
  }

  void loop() {
    // put your main code here, to run repeatedly:
    currentTime = millis();
    if (currentTime - startTime >= 2000) {
      switch (currentState) {
        case LED_ON:
          digitalWrite(led1, HIGH);
          currentState = LED_OFF;
          break;
        case LED_OFF:
          digitalWrite(led1, LOW);
          currentState = LED_ON;
          break;
      }
      startTime = currentTime;
    }
  }
