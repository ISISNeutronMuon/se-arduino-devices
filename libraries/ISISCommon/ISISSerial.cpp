/*
 * ISISSerial.cpp - Code for Serial interactions
 */
#include "Arduino.h"

// Use the ISIS namespace
namespace  isis {
  // Initialise the serial port
  void serialInit (int Baud) {
    Serial.begin(Baud);
  }

  // Send a string to the serial port without a line feed
  void serialWrite (String SendString) {
    Serial.print(SendString);
  }

  // Send a string to the serial port with a line feed
  void serialWriteLine (String SendString) {
    Serial.println(SendString);
  }

  // Returns 1/TRUE if there is any data available at the serial port, otherwise returns 0/FALSE
  boolean serialAvailable ( void ) {
    return Serial.available() > 0;
  }

  // Reads from serial line until it finds a \n, removes any \r characters and returns the data received
  String serialRead ( void ) {
    String received = Serial.readStringUntil('\n');
    // remove any carriage returns that may exist - for ease of comms with hyperterm and putty
    received.replace("\r","");
    return received;
  }

} // end namespace isis
