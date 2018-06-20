#ifndef HEADER_ISISIO
  #define HEADER_ISISIO

  void isisSetDigitalOut(int pin);
  void isisSetDigitalIn(int pin);
  String isisReadDigitalString(int pin);
  void isisWriteDigitalString(int pin, String state);
  String isisReadDigitalStringInvert(int pin);
  void isisWriteDigitalStringInvert(int pin, String state);
  
#endif
