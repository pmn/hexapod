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

bool left; 
bool right;

const int front=0; 
const int neutral=1;
const int rear=2;

void register_servos() {
  // Hook up all the legs to their appropriate pins and set movement ranges.

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

void leg_walk(int leg){
  // Sweep the specified leg in a forward walking motion.
  elbows[leg].write(10);
  shoulders[leg].write(shoulder_pos[leg][front]);
  
  // Delay to let everything catch up
  delay(600); 
  
  // Leg is forward, lower the arm and move it backwards
  elbows[leg].write(70);
  delay(300);
  shoulders[leg].write(shoulder_pos[leg][rear]);
  delay(300);
  
  elbows[leg].write(60);
  // Set the leg neutral
  // leg_move_neutral(leg);
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
  right = true;
  register_servos();
  init_position();
}

void loop() {
  // Put main code here; this loops continuously.
  // Try moving a leg forward
  
  leg_walk(0);  
  leg_walk(3);
  
  leg_walk(1);
  leg_walk(4);
  
  leg_walk(2);
  leg_walk(5);
}

