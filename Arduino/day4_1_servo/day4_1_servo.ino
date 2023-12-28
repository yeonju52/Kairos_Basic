#include<Servo.h>

Servo myServo;
int angle = 90;
int dir = 1;

void run_servos(Servo sv, int max, int speed) {
  angle += (dir * speed);
  sv.write(angle);
  if (angle < 0){
    angle = 0;
    dir = 1;
  }
  if (angle > max){
    angle = 90;
    dir = -1;
  }
}

void run_servo(Servo sv){
  angle += dir;
  sv.write(angle);
  
  if (angle < 0){
    angle = 0;
    dir = 1;
  }
  if (angle > 170){
    angle = 90;
    dir = -1;
  }
}

int servoParallelControl(Servo sv, int pos, int speed){
  int curPos = sv.read();
  
  if (curPos < pos){
    curPos += 1;
    sv.write(curPos);
    delay(speed); // 감속, 가속은 이미 빠르기 때문에 의미가 없다.
    return 0;
  }
  else if (curPos > pos){
    curPos -= 1;
    sv.write(curPos);
    delay(speed);
    return 0;
  }
  else{
    return 1;
  }
}


void setup() {
  myServo.attach(2);
  myServo.write(90);
}

int done = 0;
  
void loop() {
  // run_servo(myServo);
  // dir = 1;
  // run_servos(myServo, 0, 120, 3);
  if (!done){
    if (servoParallelControl(myServo, 150, 20)) done = 1;
  }
}
