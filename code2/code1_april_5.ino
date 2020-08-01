int right_1=26;
int right_2=27;
int left_1=23;
int left_2=24;

int right_en=24;
int left_en=25;

int right_pwm_pin=3;
int left_pwm_pin=2;
int right_pwm=60;
int left_pwm=60;

int right_out_A=10;
int right_out_B=11;

int left_out_A=8;
int left_out_B=9;

int right_encoder_A=20;
int right_encoder_B=21;
int left_encoder_A=18;
int left_encoder_B=19;

volatile unsigned long leftCount = 0;
volatile unsigned long rightCount = 0;

int left_trig=33;
int left_echo=32;

int right_trig=4;
int right_echo=5;

int front_trig=30;
int front_echo=31;

long left_duration=0;
int left_distance=0;

long right_duration=0;
int right_distance=0;

long front_duration=0;
int front_distance=0;

void setup() {
  Serial.begin(9600);
  pinMode(right_encoder_A,INPUT);
  pinMode(right_encoder_B,INPUT);
  pinMode(left_encoder_A,INPUT);
  pinMode(left_encoder_B,INPUT);
  
  attachInterrupt(0, leftEncoderEvent, CHANGE);
  attachInterrupt(1, rightEncoderEvent, CHANGE);

  digitalWrite(right_en,HIGH);
  digitalWrite(left_en,HIGH);
  
  pin_define();
}

void loop() {
  wall_follow_sense();
  wall_follow_algo();
 // go_forward();
/*
  Serial.print("Right Count: ");
  Serial.println(rightCount);
  Serial.print("Left Count: ");
  Serial.println(leftCount);
  Serial.println();
  delay(500);
  */

}
