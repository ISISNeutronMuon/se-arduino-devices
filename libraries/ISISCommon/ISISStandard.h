/*
 * ISISStandard.h - Header for the standard ISIS functions
 */
// Only define the header if it hasn't been defined previously
#ifndef HEADER_STANDARD
  #define HEADER_STANDARD
  
	// Use the ISIS namespace
  namespace  isis {
    // Declarations of variables
    extern String _ID;
	
    // Declarations of functions
    boolean valueInArray(int value, int values[], int size);
    boolean valueInArray(String value, String values[], int size);
    void actionStandardCommand(String command);
    void clearError();
    void setError(String errorString);
    boolean checkIsisStandardCommand(String command);
  } // End namespace isis
     
#endif // end if header not defined
