int right_1=27;
int right_2=26;
int left_1=22;
int left_2=23;

int right_en=24;
int left_en=25;

int right_pwm_pin=3;
int left_pwm_pin=2;
int right_pwm=150;
int left_pwm=150;

int right_out_A=10;
int right_out_B=11;
int left_out_A=8;
int left_out_B=9;

void setup() {
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  pinMode(right_pwm_pin,OUTPUT);
  pinMode(left_pwm_pin,OUTPUT);
  pinMode(right_en,OUTPUT);
  pinMode(left_en,OUTPUT);
}

void loop() {
  digitalWrite(right_1,HIGH);
  digitalWrite(right_2,LOW);
  
  digitalWrite(left_1,HIGH);
  digitalWrite(left_2,LOW);

  digitalWrite(right_en,HIGH);
  digitalWrite(left_en,HIGH);
  
  analogWrite(right_pwm_pin,right_pwm);
  analogWrite(left_pwm_pin,left_pwm);

}
