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

void setup() {
  Serial.begin(9600);
  pinMode(right_encoder_A,INPUT);
  pinMode(right_encoder_B,INPUT);
  pinMode(left_encoder_A,INPUT);
  pinMode(left_encoder_B,INPUT);
  
  attachInterrupt(0, leftEncoderEvent, CHANGE);
  attachInterrupt(1, rightEncoderEvent, CHANGE);

  pin_define();
}

void loop() {
  go_forward();
  analogWrite(right_pwm_pin,right_pwm);
  analogWrite(left_pwm_pin,left_pwm);

  Serial.print("Right Count: ");
  Serial.println(rightCount);
  Serial.print("Left Count: ");
  Serial.println(leftCount);
  Serial.println();
  delay(500);

}
