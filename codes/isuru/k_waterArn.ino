void waterArm()
{
  for(pos4 = 0; pos4 < 100; pos4 += 1)
  {
    myservo4.write(pos4);
    delay(20);
  }
  delay(1000);
  for(pos4 = 100; pos4 > 0; pos4 -= 1){
    myservo4.write(pos4);
    delay(20);
  }
  delay(1000);
}
