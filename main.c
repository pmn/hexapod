#include <Servo.h>
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
Servo Shoulders[6];
Servo Elbows[6];

void register_servos() {
  // Hook up all the legs to their appropriate pins.

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

void leg_move_neutral(int leg){
    Shoulders[leg].write(90);
    delay(100);

    Elbows[leg].write(55);
    delay(100);
}

void left_leg_walk_forward(int leg){
  // Sweep the specified leg in a forward walking motion.
  Elbows[leg].write(10);
  Shoulders[leg].write(120);

  // Delay to let everything catch up
  delay(600);

  // Leg is forward, lower the arm and move it backwards
  Elbows[leg].write(60);
  delay(300);
  Shoulders[leg].write(40);
  delay(300);
}

void right_leg_walk_forward(int leg){
  // Sweep the specified leg in a forward walking motion.
  Elbows[leg].write(10);
  Shoulders[leg].write(180-120);

  // Delay to let everything catch up
  delay(600);

  // Leg is forward, lower the arm and move it backwards
  Elbows[leg].write(60);
  delay(300);
  Shoulders[leg].write(180-40);
  delay(300);
}

void init_position() {
  // Elbows should be moved to position 55
  // Shoulders should be moved to position 90

  for (int i=0; i<=5; i+=1){
    leg_move_neutral(i);
  }
}

void setup() {
  // Put setup code here. This only runs once.
  register_servos();
  init_position();
}

void loop() {
  // Put main code here; this loops continuously.
   // Try moving a leg forward
  left_leg_walk_forward(0);

  right_leg_walk_forward(3);
}
