encoder_right_A=8;
encoder_right_B=9;
encoder_left_A=10;
encoder_left_B=11;

int encoderValue=0;

void count(void); // code for counting the increasing values of encoder ticks void setup()
{
Serial.begin(9600);
pinMode(21,INPUT);
attachInterrupt(2,count,FALLING);
encoderValue=0;
}

void loop()
{
Serial.print("Starting\n");
// to print encoder value on the screen 
Serial.print("Encoder Value="); 
Serial.println(encoderValue);
}

void count()
{
encoderValue++;
}

/*
void setup() {
  pinMode(encoder_right_A,INPUT);
  pinMode(encoder_right_B,INPUT);
  pinMode(encoder_right_A,INPUT);
  pinMode(encoder_left_B,INPUT);
}

void loop() {

}
*/
