#include "Arduino.h"
#include "ISISIO.h"
#include "ISISStandard.h"
#include "ISISSerial.h"

extern const int Baud = 9600;
extern const String ID = "RIKENFE Prototype v2.0"; // ID string for verification of code
extern const String OK = "OK";
extern int digitalInputs[] = {2, 3, 4, 5, 6, 7}; // List of the pins set to use as inputs
extern int digitalOutputs[] = {8, 9, 10, 11, 12, 13}; // List of the pins set to use as outputs
extern String rikendioCommands[] = {"READ", "WRITE"};

void rikendioSetup() {  
  // Ensure that the input pins in the list are all set as input
  for (int i = 0; i < sizeof(digitalInputs)/sizeof(digitalInputs[0]); i++) {
    isisSetDigitalIn(digitalInputs[i]);
  }
  // Ensure that the output pins in the list are all set as output
  for (int i = 0; i < sizeof(digitalOutputs)/sizeof(digitalOutputs[0]); i++) {
    isisSetDigitalOut(digitalOutputs[i]);
  }
}

void rikendioReadPin(int pin) {
  if (!isisValueInArray(pin, digitalInputs, sizeof(digitalInputs)/sizeof(digitalInputs[0]))) {
    isisSetError("The pin is not readable");
    return;
  }
  isisSerialWriteLine(isisReadDigitalString(pin));
  // The errors are cleared on succesful completion of any task
  isisClearError();
}

void rikendioWritePin(int pin, String state) {
  if (!isisValueInArray(pin, digitalOutputs, sizeof(digitalOutputs)/sizeof(digitalOutputs[0]))) {    
    isisSetError("The pin is not writeable");
    return;
  }
  // If the value given is suitable write the appropriate value, otherwise raise an error
  if (state == "TRUE" || state == "FALSE") {
    isisWriteDigitalString(pin, state);
  }
  else {
    String forError;
    forError += "Cannot set pin ";
    forError += pin;
    forError += " to ";
    forError += state;
    isisSetError(forError);
    return;
  }
  // Display the status so that something is always returned after a command
  isisSerialWriteLine(OK);
  // The errors are cleared on succesful completion of any task
  isisClearError();
}

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

