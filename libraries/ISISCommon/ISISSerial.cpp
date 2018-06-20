#include "Arduino.h"

void isisSerialInit (int Baud) {
  Serial.begin(Baud);
}

void isisSerialWrite (String SendString) {
  Serial.print(SendString);
}

void isisSerialWriteLine (String SendString) {
  Serial.println(SendString);
}

boolean isisSerialAvailable ( void ) {
  return Serial.available() > 0;
}

String isisSerialRead ( void ) {
  String received = Serial.readStringUntil('\n');
  // remove any carriage returns that may exist - for ease of comms with hyperterm and putty
  received.replace("\r","");
  return received;
}

