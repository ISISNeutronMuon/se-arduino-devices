/*
 * ISISIO.cpp - Code for input and output
 */
#include "Arduino.h"

// Use the ISIS namespace
namespace  isis {
  // Set specified pin to be an output
  void setDigitalOut(int pin) {
    pinMode(pin, OUTPUT);
  }

  // Set specified pin to be an input
  void setDigitalIn(int pin) {
    pinMode(pin, INPUT);
  }

  // Convert returned pin value to a TRUE or FALSE string, 1 = TRUE, 0 = FALSE
  String readDigitalString(int pin) {
    return (digitalRead(pin) ? "TRUE" : "FALSE");
  }

  // Set pin to HIGH/LOW based on a TRUE or FALSE string, 1 = TRUE, 0 = FALSE
  void writeDigitalString(int pin, String state) {
    if (state == "TRUE") {
      digitalWrite(pin, HIGH);
    }
    else if (state == "FALSE") {
      digitalWrite(pin, LOW);
    }
  }

  // Convert returned pin value to a TRUE or FALSE string, inverted, 1 = FALSE, 0 = TRUE
  String readDigitalStringInvert(int pin) {
    return (digitalRead(pin) ? "FALSE" : "TRUE");
  }

  // Set pin to HIGH/LOW based on a TRUE or FALSE string, 1 = FALSE, 0 = TRUE
  void writeDigitalStringInvert(int pin,String state) {
    if (state == "TRUE") {
      digitalWrite(pin, LOW);
    }
    else if (state == "FALSE") {
      digitalWrite(pin, HIGH);
    }
  }

} // end namespace isis
