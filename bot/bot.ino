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

int even_legs[3];
int odd_legs[3];

const int forward=0; 
const int neutral=1;
const int rear=2;

const int up=30;
const int down=70;
const int in=90;
const int out=20;


void register_servos() {
  // Hook up all the legs to their appropriate pins and set movement ranges.
  even_legs[0] = 0;
  even_legs[1] = 2;
  even_legs[2] = 4;
  
  odd_legs[0] = 1;
  odd_legs[1] = 3;
  odd_legs[2] = 5;
 
  
  elbows[0].attach(30);
  shoulders[0].attach(31);
  shoulder_pos[0][forward] = 115;
  shoulder_pos[0][neutral] = 130;
  shoulder_pos[0][rear] = 145;

  elbows[1].attach(32);
  shoulders[1].attach(33);
  shoulder_pos[1][forward] = 75;
  shoulder_pos[1][neutral] = 90;
  shoulder_pos[1][rear] = 105;

  elbows[2].attach(34);
  shoulders[2].attach(35);
  shoulder_pos[2][forward] = 45;
  shoulder_pos[2][neutral] = 60;
  shoulder_pos[2][rear] = 75;

  elbows[3].attach(8);
  shoulders[3].attach(9);
  shoulder_pos[3][forward] = 145;
  shoulder_pos[3][neutral] = 130;
  shoulder_pos[3][rear] = 115;

  elbows[4].attach(10);
  shoulders[4].attach(11);
  shoulder_pos[4][forward] = 105;
  shoulder_pos[4][neutral] = 90;
  shoulder_pos[4][rear] = 75;

  elbows[5].attach(12);
  shoulders[5].attach(13);
  shoulder_pos[5][forward] = 75;
  shoulder_pos[5][neutral] = 60;
  shoulder_pos[5][rear] = 45;
}

void move_legs_forward(int legs[]){
  for (int i=0; i<3; i+=1){
   shoulders[legs[i]].write(shoulder_pos[legs[i]][forward]);
  }
  delay(75);
}

void move_legs_up(int legs[]){
  for (int i=0; i<3; i+=1){
   elbows[legs[i]].write(up); 
  }
  delay(75);
}

void move_legs_down(int legs[]){
  for (int i=0; i<3; i+=1){
   elbows[legs[i]].write(down); 
  }
  delay(75);
}

void move_legs_backward(int legs[]){
  for (int i=0; i<3; i+=1){
   shoulders[legs[i]].write(shoulder_pos[legs[i]][rear]);
  }
  delay(75);
}

void move_legs_in(int legs[]){
 for (int i=0; i<3; i+=1){
   elbows[legs[i]].write(in);
 } 
 delay(200);
}

void move_legs_out(int legs[]){
 for (int i=0; i<3; i+=1){
  elbows[legs[i]].write(out);
 }
 delay(200); 
}

void leg_move_neutral(int leg){
    shoulders[leg].write(shoulder_pos[leg][neutral]);
    delay(75);
    
    elbows[leg].write(down);
    delay(75);
}

void move_legs_neutral(int legs[]){
  for (int i=0; i<3; i+=1){ 
   leg_move_neutral(legs[i]);
  } 
}

// Walk forward
void walk_forward() {
  move_legs_up(odd_legs);
  move_legs_forward(odd_legs);
  move_legs_down(odd_legs);
  
  move_legs_up(even_legs);
  move_legs_backward(odd_legs);
  move_legs_forward(even_legs);
  
  move_legs_down(even_legs);
  move_legs_up(odd_legs);
  move_legs_backward(even_legs);
}

// Crab walk to the left
void crab_left() {
  move_legs_in(odd_legs);
  move_legs_out(even_legs);
  
  move_legs_in(even_legs);
  move_legs_out(odd_legs);
}

// Crab walk to the right
void crab_right() {
  
}

void init_position() {
  // Elbows should be moved to position 55
  // Shoulders should be moved to position 90
  move_legs_neutral(even_legs);
  move_legs_neutral(odd_legs);
}

void setup() {
  // Put setup code here. This only runs once.
  register_servos();
  init_position();
}

void loop() {
  // Put main code here; this loops continuously.
  walk_forward();
  //crab_left();
}

