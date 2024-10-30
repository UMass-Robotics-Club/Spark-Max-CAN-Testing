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
* Because it is a bus, nodes can interfere with each other.
### Arbitration
* Done using the 29 bit identifier field

# Use external CAN controller? 
https://ww1.microchip.com/downloads/aemDocuments/documents/APID/ProductDocuments/DataSheets/MCP251863-External-CAN-FD-Controller-with-Integrated-Transceiver-DS20006624.pdf 