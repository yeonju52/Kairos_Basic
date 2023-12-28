#include<Servo.h>

int cmap(int v, int x_start, int x_end, int y_start, int y_end) {
  float ratio = (y_end - y_start) * 1.0 / (x_end - x_start);
  return v * ratio;
}

// 주황: 9, 빨강: 5V, 갈색: 0V
Servo myServo;
void setup() {
  Serial.begin(115200);
  myServo.attach(9);
}

void loop() {
  int value = analogRead(A0);
  Serial.print(value);
  Serial.print("    ");
  Serial.println(cmap(value, 0, 1023, 0, 180));
  myServo.write(cmap(value, 0, 1023, 0, 180));
  // myServo.write(value/4)
}
