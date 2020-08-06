/*
 * ISISIO.h - Header for the IO interactions
 */
// Only define the header if it hasn't been defined previously
#ifndef HEADER_ISISIO
  #define HEADER_ISISIO

  // Use the ISIS namespace
  namespace  isis {
    // Declarations of functions
    void setDigitalOut(int pin);
    void setDigitalIn(int pin);
    String readDigitalString(int pin);
    void writeDigitalString(int pin, String state);
    String readDigitalStringInvert(int pin);
    void writeDigitalStringInvert(int pin, String state);
  
  } // end namespace isis
  
#endif // end if header not defined
