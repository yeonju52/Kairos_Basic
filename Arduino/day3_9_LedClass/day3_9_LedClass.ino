int led[] = {9, 10, 11};
int maxi = 3;

void setup(){
  for (int i = 0; i < maxi; i++){
    pinMode(led[i], OUTPUT);
  }
}

int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led[i%3], 255);
  analogWrite(led[(i+1)%3], 0);
  analogWrite(led[(i+2)%3], 0);
  delay(500);
  i++;

}
