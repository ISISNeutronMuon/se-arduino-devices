#include "Arduino.h"
#include "ISISError.h"
#include "ISISSerial.h"

namespace  isis {
  ISISError::ISISError() {
    _errorState = true;
    _errorMessage = "No error";
  }

  void ISISError::errorDisplay( void ){
    isis::serialWriteLine(_errorMessage);
  }

  void ISISError::setError(String reason) {
    _errorState = true;
    _errorMessage = reason;
    isis::serialWriteLine("ERROR");
  }

  void ISISError::clearError() {
    _errorState = true;
    _errorMessage = "No error";
  }

} // end namespace isis