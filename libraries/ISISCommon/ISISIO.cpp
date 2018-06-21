#include "Arduino.h"

namespace  isis {
  void setDigitalOut(int pin) {
    pinMode(pin, OUTPUT);
  }

  void setDigitalIn(int pin) {
    pinMode(pin, INPUT);
  }

  String readDigitalString(int pin) {
    return (digitalRead(pin) ? "TRUE" : "FALSE");
  }

  void writeDigitalString(int pin, String state) {
    if (state == "TRUE") {
      digitalWrite(pin, HIGH);
    }
    else if (state == "FALSE") {
      digitalWrite(pin, LOW);
    }
  }

  String readDigitalStringInvert(int pin) {
    return (digitalRead(pin) ? "FALSE" : "TRUE");
  }

  void writeDigitalStringInvert(int pin,String state) {
    if (state == "TRUE") {
      digitalWrite(pin, LOW);
    }
    else if (state == "FALSE") {
      digitalWrite(pin, HIGH);
    }
  }

} // end namespace isis
