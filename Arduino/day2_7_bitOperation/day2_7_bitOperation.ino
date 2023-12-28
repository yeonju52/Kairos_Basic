void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  char a = 0b00000011;
  char b = 0b10101100;

  char c = a | b;
  for (int i = 0; i < 8; i++){
    char d = c << 1;
    printf("%b", d);
  }

}
# 실패

void bit_read(){

}

void loop() {
  // put your main code here, to run repeatedly:

}
