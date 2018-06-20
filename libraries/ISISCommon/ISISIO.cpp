#include "Arduino.h"

void isisSetDigitalOut(int pin) {
  pinMode(pin, OUTPUT);
}

void isisSetDigitalIn(int pin) {
  pinMode(pin, INPUT);
}

String isisReadDigitalString(int pin) {
  return (digitalRead(pin) ? "True" : "False");
}

void isisWriteDigitalString(int pin, String state) {
  if (state == "TRUE") {
    digitalWrite(pin, HIGH);
  }
  else if (state == "FALSE") {
    digitalWrite(pin, LOW);
  }
}

String isisReadDigitalStringInvert(int pin) {
  return (digitalRead(pin) ? "False" : "True");
}

void isisWriteDigitalStringInvert(int pin,String state) {
  if (state == "TRUE") {
    digitalWrite(pin, LOW);
  }
  else if (state == "FALSE") {
    digitalWrite(pin, HIGH);
  }
}

