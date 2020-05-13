void Lsonar() 
{
  digitalWrite(ltrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(ltrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ltrigPin, LOW);
  lduration = pulseIn(lechoPin, HIGH);
  Ldistance= lduration*0.034/2;
}

void Fsonar() 
{
  digitalWrite(ftrigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(ftrigPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(ftrigPin, LOW);
  fduration = pulseIn(fechoPin, HIGH);
  Fdistance= fduration*0.034/2;
}

void Rsonar() 
{
  digitalWrite(rtrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(rtrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(rtrigPin, LOW);
  rduration = pulseIn(rechoPin, HIGH);
  Rdistance= rduration*0.034/2;
}

void Sonar_State()
{
  if (Ldistance <= 25.00 ) { 
    Leftstate=1;
  }
  else {
    Lsonar();
    if (Ldistance > 25.00 ){
      Lsonar();
      if (Ldistance > 25.00 ){
        Leftstate = 0;
      }
      else{Leftstate = 1;}
    }
    else{Leftstate = 1;}
  }

  
  if (Fdistance > 8.00 ) {
    Forwardstate = 0;}
  else {
    Fsonar();
    if (Fdistance <= 8.00 ){
      Fsonar();
      if (Fdistance <= 8.00 ){
        Forwardstate = 1;
      }
      else{Forwardstate = 0;}
    }
    else{Forwardstate = 0;}
  }

  if (Rdistance <= 25.00 ) {Rightstate = 1;}
  else {Rightstate = 0;}
}

void Printsonar()
{
  Serial.print(Ldistance);
  Serial.print("   ");

  Serial.print(Fdistance);
  Serial.print("   ");
  
  Serial.print(Rdistance);
  Serial.println("");
}