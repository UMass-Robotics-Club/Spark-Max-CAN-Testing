# Spark-Max-CAN-Testing

## Notes about CAN (Controller area network)
### General
* Broadcast type bus. Every message is broadcast to every node on the bus. messages are filtered by identifier at start.
* Older version of CAN (1.0) only had a 11 bit identifier but new version (2.0) has 29 bit identifier. We will be using CAN 2.0.
* 3 types of frames
    * Data: Put data onto the CAN bus for everyone else.
    * Remote: Asks for some data with a specific label. Someone else on the CAN bus should respond.
    * Error: An error was detected. This frame violates framing rules so everyone on the bus will also produce an error frame.
    * Type of frame is differentiated by remote transmission request(RTR) bit.
* Each message(frame) has a maximum utility load of 94 bits
    * 29 bit identifier
    * 0-8 byte data
    * 1 bit RTR
### Arbitration
* Done using the 29 bit identifier field. The lowest number has the highest priority.

## Notes about interfacing with Spark Max
* [SPARK Max Configuration Parameters](https://docs.revrobotics.com/brushless/spark-max/parameters)
* [FRC CAN standard](https://docs.wpilib.org/en/stable/docs/software/can-devices/can-addressing.html)

### Identifier Structure
| Device Type | Manufacturer | API Class | API Index | Device ID |
|-------------|--------------|-----------|-----------|-----------|
| 28:24 | 23:16 | 15:10 | 9:6 | 5:0 | 
| Motor Controller: 2 | REV: 5 | Look below | Look below | Spark Max ID |
#### API Class
* Speed Control Mode: 1
* Voltage Compensation Mode: 2
* Position Control Mode: 3
* Current Control Mode: 4
* Status: 5
* Periodic Status:  6
* Configuration: 7
* Ack: 8
#### API Index
* Enable Control: 0
* Disable Control: 1
* Set Setpoint: 2
* P Constant: 3
* I Constant: 4
* D Constant: 5
* Set Reference: 6
* Trusted Enable: 7
* Trusted Set No Ack: 8
* Trusted Set Setpoint No Ack: 10
* Set Setpoint No Ack: 11

# Use external CAN controller? 
Good controller [MCP251863](https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/MCP251863-External-CAN-FD-Controller-with-Integrated-Transceiver-DS20006624.pdf)
Library [acan2517fd](https://docs.arduino.cc/libraries/acan2517fd/#Releases)
