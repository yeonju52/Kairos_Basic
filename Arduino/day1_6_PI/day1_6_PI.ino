float pi = 3.14;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  pi *= 1.1;
  if (isinf(pi)){
    break;
  }
  Serial.println(pi);
}
