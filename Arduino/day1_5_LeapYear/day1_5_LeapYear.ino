int num = 247;

void setup() {
  // put your setup code here, to run once:
  // 247s -> ?m
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(num / 60);
  Serial.print("m ");
  Serial.print(num % 60);
  Serial.println("s");
  delay(1000);
}
