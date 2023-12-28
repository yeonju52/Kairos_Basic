/*
class Led:
  def __init__():
    pass
*/

class Led{
public:
  Led(int pin_){ // 생성자
    // Serial.println("created"); // 초기화를 전역변수에 하니, 의미가 없음.
    pinMode(13, OUTPUT);
    pin = pin_;
  }
  Led(){
    pin = 13;
  }
  
  int pin;

  void turnOn(){
    digitalWrite(pin, HIGH);
    Serial.println("ON");
    delay(1000);
  }
  void turnOff(){
    digitalWrite(pin, LOW);
    Serial.println("OFF");
    delay(1000);
  }
  void setPin2(int pin2_){
    pin2 = pin2_;
  }
  int getPin2(){
    return pin2;
  }
private:
  int pin2 = 4;
};

Led l1(13);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  l1.turnOn();
  l1.turnOff();
}