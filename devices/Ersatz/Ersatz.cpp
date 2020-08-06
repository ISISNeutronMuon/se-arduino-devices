/*
 * RikenFEDIO.cpp - Code for the RIKEN DIO requirements
 */
#include "Arduino.h"
#include "ISISIO.h"
#include "ISISStandard.h"
#include "ISISSerial.h"

// Define the external constants
extern const int Baud = 9600;
extern const String ID = "Ersatz - Stacia V2.0"; // ID string for verification of code

// Define internal constants
String OK = "OK";
String ersatzCommands[] = {"RNAME", "RSP", "WSP", "RPV", "RST", "REV", "WEV"};
float setPoint = 2;
float echoValue = 0;
int randNumber;

// Setup sepcific to the device
void ersatzSetup() {  
  randomSeed(analogRead(0));
}

// Use this to decide if the command is in the list of device specific commands
// This code loops through the command list and checks the start of the command against the allowed values
boolean checkErsatzCommand(String command) {
  boolean ersatzCommand = false;
  for (int i = 0; i < sizeof(ersatzCommands)/sizeof(ersatzCommands[0]) ; i++) {
    String checking = command.substring(0, ersatzCommands[i].length());
    if (checking == ersatzCommands[i]) { 
      ersatzCommand = true; 
      break;
      }
  }
  return ersatzCommand;
}

// Undertake the actions necessary for the commands in the list
void ersatzActionCommand(String command) {
  if (command == "RNAME") {
    isis::serialWriteLine(ID);
    }
  else if (command == "RSP") {
    isis::serialWriteLine(String(setPoint));
    }
  else if (command.substring(0, 3) == "WSP") {
    setPoint = (command.substring(4, command.length())).toFloat();
    }
  else if (command == "RPV") {
    randNumber = random(100);
    isis::serialWriteLine(String(randNumber));
    }
  else if (command == "RST") {
    setPoint = 2;
    echoValue = 0;
    }
  else if (command == "REV") {
    isis::serialWriteLine(String(echoValue));
    }
  else if (command.substring(0, 3) == "WEV") {
    echoValue = (command.substring(4, command.length())).toFloat();
    isis::serialWrite("wev ");
    isis::serialWriteLine(String(echoValue));
    }
}
