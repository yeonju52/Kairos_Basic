void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 100; i++){
    digitalWrite(3, HIGH);
    delay(100-i);
    digitalWrite(3, LOW);
    delay(i);
  }
}
