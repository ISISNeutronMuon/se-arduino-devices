#include "Arduino.h"
#include "ISISError.h"
#include "ISISSerial.h"

ISISError::ISISError() {
  _errorState = true;
  _errorMessage = "No error";
}

void ISISError::errorDisplay( void ){
  isisSerialWriteLine(_errorMessage);
}

void ISISError::setError(String reason) {
  _errorState = true;
  _errorMessage = reason;
  isisSerialWriteLine("ERROR");
}

void ISISError::clearError() {
  _errorState = true;
  _errorMessage = "No error";
}
