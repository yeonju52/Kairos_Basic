const int interPin = 2;

class LED{
public:
  int pin;
  void setLED(int pin_){
    pin = pin_;
    pinMode(pin, OUTPUT);
  }
  void turnOn(){
    analogWrite(pin, 128);
  }
  void turnOff(){
    analogWrite(pin, 0);
  }
};

LED led[1];
void setup() {
  pinMode(interPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interPin), interruptFunction, FALLING);
  // CHANGE와의 차이점은?
  led[0].setLED(9);
}

int flag = 0;

int n = 0;
void loop() {
  delay(1000);
  if (flag == 0){
    if (n == 0){
      led[0].turnOn();
      n = 1;
    }
    else if (n == 1){
      led[0].turnOff();
      n = 0;
    }
    flag = 1;
  }
}

void interruptFunction(){
  flag = 0;
}