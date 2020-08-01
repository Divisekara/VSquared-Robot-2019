#define red 1
#define green 2
#define blue 3
#define power 4

void setup() {
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(power,OUTPUT);
}

void loop() {
  digitalWrite(power,HIGH);
  delay(1000);
  digitalWrite(power,LOW);
  digitalWrite(red,HIGH);
  delay(1000);
  digitalWrite(red,LOW);
  digitalWrite(green,HIGH);
  delay(1000);
  digitalWrite(green,LOW);
  digitalWrite(blue,HIGH);
  delay(1000);
  digitalWrite(blue,LOW);
  
}
