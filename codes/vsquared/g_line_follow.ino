int All_Count = 0;
int Left_Count = 0;
int Right_Count = 0;
int Mid_Count = 0;
bool Left= false;
bool Right= false;

void Count_All()
{
  All_Count = 0;
  for(int i=0; i<10; i++)
  {
    if (sens[i] == 1) {All_Count += 1;}
  }
}

void Count_Left()
{
  Left_Count = 0;
  for(int i=1; i<5; i++)
  {
    if (sens[i] == 1) {Left_Count += 1;}
  }
}

void Count_Right()
{
  Right_Count = 0;
  for(int i=5; i<9; i++)
  {
    if (sens[i] == 1) {Right_Count += 1;}
  }
}

void Count_Mid()
{
  Mid_Count = 0;
  for(int i=1; i<9; i++)
  {
    if (sens[i] == 1) {Mid_Count += 1;}
  }
}



void Line_Follow()
{
  Ir_Sensor();
  Count_Right();
  Count_Left();
  Count_Mid();
  if (Left_Sens == 0 && Right_Sens == 1 && Right_Count ==4)
  {
    Brake();
    delay(50);
    encoderCount = 450;
    encoderForward();
    Brake();
    delay(50);
    Turn_Rightninety_One();
    Brake();
    delay(50);
    //taskCount+=1;
  }
  else if (Left_Sens == 1 && Right_Sens ==0 && Left_Count == 4)
  {
    Brake();
    delay(50);
    encoderCount = 450;
    encoderForward();
    Brake();
    delay(50);
    Turn_Leftninety_One();
    Brake();
    delay(50);
  }
  else
  {
    Line_PID();
    Forward();
  }
 
}

void task()
{
  Ir_Sensor();
  Count_Mid();
  Count_Right();
  Count_Left();
  if (Mid_Count ==8 && Left_Sens == 0 && Right_Sens == 0)
  {
    taskCount +=1;
    Brake();
    delay(1000);
  }

}

void colorTask()
{
  Ir_Sensor();
  Count_Mid();
  if (Mid_Count >= 6)
  {
    taskCount +=1;
    Brake();
    delay(1000);
  }
  
}

void Line_Follow_Without()
{
  Ir_Sensor();
  Line_PID();
  Forward();
}



