const int inputPin = 2;
class Led{
public:
  int pin;
  void turnOn(){
    analogWrite(pin, 90);
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

void setup() {
  Serial.begin(115200);
  pinMode(inputPin, INPUT_PULLUP);
  led[0].setPin(9);
  led[1].setPin(10);
  led[2].setPin(11);
}

int i = 0;
bool flag = 1;
void loop() {
  // delay(100);
  int digitalValue = digitalRead(inputPin);
  if (digitalValue == 1){ // off
    flag = 1;
  }
  else { // on
    if (flag == 1){ // continㅕous
      led[i%3].turnOn();
      led[(i+1)%3].turnOff();
      led[(i+2)%3].turnOff();
      i = (i + 1) % 3;
      Serial.println(i);
      flag = 0;
    }
  }
}

// 교과서 코드 참고해서, 지터 해결하자.
