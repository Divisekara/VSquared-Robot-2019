void water_pump(){
  pinMode(water_pump_dir_1, OUTPUT);
  pinMode(water_pump_dir_2, OUTPUT);
  digitalWrite(52,HIGH);
  digitalWrite(53,LOW); 
  delay(3000);
  digitalWrite(52,LOW);
  digitalWrite(53,LOW); 
  }