void lineMaze()
{ 
  Ir_Sensor();
  Count_Mid();
  if (Mid_Count == 8 && Left_Sens == 1 && Right_Sens == 1)
  {
    taskCount = 0;
    encoderCount = 200;
    encoderForward();
  }
  else
  {
    taskCount = -1;
  }
  while (taskCount == 0)
  {
    Line_Follow();
    
  }
  while( taskCount==1){
    Line_Follow_Without();
    task();
  }
  while (taskCount ==2)
  {
    Brake();
    //encoderRight = -70;
    //rightMotorReverse();
    TEXT="2 coin collecting";
    servo_motors();
    //encoderCount = 600;
    //encoderForward();
    Brake();
    delay(500);
        
    while (1)
    {
     Line_Follow_Without();

      if(Left_Sens == 1){Left= true; }
      if(Right_Sens == 1){Right= true; }
            
     if (Left && Right)  //next colour junction found
     
      {Left= false;
      Right= false;
        Brake();
        delay(500);
        //while(1){}
        // colour junction detected. turn to the required path

        
        ///////for green
        if(color==2)
        {
          encoderCount = 150;
          encoderForward();    //untill the junction is passed
          
          while(taskCount==2)
          {
          Ir_Sensor();
           Line_PID();
           Forward();
           colorTask();
                        //// the unloading box found - now taskCount=2
          }
          //////// dropping the coin
          Brake();
          delay(500);
          forward_coin_drop();
          Brake();
          delay(500);
          gate_servo();
          delay(500);

          while(1)
          {
            Ir_Sensor();
           Line_PID();
           Forward();
            if (Left_Sens == 1 && Right_Sens == 1)  //next colour junction found
            {
              break;
            }
          }
          encoderCount = 200;
          encoderForward();   //untill the junction is passed
          taskCount=3;
          break;
          
          
        }

        //////////// for red
        if(color==3)
        {
        

          encoderCount = 100;
          encoderForward();    //untill the junction is passed
          encoderLeft = 450;
          leftMotor();
          
          y=0;
          while(y<700)
          {
           Ir_Sensor();
           Count_Mid();
           if (Last_Mid == 1 && Mid_Count == 0 )
            {
              while(sens[4] == 0)
              {
                Turn_Left();
                Ir_Sensor();
              }
            }
            else if(Last_Mid == 2 && Mid_Count == 0)
            {
             while(sens[4] == 0)
              {
                Turn_Right();
                Ir_Sensor();
              } 
             }
            else
            {
              Red_Line_PID();
              Forward();
            }
            
            Red_Line_PID();
            Forward();
           y++; //// the unloading box found - now taskCount=2
          }
          
          while(1){
          //////// dropping the coin
          Brake();
          delay(500);
          encoderCount = -300;
          encoderReverse();
          gate_servo(); 
          delay(500);
          break;
          }
          while(1)
          {
            Ir_Sensor();
            Count_Mid();
            if (Last_Mid == 1 && Mid_Count == 0 )
            {
              while(sens[4] == 0)
              {
                Turn_Left();
                Ir_Sensor();
              }
            }
            else if(Last_Mid == 2 && Mid_Count == 0)
            {
             while(sens[5] == 0)
              {
                Turn_Right();
                Ir_Sensor();
              } 
             }
            else
            {
              Red_Line_PID();
              Forward();
            }
            if(Left_Sens == 1){Left= true; }
            if(Right_Sens == 1){Right= true; }
            
            if (Right)  //next colour junction found
            {
              Brake();
              break;
            }
            Left= false;
            Right= false;
          }
          encoderCount = 100;
          encoderForward();    //untill the junction is passed
          encoderLeft = 450;
          leftMotor();
          encoderCount = 150;
          encoderForward();   //untill the junction is passed
          taskCount=3;
          
          break;
          
          
        }


        ///////for blue
        if(color==1)
        {
        

          encoderCount = 100;
          encoderForward();    //untill the junction is passed
          encoderRight = 450;
          rightMotor();
          
          while(y<700)
          {
           Ir_Sensor();
           Count_Mid();
           if (Last_Mid == 1 && Mid_Count == 0 )
            {
              while(sens[3] == 0)
              {
                Turn_Left();
                Ir_Sensor();
              }
            }
            else if(Last_Mid == 2 && Mid_Count == 0)
            {
             while(sens[6] == 0)
              {
                Turn_Right();
                Ir_Sensor();
              } 
             }
            else
            {
              Red_Line_PID();
              Forward();
            }
           y++;//// the unloading box found - now taskCount=2
          }
          while(1){
          //////// dropping the coin
          Brake();
          delay(500);
          encoderCount = -200;
          encoderReverse();
          gate_servo(); 
          delay(500);
          encoderCount = 400;
          encoderForward();
          break;
          }
          while(1)
          {
            Ir_Sensor();
            Count_Mid();
            if (Last_Mid == 1 && Mid_Count == 0 )
            {
              while(sens[4] == 0)
              {
                Turn_Left();
                Ir_Sensor();
              }
            }
            else if(Last_Mid == 2 && Mid_Count == 0)
            {
             while(sens[5] == 0)
              {
                Turn_Right();
                Ir_Sensor();
              } 
             }
            else
            {
              Red_Line_PID();
              Forward();
            }
            if(Left_Sens == 1)
            {Left= true; }
            if(Right_Sens == 1)
            {Right= true; }
            
            if (Left)  //next colour junction found
            {
              Brake();
              //while(1){}
              break;
            }
            Left= false;
            Right= false;
          }
          encoderCount = 100;
          encoderForward();    //untill the junction is passed
          encoderRight = 450;
          rightMotor();
          encoderCount = 150;
          encoderForward();   //untill the junction is passed
          taskCount=3;
          
          break;
          
          
        } 
        
      } 
      
    }

  }

  
  while(taskCount==3)
    {
      Line_Follow();
    }
  while (taskCount == 4)
  {
    encoderCount = 700;
    encoderForward();
    taskCount =5;
  }

}
  





/*   
    
  }
  while (taskCount == 2)
  {
    Line_Follow();
    task();
  }
  while (taskCount ==3)
  {
     if (color==2)
     {//green
      encoderCount = 300;
      encoderForward();
      delay(500);
     }
     taskCount+=1;
  }
  while (taskCount == 4)
  {
    Line_Follow();
    task();
  }
  while (taskCount == 5)
  {
    Brake();
    delay(500);
    forward_coin_drop();
    Brake();
    delay(500);
    gate_servo();
    delay(500);
    taskCount +=1;
    Brake();
    delay(1000);
  }
  while (taskCount == 6)
  {
    Line_Follow();
    task();
  }
  while (taskCount == 7)
  {
    if (color==2)
    {  //green
        Brake();delay(500);
        encoderCount = 600;
        encoderForward();
    }
    taskCount += 1;
  }
  while (taskCount == 8)
  {
    Line_Follow();
    task();
  }
  while (taskCount == 9)
  {
    while (1){}
  }
}
*/
