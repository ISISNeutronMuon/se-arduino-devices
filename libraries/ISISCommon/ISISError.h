#ifndef HEADER_ISISERROR
  #define HEADER_ISISERROR

  namespace  isis {
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
  
  } // end namespace isis
   
#endif
