#include "ISISSerial.h"
#include "RikenFEDIO.h"
#include "ISISStandard.h"

// Global Variables
void setup() {
  // Baud should be set up in the specific files
  isisSerialInit(Baud);

  // _ID is the ISIS Standard variable, ID should be set up in the specific files
  _ID = ID;
  
  // call the setup required for the specific purpose of the device
  rikendioSetup();
}

// Note that the assumption here is that it will all be a single threaded application
void loop() {
  // Respond to items on the Serial line
  if (isisSerialAvailable()) {
    commandAction(isisSerialRead());
  }

  // Undertake any specific behaviour
}

// Decode and undertake the appropriate commands
void commandAction(String command) {
  command.toUpperCase(); // Convert to upper case for ease of coding
  
  if (checkIsisStandardCommand(command)) {
    isisActionStandardCommand(command);
  }
  else if (checkRikendioCommand(command)) {
    rikendioActionCommand(command);
  }
  else {
    isisSetError("Command not recognised");
  }
}



