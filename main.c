#include <Servo.h>

void setpos(int pin, int pos){
  // Set the position of servo at <pin> position.
  Servo servo;
  servo.attach(pin);
  servo.write(pos);
}

void init_position(){
  /*  LEG            ELBOW PIN       SHOULDER PIN
      -------------------------------------------
      1              30              31
      2              32              33
      3              34              35
      4               8               9
      5              10              11
      6              12              13
  */
  // Arm set 1
  for (int i=7; i<=13; i+=1) {
    // Set Elbows
    if (i%2==0){
      // Even pins are always elbows
      setpos(i, 55);
    } else {
      // odd pins are shoulders
      setpos(i, 90);
    }
  }

  // Arm set 2
  for (int i=30; i<=36; i+=1) {
    // Set Elbows
    if (i%2==0){
      // Even pins are always elbows
      setpos(i, 55);
    } else {
      // odd pins are shoulders
      setpos(i, 90);
    }
  }

  delay(15);
}

void setup(){
  // Called once at initialization.
  init_position();
}

void loop(){
  // This code runs repeatedly.
}
