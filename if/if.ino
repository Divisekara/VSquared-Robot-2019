int sensor_1
int sensor_2
int sensor_3

int right_1
int right_2
int left_1
int left_2

int right_pwm
int left_pwm

int adc(int Analog){ //Analog to digital converter for ir sensor value
  int digital;
  if (Analog<100){
    digital=0;
    }
  else {
    digital=1;
    }
  return digital;
}

void motor(){
  pinMode(right_1,OUTPUT);
  pinMode(right_2,OUTPUT);
  pinMode(left_1,OUTPUT);
  pinMode(left_2,OUTPUT);
  }

void setup() {
  pinMode(senosr_1,INPUT);
  pinMode(senosr_2,INPUT);
  pinMode(senosr_3,INPUT);

  
}

void loop() {
  
  if sensor 1

}
