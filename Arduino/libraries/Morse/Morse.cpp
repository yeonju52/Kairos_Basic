#include "Arduino.h"
#include "Morse.h"

#ifndef MORSE_H
#define MORSE_H

// 생성자
Morse::Morse(int pin){
    _pin = pin;
}

void Morse::begin(){
    pinMode(_pin, OUTPUT);
}

void Morse::dot(){
    digitalWrite(_pin, HIGH);
    delay(250);
    digitalWrite(_pin, LOW);
    delay(250);
}

void Morse::dash(){
    digitalWrite(_pin, HIGH);
    delay(1000);
    digitalWrite(_pin, LOW);
    delay(250);
}

#endif