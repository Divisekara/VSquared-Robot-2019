void buzzer_code(){
    curTime = millis();
    Serial.println(totalNotes);
    for (int i=0; i<5000; i++){
      noteIndex++;
      tonePrevTime = curTime;
      noTone(pinTone);
      tone(pinTone, aNotes[noteIndex].note, aNotes[noteIndex].tempo);
      noteDelay = aNotes[noteIndex].tempo;
      Serial.println(noteDelay);
      delay(noteDelay);
    }
}
