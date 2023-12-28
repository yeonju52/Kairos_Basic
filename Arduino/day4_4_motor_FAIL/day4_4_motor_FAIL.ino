// IA_1 = 9, IB_1 = 10
void setup() {
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  Serial.begin(115200);

  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
}

String input;
int num[2] = { 0, 0 };
void loop() {
  if (Serial.available()) {
    input = Serial.readStringUntil('\n');
    Serial.println(input);
    num[0] = input.substring(input.charAt('a') + 1, input.charAt('b')).toInt();
    num[1] = input.substring(input.charAt('b') + 1, input.charAt('c')).toInt();
  }
  if (num[0] == 0) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    Serial.println(num[0]);
  } else if (num[0] == 1) {
    // digitalWrite(9, HIGH);
    // 속도 조절을 위해서는 ..?
    analogWrite(9, num[1]);
    digitalWrite(10, LOW);
    Serial.println(num[0]);
  } else if (num[0] == 2) {
    analogWrite(9, num[1]);
    // digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    Serial.println(num[0]);
  }
}
