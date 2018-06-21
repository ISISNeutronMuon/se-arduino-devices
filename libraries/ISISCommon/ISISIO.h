#ifndef HEADER_ISISIO
  #define HEADER_ISISIO

  namespace  isis {
    // Declarations of functions
    void setDigitalOut(int pin);
    void setDigitalIn(int pin);
    String readDigitalString(int pin);
    void writeDigitalString(int pin, String state);
    String readDigitalStringInvert(int pin);
    void writeDigitalStringInvert(int pin, String state);
  
  } // end namespace isis
  
#endif
