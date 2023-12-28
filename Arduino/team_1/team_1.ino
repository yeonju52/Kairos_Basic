#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

class UltraSound{
public:
  int trig_pin;
  int echo_pin;
  void setPin(int output, int input){
    trig_pin = output;
    pinMode(trig_pin, OUTPUT);
    echo_pin = input;
    pinMode(echo_pin, INPUT);
  }
  void output_trig(){
    digitalWrite(trig_pin, LOW);  
    delayMicroseconds(2);
    digitalWrite(trig_pin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig_pin, LOW);
  }
  long input_echo(){
    long duration = pulseIn(echo_pin, HIGH);
    long distance = (duration / 2) / 29.1;
    return distance;
  }
  void viewOLED(int dir, int v){
    // front (y: min: 32, max = 0)
    // right (x: min: 64, max = 128)
    // left (x: min: 64, max = 0)
    if (v > 500){
      v = 500;
    }
    // Serial.println(v);
    if (dir == 0){ // front
      int vf = map(v, 0, 500, 32, 0);
      display.drawLine(0, vf, display.width()-1, vf, SSD1306_WHITE); // y: 0 ~ 32
    }
    else if (dir == 1){ // right
      int vr = map(v, 0, 500, 64, 128);
      display.drawLine(vr, 0, vr, display.height()-1, SSD1306_WHITE); // x: 0 ~ 128
    }
    else if (dir == 2){
      int vl = map(v, 0, 500, 64, 0);
      display.drawLine(vl, 0, vl, display.height()-1, SSD1306_WHITE); // x: 0 ~ 128
    }
  }
};

UltraSound ul[3];

void setup() {
  Serial.begin(115200);
  ul[0].setPin(8, 9); // front
  ul[1].setPin(4, 5); // right
  ul[2].setPin(6, 7); // left

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }

  // Clear the buffer
  display.clearDisplay();
}

int n = 0;
void loop() {
  for (int i = 0; i < 3; i++){
    ul[i].output_trig();
    // input
    ul[i].viewOLED(i, ul[i].input_echo());
    // Serial.print(ul[i].input_echo());
    // Serial.print(" cm   ");
  }
  display.display();
  delay(1);
  if (n == 2){
    display.clearDisplay();
  }
  n = (n + 1) % 3;
  // Serial.println("");
}
