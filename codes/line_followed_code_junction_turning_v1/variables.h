int left_speed,right_speed;

//least pwm can be 70
//maximum can be 255
int base_pwm=60;

int black=0;

//sensor values
//S0-right most S9-left most
int S0,S1,S2,S3,S4,S5,S6,S7,S8,S9;
int IR_pin[8]={A6,A7,A8,A9,A10,A11,A12,A13};
int sensor_reading_array[8] = { 0 };



int pos1 = 0;
int pos2 = 0;
int pos3 = 0;


String TEXT;
