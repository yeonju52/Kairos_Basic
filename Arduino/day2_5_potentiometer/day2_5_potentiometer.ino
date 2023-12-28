const int analogPin = A0;

// GCC: 0V, VCC: 5V, OUTPUT: A0 
void setup() {
  Serial.begin(115200);
  // pinMode(analogPin, INPUT);
}

void loop() {
  int analogValue = analogRead(analogPin);
  Serial.println(analogValue);
}
