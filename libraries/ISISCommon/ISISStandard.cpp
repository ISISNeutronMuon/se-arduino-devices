#include "Arduino.h"
#include "ISISError.h"
#include "ISISSerial.h"
#include "ISISStandard.h"

extern String isisStandardCommands[] = {"*IDN?", "STATUS", "ERR"};
extern String _ID = "Undefined type";
ISISError Error;

boolean isisValueInArray(int value, int values[], int size) {
  boolean inArray = false;
  for (int i = 0; i < size; i++) {
    if (values[i] == value) { 
      inArray = true; 
      break;
      }
  }
  return inArray;
}

boolean isisValueInArray(String value, String values[], int size) {
  boolean inArray = false;
  for (int i = 0; i < size; i++) {
    if (values[i] == value) { 
      inArray = true; 
      break;
      }
  }
  return inArray;
}

void isisActionStandardCommand(String command) {
  // Display the ID
  if (command == "*IDN?") {
    isisSerialWriteLine(_ID);
    isisClearError(); // Clear error after every successful command
  }
  // Display the status
  else if (command == "STATUS") {
    Error.errorDisplay();
  }
  // Display error details
  else if (command == "ERR") {
    Error.errorDisplay();
  }
}

void isisClearError() {
  Error.clearError();
}

void isisSetError(String errorString){
  Error.setError(errorString);
}

boolean checkIsisStandardCommand(String command) {
  return isisValueInArray(command, isisStandardCommands, sizeof(isisStandardCommands)/sizeof(isisStandardCommands[0]));
}

