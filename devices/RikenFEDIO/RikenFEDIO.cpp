/*
 * RikenFEDIO.cpp - Code for the RIKEN DIO requirements
 */
#include "Arduino.h"
#include "ISISIO.h"
#include "ISISStandard.h"
#include "ISISSerial.h"

// Define the external constants
extern const int Baud = 9600;
extern const String ID = "RIKENFE Prototype v2.0"; // ID string for verification of code

// Define internal constants
String OK = "OK";
int digitalInputs[] = {2, 3, 4, 5, 6, 7}; // List of the pins set to use as inputs
int digitalOutputs[] = {8, 9, 10, 11, 12, 13}; // List of the pins set to use as outputs
String rikendioCommands[] = {"READ", "WRITE"};

// Setup sepcific to the device
void rikendioSetup() {  
  // Ensure that the input pins in the list are all set as input
  for (int i = 0; i < sizeof(digitalInputs)/sizeof(digitalInputs[0]); i++) {
    isis::setDigitalIn(digitalInputs[i]);
  }
  // Ensure that the output pins in the list are all set as output
  for (int i = 0; i < sizeof(digitalOutputs)/sizeof(digitalOutputs[0]); i++) {
    isis::setDigitalOut(digitalOutputs[i]);
  }
}

// Read a pin
void rikendioReadPin(int pin) {
  // Check that the pin is the list of readable pins (setup as an Input)
  if (!isis::valueInArray(pin, digitalInputs, sizeof(digitalInputs)/sizeof(digitalInputs[0]))) {
    isis::setError("The pin is not readable");
    return;
  }
  // Write the status of the pin
  isis::serialWriteLine(isis::readDigitalString(pin));
  // The errors are cleared on succesful completion of any task
  isis::clearError();
}

// Write to a pin
void rikendioWritePin(int pin, String state) {
  // Check that the pin is the list of writable pins (setup as an Output)
  if (!isis::valueInArray(pin, digitalOutputs, sizeof(digitalOutputs)/sizeof(digitalOutputs[0]))) {    
    isis::setError("The pin is not writeable");
    return;
  }
  // If the value given is suitable write the appropriate value, otherwise raise an error
  if (state == "TRUE" || state == "FALSE") {
    isis::writeDigitalString(pin, state);
  }
  else {
    String forError;
    forError += "Cannot set pin ";
    forError += pin;
    forError += " to ";
    forError += state;
    isis::setError(forError);
    return;
  }
  // Display the status so that something is always returned after a command
  isis::serialWriteLine(OK);
  // The errors are cleared on succesful completion of any task
  isis::clearError();
}

// Use this to decide if the command is in the list of device specific commands
// This code loops through the command list and checks the start of the command against the allowed values
boolean checkRikendioCommand(String command) {
  boolean rikendioCommand = false;
  for (int i = 0; i < sizeof(rikendioCommands)/sizeof(rikendioCommands[0]) ; i++) {
    String checking = command.substring(0, rikendioCommands[i].length());
    if (checking == rikendioCommands[i]) { 
      rikendioCommand = true; 
      break;
      }
  }
  return rikendioCommand;
}

// Undertake the actions necessary for the commands in the list
void rikendioActionCommand(String command) {
  // Can add more error checking for the commands here, e.g. "READ Q" returns a True rather than being an error
  // Undertake a read
  if (command.substring(0, 4) == "READ") {
    rikendioReadPin(command.substring(command.indexOf(" ")).toInt());
  }
  // Undertake a write
  else if (command.substring(0, 5) == "WRITE"){
    rikendioWritePin(command.substring(command.indexOf(" ") , command.indexOf(" ", command.indexOf(" ") + 1)).toInt(), command.substring(command.lastIndexOf(" ") + 1));
  }
}

