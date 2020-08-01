#define Left_Dir1 27
#define Left_Dir2 25 
#define Left_A 18
#define Left_B 19
#define Left_en 26
#define Left_Speed 10
#define Right_Dir1 29
#define Right_Dir2 28
#define Right_A 2
#define Right_B 3
#define Right_en 24
#define Right_Speed 11


const int ftrigPin = A1;
const int fechoPin = A0;

const int ltrigPin = 31;
const int lechoPin = 30;

const int rtrigPin = 13;
const int rechoPin = 12;



/**********************colour sensor pins defining***************************/
#define S0 44
#define S1 45
#define S2 43
#define S3 42
#define sensorOut 41
/**********************colour sensor pins defining over***************************/


/**********************led indicators pins defining***************************/
int green_led_pin=15; //red wire
int red_led_pin=16; //orange wire
int blue_led_pin=17; //yellow wire
/**********************led indicators pins defining***************************/


/**********************water pump pins defining***************************/
//water pump motor driver L298n pins
int water_pump_dir_1=52;
int water_pump_dir_2=53;
/**********************water pump pins defining over***************************/


/**********************buzzer pins defining***************************/
//buzzer [postive pin
const int pinTone = 9;
/**********************buzzer pins defining over***************************/


/**********************servo motors pins defining***************************/
int gate_servo = 4;
int coin_arm_servo = 5;
int coin_magnet_servo = 7;
int water_arm_servo = 6;
/**********************servo motor pins defining over***************************/
