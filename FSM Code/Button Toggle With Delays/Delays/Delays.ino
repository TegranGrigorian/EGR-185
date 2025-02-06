  enum stateForFSM {
    LED_OFF,
    LED_ON
  };
  enum stateForFSM currentState;
  unsigned long startTime = 0, currentTime;
  uint8_t led1 = 13;
  uint8_t button1 = 8;
  void setup() {
    // put your setup code here, to run once:
    Serial.begin(9600);
    currentState = LED_OFF;
    pinMode(led1, OUTPUT);
    pinMode(button1, INPUT_PULLUP);
    startTime = 0;
  }

  void loop() {
    // put your main code here, to run repeatedly:
    currentTime = millis();
    // if (currentTime - startTime >= 2000) {
    //   switch (currentState) {
    //     case LED_ON:
    //       digitalWrite(led1, HIGH);
    //       currentState = LED_OFF;
    //       break;
    //     case LED_OFF:
    //       digitalWrite(led1, LOW);
    //       currentState = LED_ON;
    //       break;
    //   }
    //   startTime = currentTime;
    // }
    
    if (pressed(button1)) { 
      digitalWrite(led1, HIGH);
      delay(1000);
      digitalWrite(led1, LOW);
    } else if (!pressed(button1)) {
      digitalWrite(led1, HIGH);
      delay(200);
      digitalWrite(led1, LOW);
    }
  }

  bool pressed(uint8_t pin) {
    if (digitalRead(pin) == LOW) {
      return true;
    return false;
    }
  }