#include "Arduino.h"
#include "ISISError.h"
#include "ISISSerial.h"
#include "ISISStandard.h"

String standardCommands[] = {"*IDN?", "STATUS", "ERR"};
extern String isis::_ID = "Undefined type";
isis::ISISError Error;

namespace isis {
  boolean valueInArray(int value, int values[], int size) {
    boolean inArray = false;
    for (int i = 0; i < size; i++) {
      if (values[i] == value) { 
        inArray = true; 
        break;
      }
    }
  return inArray;
  }

  boolean valueInArray(String value, String values[], int size) {
    boolean inArray = false;
    for (int i = 0; i < size; i++) {
      if (values[i] == value) { 
        inArray = true; 
        break;
      }
    }
    return inArray;
  }

  void actionStandardCommand(String command) {
    // Display the ID
    if (command == "*IDN?") {
      isis::serialWriteLine(isis::_ID);
      isis::clearError(); // Clear error after every successful command
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

  void clearError() {
    Error.clearError();
  }

  void setError(String errorString){
    Error.setError(errorString);
  }

  boolean checkIsisStandardCommand(String command) {
    return valueInArray(command, standardCommands, sizeof(standardCommands)/sizeof(standardCommands[0]));
  }
} // end namespace isis