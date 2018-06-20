#ifndef HEADER_ISISSERIAL
  #define HEADER_ISISSERIAL

  void isisSerialInit (int Baud);
  void isisSerialWrite (String SendString);
  void isisSerialWriteLine (String SendString);
  boolean isisSerialAvailable ( void );
  String isisSerialRead ( void );
   
#endif
