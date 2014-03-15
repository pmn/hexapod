#include <Servo.h>

Servo Shoulders[6];
Servo Elbows[6];

void register_servos() {
    /* PIN LAYOUT
      LEG            ELBOW PIN       SHOULDER PIN
      -------------------------------------------
      1              30              31
      2              32              33
      3              34              35
      4               8               9
      5              10              11
      6              12              13
  */

  Elbows[0].attach(30);
  Shoulders[0].attach(31);

  Elbows[1].attach(32);
  Shoulders[1].attach(33);

  Elbows[2].attach(34);
  Shoulders[2].attach(35);

  Elbows[3].attach(8);
  Shoulders[3].attach(9);

  Elbows[4].attach(10);
  Shoulders[4].attach(11);

  Elbows[5].attach(12);
  Shoulders[5].attach(13);
}

void init_position() {
  // Elbows should be moved to position 55
  // Shoulders should be moved to position 90

  for (int i=0; i<=5; i+=1){
    Shoulders[i].write(90);
    delay(100);

    Elbows[i].write(55);
    delay(100);
  }
}

void setup() {
  // Put setup code here. This only runs once.
  register_servos();
  init_position();
}

void loop() {
  // Put main code here; this loops continuously.
}
