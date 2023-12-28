const int trig_pin = 11;
const int echo_pin = 12;

float alpha = 0.4;
float output = 0;

float low_pass_filter(float input){
  output = alpha * input + (1 - alpha) * output; // output은 이전 출력값
  return output;
}

void setup() {
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Serial.begin(115200);
}

void loop() {
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  // input
  long duration = pulseIn(echo_pin, HIGH);
  long distance = (duration / 2) / 29.1;

  Serial.print(distance);
  Serial.print(" cm, ");
  Serial.print(low_pass_filter(distance));
  Serial.println(" cm");
}
