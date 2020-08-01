int right_1=26; //Righ motor output 1
int right_2=27; //Righ motor output 2
int left_1=23;  //Left motor output 1
int left_2=24;  //left motor output 2

int right_en=24; //right motor enable pin
int left_en=25;  //Left motor enable pin

int right_pwm_pin=3; //right motor pwm pin
int left_pwm_pin=2;  //left motor pwm pin
int right_pwm=60;    //right motor pwm speed
int left_pwm=60;     //left motor pwm speed

int right_encoder_A=20;  //right encoder A
int right_encoder_B=21;  //right encoder B
int left_encoder_A=18;   //left encoder A
int left_encoder_B=19;   //left encoder B

volatile unsigned long leftCount = 0;  //Encoder count for left motor
volatile unsigned long rightCount = 0; //Encoder count for right motor

int left_trig=33; //left zonar sensor trigger pin
int left_echo=32; //left zonar senosr echo pin

int right_trig=4; //right zonar sensor trigger pin
int right_echo=5; //left zonar sensor echo pin

int front_trig=30; //fornt zonar sensor trigger pin 
int front_echo=31; //fornt zonar sensor echo pin

long left_duration=0; //left zonar sensor time to be calculated the distance
int left_distance=0;  //distance of left zonar sensor reading

long right_duration=0;  //right zonar sensor time to be calculated the distance
int right_distance=0;   //distance of right zonar sensor reading

long front_duration=0;  //front zonar sensor time to be calculated the distance
int front_distance=0;   //distance of front zonar sensor reading
