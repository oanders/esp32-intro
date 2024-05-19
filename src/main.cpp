#include <Arduino.h>

#define PIN_LED  2
#define PIN_BUTTON 13

void reverseGPIO(int pin){
  digitalWrite(pin, !digitalRead(pin));
}

void setup() {
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);
  Serial.begin(921600);
  Serial.println("Hello from the setup");
}

void loop() {
  if(digitalRead(PIN_BUTTON) == LOW){
    delay(20);
    if(digitalRead(PIN_BUTTON) == LOW){
      reverseGPIO(PIN_LED);
    }
    while(digitalRead(PIN_BUTTON) == LOW){
      delay(20);
    }
  } 
}



