/*
 * ISISStandard.cpp - Code for ISIS Standard behaviours
 */
#include "Arduino.h"
#include "ISISError.h"
#include "ISISSerial.h"
#include "ISISStandard.h"

// Create constant/defalt values
// List of standard commands
String standardCommands[] = {"*IDN?", "STATUS", "ERR"};
// This _ID should be overwritten by the device code
extern String isis::_ID = "Undefined type";
// Instantiate an error for use within the system
isis::ISISError Error;

// Use the ISIS namespace
namespace isis {
  // Check if an int value is in an array of integers, note that size is passed in so that the whole array can be considered, return 0/FALSE ot 1/TRUE as appropriate
  boolean valueInArray(int value, int values[], int size) {
    // Initialise a variable to return the status
    boolean inArray = false;
    for (int i = 0; i < size; i++) {
      if (values[i] == value) { 
        // Value is in array, so set status to true and break ratehr than loop unnecessarily
        inArray = true; 
        break;
      }
    }
  return inArray;
  }

  // Check if a string value is in an array of string, note that size is passed in so that the whole array can be considered, return 0/FALSE ot 1/TRUE as appropriate
  boolean valueInArray(String value, String values[], int size) {
    // Initialise a variable to return the status
    boolean inArray = false;
    for (int i = 0; i < size; i++) {
      if (values[i] == value) { 
        // Value is in array, so set status to true and break ratehr than loop unnecessarily
        inArray = true; 
        break;
      }
    }
    return inArray;
  }

  // Undertake actions based on a standard command
  // The list of commands is maintained as a constant within this file
  // Note that this is not a switch at present, this would be a change to consider in the future
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

  // Clear the error
  void clearError() {
    Error.clearError();
  }

  // Set the error
  void setError(String errorString){
    Error.setError(errorString);
  }

  // Check if the command is in the list of standard commands
  // Size is calculated as the size of the whole list, which is gien in bytes, devided by the size of the first element to give the size of the data type, this is done to provide the iterator to ensure that every command is considered when checking the array
  boolean checkIsisStandardCommand(String command) {
    return valueInArray(command, standardCommands, sizeof(standardCommands)/sizeof(standardCommands[0]));
  }
} // end namespace isis
