#ifndef HEADER_ISISSTANDARD

  extern String isisStandardCommands[];
  boolean isisValueInArray(int value, int values[], int size);
  boolean isisValueInArray(String value, String values[], int size);
  void isisActionStandardCommand(String command);
  extern String _ID;
  void isisClearError();
  void isisSetError(String errorString);
  boolean checkIsisStandardCommand(String command);
   
#endif
