String uga = "a45b98c43d67\n";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char pivot = 'a';
  for (int i = 0; i < 3; i++){
    char idx = pivot + i;
    int start = uga.indexOf(idx);
    int end = uga.indexOf(idx + 1);
    Serial.print(uga.substring(start+1, end).toInt());
    Serial.print("  ");
  }
  Serial.println();
}
