class Led{
public:
  int pin;
  void turnOn(){
    analogWrite(pin, 180);
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
  // put your setup code here, to run once:
  Serial.begin(115200);
  led[0].setPin(9);
  led[1].setPin(10);
  led[2].setPin(11);
}

int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  led[i%3].turnOn();
  led[(i+1)%3].turnOff();
  led[(i+2)%3].turnOff();
  delay(1000);
  i = (i + 1) % 3;
}