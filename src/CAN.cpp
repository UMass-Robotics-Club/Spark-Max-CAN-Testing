typedef struct [[gnu::packed]] CANFrame_t {
    unsigned char device_type : 5;
    unsigned char manufacturer_code : 8;
    API_Class_e API_class : 6;
    API_Index_e index : 4;
    unsigned char device_number : 6;
} CANFrame_t;

typedef enum API_Class_e {
    VOLTAGE_CONTROL_MODE,
    SPEED_CONTROL_MODE,
    VOLTAGE_COMPENSATION_MODE,
    POSITION_CONTROL_MODE,
    CURRENT_CONTROL_MODE,
    STATUS,
    PERIODIC_STATUS,
    CONFIGURATION,
    ACK
} API_Class_e;

typedef enum API_Index_e {
    ENABLE_CONTROL,
    DISABLE_CONTROL,
    SET_SETPOINT,
    P_CONSTANT,
    I_CONSTANT,
    D_CONSTANT,
    SET_REFERENCE,
    TRUSTED_ENABLE,
    TRUSTED_SET_NO_ACK,
    TRUSTED_SET_SETPOINT_NO_ACK,
    SET_SETPOINT_NO_ACK
} API_Index_e;

