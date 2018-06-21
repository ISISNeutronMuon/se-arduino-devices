/*
 * RikenFEDIO.h - Header for the RIKEN DIO requirements
 */
#ifndef HEADER_RIKENDIO
  #define HEADER_RIKENDIO

  // Declarations of variables
  extern const int Baud;
  extern const String ID;

  // Declarations of functions
  void rikendioSetup();
  void rikendioReadPin(int pin);
  void rikendioWritePin(int pin, String state);
  boolean checkRikendioCommand(String command);
  void rikendioActionCommand(String command);
  
#endif
