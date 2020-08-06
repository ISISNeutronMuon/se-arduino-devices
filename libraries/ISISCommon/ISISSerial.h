/*
 * ISISSerial.h - Header for the serial interactions
 */
// Only define the header if it hasn't been defined previously
#ifndef HEADER_ISISSERIAL
  #define HEADER_ISISSERIAL

  // Use the ISIS namespace
  namespace  isis {
    // Declarations of functions
    void serialInit (int Baud);
    void serialWrite (String SendString);
    void serialWriteLine (String SendString);
    boolean serialAvailable ( void );
    String serialRead ( void );
   
  } // end namespace isis
  
#endif // end if header not defined
