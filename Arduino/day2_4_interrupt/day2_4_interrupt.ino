class Led{
public:
  int pin;
  void turnOn(){
    analogWrite(pin, 50);
  }
  void turnOff(){
    analogWrite(pin, 0);
  }
  void setPin(int pin_){
    pin = pin_;
    pinMode(pin, OUTPUT);
  }
  int getPin(){
    return pin;
  }
};
Led led[3];

const int interruptPin = 2;
// volatile int interruptCount = 0; // 빠른 access를 위한
void setup() {
  pinMode(interruptPin, INPUT_PULLUP);
  // callback 함수와 유사
  attachInterrupt(digitalPinToInterrupt(interruptPin), interruptFunction, FALLING);
  Serial.begin(115200);
  led[0].setPin(9);
  led[1].setPin(10);
  led[2].setPin(11);
}

bool flag = 1;
int i = 0;
void loop() {
  // Serial.println(interruptCount);
  delay(1000);
  if (flag == 0){ // continuous
    led[i%3].turnOn();
    led[(i+1)%3].turnOff();
    led[(i+2)%3].turnOff();
    i = (i + 1) % 3;
    Serial.println(i);
    flag = 1;
  }
}

void interruptFunction(){ // jitter 발생 어떻게 해결?
  // interruptCount++;
  // Serial.println(interruptCount);
  flag = 0;
  // 다른 방법 (당연히, loop함수 수정해야함. if 절로)
  // if (flag == 0){
  //   flag = 1;
  // }
  // else{
  //   flag = 0;
  // }
}
