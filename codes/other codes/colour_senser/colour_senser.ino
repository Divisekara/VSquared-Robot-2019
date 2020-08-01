#define S0 44
#define S1 45
#define S2 43
#define S3 42
#define sensorOut 41

#define red 32
#define green 33
#define blue 34

// Stores frequency read by the photodiodes
int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;
int k=0;
int z=0;
int flag = 0;

void setup() {
  // Setting the outputs
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  
  // Setting the sensorOut as an input
  pinMode(sensorOut, INPUT);
  
  // Setting frequency scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
   // Begins serial communication 
  Serial.begin(9600);
  //attachInterrupt(digitalPinToInterrupt(3),intr, RISING);
}


void loop()
{
  // Setting RED (R) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  
  // Reading the output frequency
  redFrequency = pulseIn(sensorOut, LOW);
  
   // Printing the RED (R) value
  Serial.print("R = ");
  Serial.print(redFrequency);
  delay(100);
  
  // Setting GREEN (G) filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  greenFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the GREEN (G) value  
  Serial.print(" G = ");
  Serial.print(greenFrequency);
  delay(100);
 
  // Setting BLUE (B) filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  
  // Reading the output frequency
  blueFrequency = pulseIn(sensorOut, LOW);
  
  // Printing the BLUE (B) value 
  Serial.print(" B = ");
  Serial.print(blueFrequency);
  delay(100);

  if(blueFrequency<greenFrequency){
    if(blueFrequency<redFrequency){
      if(blueFrequency<100){
        Serial.println("  blue");
        digitalWrite(blue,HIGH);
        }
      if(blueFrequency>100){
        Serial.println("");
        }
      }
    }
  if(greenFrequency<blueFrequency){
    if(greenFrequency<redFrequency){
      if(greenFrequency<100){
        Serial.println("  green");
        digitalWrite(green,HIGH);
        }
      if(greenFrequency>100){
        Serial.println("");
        }
      }
    }
  if(redFrequency<greenFrequency){
    if(redFrequency<blueFrequency){
      if(redFrequency<100){
        Serial.println("  red");
        }
      if(redFrequency>100){
        Serial.println("");
        }
      }
    }
 else{
  Serial.println("");
  }  
  delay(100);
  digitalWrite(red,LOW);
  digitalWrite(green,LOW);
  digitalWrite(blue,LOW);
  
}
