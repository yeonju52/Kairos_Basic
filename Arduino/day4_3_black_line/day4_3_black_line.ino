int pin = 8;

void setup() {
  pinMode(pin, INPUT);
  Serial.begin(115200);
}

void loop() {
  int val = digitalRead(pin);
  Serial.println(val);
}

