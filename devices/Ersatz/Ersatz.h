/*
 * Ersatz.h - Header for the Ersatz requirements
 */
#ifndef HEADER_ERSATZ
  #define HEADER_ERSATZ

  // Declarations of variables
  extern const int Baud;
  extern const String ID;

  // Declarations of functions
  void ersatzSetup();
  boolean checkErsatzCommand(String command);
  void ersatzActionCommand(String command);
  
#endif
