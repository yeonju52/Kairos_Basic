
// 의무 설정: No Line Ending, 9600 baud
#include <SoftwareSerial.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <math.h>

#define blueTX 2
#define blueRX 3
char ser = 0;
char ble = 0;

Adafruit_MPU6050 mpu;
SoftwareSerial HC06(blueTX, blueRX);

// IA_1 = 9, IB_1 = 10
class motor{
public:
  int IA;
  int IB;
  void setMotor(int ia_, int ib_){
    IA = ia_;
    IB = ib_;
    pinMode(IA, OUTPUT);
    pinMode(IB, OUTPUT);
  }
  void runFront(int speed){
    analogWrite(IA, speed);
    digitalWrite(IB, LOW);
  }
  void stop(){
    digitalWrite(IA, LOW);
    digitalWrite(IB, LOW);
  }
  void runBack(int speed){
    digitalWrite(IA, LOW);
    analogWrite(IB, speed);
  }
};

class ultra{
public:
  int trig_pin;
  int echo_pin;
  void setUltra(int trig_p, int echo_p){
    trig_pin = trig_p;
    echo_pin = echo_p;
    pinMode(trig_pin, OUTPUT);
    pinMode(echo_pin, INPUT);
  }
  long getDist(){
    digitalWrite(trig_pin, LOW);
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);

    // input
    long duration = pulseIn(echo_pin, HIGH);
    long distance = (duration / 2) / 29.1;

    Serial.print(distance);
    Serial.println(" cm  ");
    
    return distance;
  }
};

motor mt[2];
ultra ul;

void setup() {
  Serial.begin(9600);
  HC06.begin(9600);
  mt[1].setMotor(10, 9);
  mt[0].setMotor(11, 12);
  ul.setUltra(5, 4);

  // gyro
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  Serial.print("Accelerometer range set to: ");
  switch (mpu.getAccelerometerRange()) {
  case MPU6050_RANGE_2_G:
    Serial.println("+-2G");
    break;
  case MPU6050_RANGE_4_G:
    Serial.println("+-4G");
    break;
  case MPU6050_RANGE_8_G:
    Serial.println("+-8G");
    break;
  case MPU6050_RANGE_16_G:
    Serial.println("+-16G");
    break;
  }
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  Serial.print("Gyro range set to: ");
  switch (mpu.getGyroRange()) {
  case MPU6050_RANGE_250_DEG:
    Serial.println("+- 250 deg/s");
    break;
  case MPU6050_RANGE_500_DEG:
    Serial.println("+- 500 deg/s");
    break;
  case MPU6050_RANGE_1000_DEG:
    Serial.println("+- 1000 deg/s");
    break;
  case MPU6050_RANGE_2000_DEG:
    Serial.println("+- 2000 deg/s");
    break;
  }
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.print("Filter bandwidth set to: ");
  switch (mpu.getFilterBandwidth()) {
  case MPU6050_BAND_260_HZ:
    Serial.println("260 Hz");
    break;
  case MPU6050_BAND_184_HZ:
    Serial.println("184 Hz");
    break;
  case MPU6050_BAND_94_HZ:
    Serial.println("94 Hz");
    break;
  case MPU6050_BAND_44_HZ:
    Serial.println("44 Hz");
    break;
  case MPU6050_BAND_21_HZ:
    Serial.println("21 Hz");
    break;
  case MPU6050_BAND_10_HZ:
    Serial.println("10 Hz");
    break;
  case MPU6050_BAND_5_HZ:
    Serial.println("5 Hz");
    break;
  }

  Serial.println("");
  delay(100);
}

long dist;
sensors_event_t a, g, temp;
int spd = 255;

void HC06proc(){
  mpu.getEvent(&a, &g, &temp);
  spd = map(abs(g.gyro.z), 3, 5, 100, 255);
  if (abs(g.gyro.z) < 3){
    spd = 150;
  }
  else if (abs(g.gyro.z) > 5){
    spd = 255;
  }
  dist = ul.getDist();
  if (dist < 20){ // 급제동, stop!!
    mt[0].stop();
    mt[1].stop();
  }
  if(HC06.available() > 0){
    ble = HC06.read();
    
    if (ble == 'w'){ // straight
      if (g.gyro.z < 0){ // gyro.z 반시계가 +, 시계가 -
        // left strong
        mt[0].runFront(spd); // 255
        mt[1].runFront(150); // 200 
      }
      else if (g.gyro.z > 0) {
        // right strong
        mt[0].runFront(150); // 255
        mt[1].runFront(spd); // 200 
      }
      else {
        mt[0].runFront(spd); // 255
        mt[1].runFront(spd); // 200 
      }
    }
    else if (ble == 's'){ // stop
      mt[0].stop();
      mt[1].stop();
    }
    else if (ble == 'a'){ // left
      mt[0].runFront(255);
      mt[1].stop();
    }
    else if (ble == 'd'){ // right
      mt[0].stop();
      mt[1].runFront(255);
    }
    else if (ble == 'x'){
      mt[0].runBack(255);
      mt[1].runBack(200);
    }
    Serial.println(ble);
    // Serial.write(ble);
  }
}

void loop() {
  HC06proc();
}

