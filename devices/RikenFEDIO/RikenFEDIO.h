#ifndef HEADER_RIKENDIO
  #define HEADER_RIKENDIO

  extern const int Baud;
  extern const String ID;
  extern const String OK;
  extern int digitalInputs[];
  extern int digitalOutputs[];
  void rikendioSetup();
  void rikendioReadPin(int pin);
  void rikendioWritePin(int pin, String state);
  boolean checkRikendioCommand(String command);
  void rikendioActionCommand(String command);
  
#endif
