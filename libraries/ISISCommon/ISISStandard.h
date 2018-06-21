#ifndef HEADER_STANDARD
  #define HEADER_STANDARD
  
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
     
#endif
