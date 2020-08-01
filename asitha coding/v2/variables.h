int Error_values[8] = {-3, -2, -1, 0, 0, 1, 2, 3};

int left_speed,right_speed;

//sensor values
int S0,S1,S2,S3,S4,S5,S6,S7,S8,S9;

int IR_pin[8]={A6,A7,A8,A9,A10,A11,A12,A13};

int sensor_reading_array[8] = { 0 };

float Error=0;
float previousError = 0;
float totalError = 0;
float power = 0;
