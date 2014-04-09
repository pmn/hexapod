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
Servo shoulders[6];
Servo elbows[6];

int shoulder_pos[6][3];

int right_legs[3];
int left_legs[3];

const int front=0; 
const int neutral=1;
const int rear=2;

const int up=10;
const int down=70;

void register_servos() {
  // Hook up all the legs to their appropriate pins and set movement ranges.
  left_legs[0] = 0;
  left_legs[1] = 1;
  left_legs[2] = 2;
  
  right_legs[0] = 3;
  right_legs[1] = 4;
  right_legs[2] = 5;
  
  elbows[0].attach(30);
  shoulders[0].attach(31);
  shoulder_pos[0][front] = 115;
  shoulder_pos[0][neutral] = 130;
  shoulder_pos[0][rear] = 145;

  elbows[1].attach(32);
  shoulders[1].attach(33);
  shoulder_pos[1][front] = 75;
  shoulder_pos[1][neutral] = 90;
  shoulder_pos[1][rear] = 105;

  elbows[2].attach(34);
  shoulders[2].attach(35);
  shoulder_pos[2][front] = 45;
  shoulder_pos[2][neutral] = 60;
  shoulder_pos[2][rear] = 75;

  elbows[3].attach(8);
  shoulders[3].attach(9);
  shoulder_pos[3][front] = 145;
  shoulder_pos[3][neutral] = 130;
  shoulder_pos[3][rear] = 115;

  elbows[4].attach(10);
  shoulders[4].attach(11);
  shoulder_pos[4][front] = 105;
  shoulder_pos[4][neutral] = 90;
  shoulder_pos[4][rear] = 75;

  elbows[5].attach(12);
  shoulders[5].attach(13);
  shoulder_pos[5][front] = 75;
  shoulder_pos[5][neutral] = 60;
  shoulder_pos[5][rear] = 45;
}

void leg_move_neutral(int leg){
    shoulders[leg].write(shoulder_pos[leg][neutral]);
    delay(100);
    
    elbows[leg].write(55);
    delay(100);
}

void outer_walk(int legs[]){
  // Walk the outer right legs. 
  // Expects an int[3] array [front, mid, rear] leg positions
  // Steps:
  // 0. push down center leg
  // 1. lift outer legs
  // 2. sweep outer legs to forward position
  // 3. push outer legs down
  // 4. raise inner leg
  // 5. sweep outer legs back
  // 6. push center down
  
  // Push down center leg
  elbows[legs[1]].write(down);
  
  // raise outer legs
  elbows[legs[0]].write(up);
  elbows[legs[2]].write(up);
  delay(250);
  
  // sweep outer legs forward
  shoulders[legs[0]].write(shoulder_pos[legs[0]][front]);
  shoulders[legs[2]].write(shoulder_pos[legs[2]][front]);
  delay(250);
  
  // outer legs down
  elbows[legs[0]].write(down);
  elbows[legs[2]].write(down);
  delay(250);
  
  // center leg up
  elbows[legs[1]].write(up);
  delay(250);
  
  // sweep outer legs back
  shoulders[legs[0]].write(shoulder_pos[legs[0]][rear]);
  shoulders[legs[2]].write(shoulder_pos[legs[2]][rear]);
  delay(250);
  
  // center leg down
  elbows[legs[1]].write(down);
}

void inner_walk(int legs[]){
  // Walk the inner right leg
  // Expects an intp[3] array [front, mid, rear] leg positions
  // Steps: 
  // 0. Push down outer legs
  // 1. raise center leg
  // 2. sweep center forward
  // 3. push center down
  // 4. raise outer legs
  // 5. sweep center to rear
  // 6. lower outer legs
  elbows[legs[1]].write(up);
  shoulders[legs[1]].write(shoulder_pos[legs[1]][front]);
  
  // Delay to let everything catch up
  delay(250);
  
  // Lower the arm
  elbows[legs[1]].write(down);
  
  // Raise outer legs
  elbows[legs[0]].write(up);
  elbows[legs[2]].write(up);
  delay(250);
  
  // Sweep leg back
  shoulders[legs[1]].write(shoulder_pos[legs[1]][rear]);
  delay(250);
  
  // Lower outer legs
  elbows[legs[0]].write(down);
  elbows[legs[2]].write(down);
  delay(250);
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
  
  inner_walk(left_legs);
  outer_walk(right_legs);
  
  inner_walk(right_legs);
  outer_walk(left_legs);
}

