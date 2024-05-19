#include <Arduino.h>

#define PIN_BUZZER  13
#define PIN_BUTTON  4
#define CHN         0
hw_timer_t * timer = NULL;

bool isAlerting = false;

void IRAM_ATTR onTimer(){
  digitalWrite(PIN_BUZZER, !digitalRead(PIN_BUZZER));
}


void setup() {
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_BUTTON, INPUT);

  timer = timerBegin(0, 80, true);

  timerAttachInterrupt(timer, &onTimer, true);
}

void alert(){
  float sinVal;
  int toneVal;
  for (size_t x = 0; x < 360; x += 10)
  {
    sinVal = sin(x*(PI/180));
    toneVal = 2000 + sinVal * 500;
    timerAlarmWrite(timer, 500000/toneVal, true);
    delay(1);
  }
  

}

void loop() {
  if(digitalRead(PIN_BUTTON) == LOW){
    if(!isAlerting){
      isAlerting = true;
      timerAlarmWrite(timer, 1000, true);
      timerAlarmEnable(timer);
    }
    alert();
  }else{
    if(isAlerting){
      isAlerting = false;
      timerAlarmDisable(timer);
      digitalWrite(PIN_BUZZER, LOW);
    }
  }
}



