int Encoder = 2;
volatile int count = 0;
unsigned long oldTime = 0;
unsigned long newTime = 0;

void IsReconder(){
  count++;
}

void setup() {
  Serial.begin(115200);
  pinMode(Encoder, INPUT_PULLUP);
  attachInterrupt(INT0, IsReconder, FALLING);
}

void loop() {
  newTime = millis();
  if (newTime - oldTime > 1000){
    oldTime = newTime;
    noInterrupts();
    Serial.println(count);
    interrupts();
  }
}
