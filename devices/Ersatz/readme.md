This is a code to allow a uno to behave as a serial comms driven device for use in testing and demonstrations.

This interacts with the data set of a fictional device called Stacia, which has the following command set:

| *Send* | *Receive* | *Notes* |
| --- | --- | --- |
| *IDN? | Ersatz - Stacia V2.0 | |
| rname | Stacia | |
| rpv | A random number between 0 and 100 | Read the present value |
| rsp | The setpoint number | Read the setpoint number, the default is “2” |
| wsp | | Write a value to the setpoint |
| rev | The echo value number | Read the echo value, the default is “0” |
| wev | | Write a value that is echoed back immediately |
| rst | | Reset the instrument, puts the setpoint and echo to their default values |

Serial settings are 9600,8,None,1 with no flow control.
