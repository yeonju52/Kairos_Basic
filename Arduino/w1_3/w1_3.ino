int num = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  num++;
  Serial.print("count value is: ");
  Serial.println(num);

  delay(1000);
}
