#include "Arduino.h"

namespace  isis {
  void serialInit (int Baud) {
    Serial.begin(Baud);
  }

  void serialWrite (String SendString) {
    Serial.print(SendString);
  }

  void serialWriteLine (String SendString) {
    Serial.println(SendString);
  }

  boolean serialAvailable ( void ) {
    return Serial.available() > 0;
  }

  String serialRead ( void ) {
    String received = Serial.readStringUntil('\n');
    // remove any carriage returns that may exist - for ease of comms with hyperterm and putty
    received.replace("\r","");
    return received;
  }

} // end namespace isis
