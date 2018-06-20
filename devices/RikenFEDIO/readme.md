This code is at least slightly bespoke, although it could be easily adapted for any digital only IO

Sets pins 2 to 7 as digital inputs
Sets pins 8 to 13 as digital outputs

It uses the following command protocol via the Serial port:

| *Send* | *Receive* | *Notes* |
| --- | --- | --- |
|*IDN?|`RIKENFE Prototype v1.0`|There are changes planned to the protocol which may invlve that number changing|
|STATUS|The error string|The error string is `No Error` or a string detailing the error|
|ERR|The error string|The error string is `No Error` or a string detailing the error|
|READ n|`True` or `False`|n is a digit for the hardcoded list of digital inputs|
|WRITE n state|`OK` or `Error`|n is a digit for the hardcoded list of digital outputs, state is `TRUE` or `FALSE`|

Serial settings are 9600,8,None,1 with no flow control.
