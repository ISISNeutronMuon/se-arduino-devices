#ifndef HEADER_ISISERROR
  #define HEADER_ISISERROR

  class ISISError {
    public:
      ISISError();
      void errorDisplay( void );
      void setError(String reason);
      void clearError();
    private:
      String _errorMessage;
      boolean _errorState;
  };
   
#endif
