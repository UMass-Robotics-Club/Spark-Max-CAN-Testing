//Note: This can only generate extended CAN frames (CAN 2.0)

#ifndef CAN_H
#define CAN_H

typedef unsigned char byte;

/**
 * This represents the type of frame we are trying to send.
 */
typedef enum CANFrameType_e {
    // Put data onto the CAN bus for everyone else.
    DATA,
    // Asks for some data with a specific label. Someone else on the CAN bus should respond
    REMOTE,
    // An error was detected. This frame violates framing rules so everyone on the bus will also produce an error frame.
    ERROR
} CANFrameType_e;

/**
 * This represents all of the data inside of an extended CAN frame.
 */
typedef struct CANFrameData_t{
    // The type of frame to transmit.
    CANFrameType_e type;
    // An identifier to specify which nodes on the bus we are trying to talk to.
    // This is also used for arbitration 
    unsigned int identifier : 29;
    // The amount of data to send in bytes (up to 8 bytes)
    byte data_len : 4;
    // The data to send. Can be NULL if there is no data.
    byte* data;
} CANFrame_t;


bool send_frame(CANFrame_t *frame);

#endif