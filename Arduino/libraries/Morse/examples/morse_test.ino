// https://docs.arduino.cc/learn/contributions/arduino-creating-library-guide
#include <Morse.h>

Morse morse(13);

void setup()
{
  morse.begin();
}

void loop()
{
  morse.dot(); morse.dot(); morse.dot();
  morse.dash(); morse.dash(); morse.dash();
  morse.dot(); morse.dot(); morse.dot();
  delay(3000);
}