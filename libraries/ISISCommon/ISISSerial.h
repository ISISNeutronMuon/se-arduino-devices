#ifndef HEADER_ISISSERIAL
  #define HEADER_ISISSERIAL

  namespace  isis {
    // Declarations of functions
    void serialInit (int Baud);
    void serialWrite (String SendString);
    void serialWriteLine (String SendString);
    boolean serialAvailable ( void );
    String serialRead ( void );
   
  } // end namespace isis
  
#endif
