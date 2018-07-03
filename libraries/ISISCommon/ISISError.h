/*
 * ISISError.h - Header for the ISIS Error class
 */
// Only define the header if it hasn't been defined previously
#ifndef HEADER_ISISERROR
  // Define the header information
  #define HEADER_ISISERROR

  // Use the ISIS namespace
  namespace  isis {
    // Declare the Error class
    class ISISError {
      public:
        // Initialise error class values
        ISISError();
        // Functions to perform on the error
        void errorDisplay( void );
        void setError(String reason);
        void clearError();
      private:
        // Variables kept private
        String _errorMessage;
        boolean _errorState;
    };
  
  } // end namespace isis
   
#endif // end if header not defined
