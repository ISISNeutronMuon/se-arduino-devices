/*
 * This is the primary sketch for the RIKEN DIO requirements
 */
#include "ISISSerial.h"
#include "Ersatz.h"
#include "ISISStandard.h"

void setup() {
  // Baud is defined in RikenFEDIO.cpp
  isis::serialInit(Baud);

  // _ID is the ISIS Standard variable, ID is defined in RikenFEDIO.cpp
  isis::_ID = ID;
  
  // call the setup required for the specific purpose of the device
  ersatzSetup();
}

void loop() {
  // Respond to items on the Serial line
  if (isis::serialAvailable()) {
    commandAction(isis::serialRead());
  }
  // isis::serialWriteLine("Loop");
}

// Decode and undertake the appropriate commands
void commandAction(String command) {
  command.toUpperCase(); // Convert to upper case for ease of coding

  // If it is an ISIS standard command as defined in the ISIS Standard files in the libraries use those libraries to action the commands
  if (isis::checkIsisStandardCommand(command)) {
    isis::actionStandardCommand(command);
  }
  // To keep this sketch simple, and allow for multiple applications within the same one deal with the device commands specifically
  else if (checkErsatzCommand(command)) {
    ersatzActionCommand(command);
  }
  else {
    isis::setError("Command not recognised");
  }
}
