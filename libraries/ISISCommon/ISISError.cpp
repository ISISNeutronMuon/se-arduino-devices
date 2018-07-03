/*
 * ISISError.cpp - Code for managing Errors
 */
#include "Arduino.h"
#include "ISISError.h"
#include "ISISSerial.h"

// Use the isis namespace
namespace  isis {
  // Create an error class which is empty, do not use clear as the operations may be different shuold there be a need to persist errors in the future
  ISISError::ISISError() {
    _errorState = true;
    _errorMessage = "No error";
  }

  // "Display" the error to the serial line
  void ISISError::errorDisplay( void ){
    isis::serialWriteLine(_errorMessage);
  }

  // Update the error so that it is in an error state, and immediatly write the error to the serial line
  void ISISError::setError(String reason) {
    _errorState = true;
    _errorMessage = reason;
    isis::serialWriteLine("ERROR");
  }

  // Clear any errors
  void ISISError::clearError() {
    _errorState = true;
    _errorMessage = "No error";
  }

} // end namespace isis
