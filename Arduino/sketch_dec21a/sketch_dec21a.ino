signed int num = 35767;
unsigned int num2 = 35767;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  num++;
  num2++;
  Serial.print(num);
  Serial.print("       ");
  Serial.println(num2);

  delay(1000);
}
