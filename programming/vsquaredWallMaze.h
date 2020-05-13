void Wall_Error_Left()
{
  errorLeft = 5.5-Ldistance ;
}

void Wall_PID_Left()
{
  Wall_Error_Left();
  Wallpower = (lp*errorLeft) + (ld*(errorLeft-preErrorLeft));
  preErrorLeft = errorLeft;
  errorLeft = 0;
  Right_PWM = Base_PWM - Wallpower;
  Left_PWM = Base_PWM + Wallpower;
  
}

void Wall_Error()
{
  errorWall = Ldistance - Rdistance ;
  Wall_Error_Left();
  preErrorLeft = errorLeft;
}

void Wall_Reverse_PID()
{
  Wall_Error();
  Wallpower = (rightp*errorWallR) + (rightd*(errorWallR-preErrorWallR));
  preErrorWallR = errorWallR;
  errorWallR = 0;
  Right_PWM = Base_PWM + Wallpower;
  Left_PWM = Base_PWM - Wallpower;
}

void Wall_PID()
{
  Wall_Error();
  Wallpower = (p*errorWall) + (d*(errorWall-preErrorWall));
  preErrorWall = errorWall;
  errorWall = 0;
  Right_PWM = Base_PWM + Wallpower;
  Left_PWM = Base_PWM - Wallpower;
  
}


void Wall_Follow()
{
  if (Rightstate == 1)
  {
    Wall_PID();
    Forward();
  }
  else
  {
    Wall_PID_Left();
    Forward();
  }
}

void Wall_Maze()
{
  Fsonar();
  Rsonar();
  Lsonar();
  Sonar_State();
  if (Leftstate == 0)
  {
    Brake();
    delay(1000);
    encoderCount = 750;
    encoderForward();
    Turn_Leftninety_Wall();
    encoderCount = 80;
    encoderForward(); 
  }
  
  else if (Forwardstate == 1)
  {
    if (Rightstate == 0)
    {
     Brake();
     delay(1000);
     Turn_Rightninety_Wall();
     delay(1000); 
    }
    else if (Leftstate == 1 && Rightstate == 1)
    {
      while(1)
      {
        Fsonar();
        Rsonar();
        Lsonar();
        Sonar_State();
        if (Rightstate == 0)
        {
          Brake();
          delay(200);
          //encoderCount = -20;
          //encoderReverse();
          Turn_Rightninety_Wall();
          encoderCount = 100;
          encoderForward();
          Fsonar();
          Rsonar();
          Lsonar();
          Sonar_State();
          break;
        }
        else if (Rightstate == 1 && Leftstate == 0)
        {
          Brake();
          delay(1000);
          //encoderCount = -100;
          //encoderReverse();
          Turn_Leftninety_Wall();
          Fsonar();
          Rsonar();
          Lsonar();
          Sonar_State();
          if (Leftstate == 1)
          {
            Fsonar();
            Rsonar();
            Lsonar();
            Sonar_State();
            break;
          }
          else if (Leftstate == 0)
          {
            encoderCount = -70;
            encoderReverse();
            Turn_Leftninety_Wall();
            Fsonar();
            Rsonar();
            Lsonar();
            Sonar_State();
            break;
          }

        }
        else if (Rightstate == 1 && Leftstate == 1)
        {
          Wall_Reverse_PID();
          Reverse_Wall();
        }
      }
    }
  }
  else
  {
    Wall_Follow();
  }
}


void Maze_Complete()
{
  while (mazeCount <= 30)
  {
    Wall_Maze();
    mazeCount ++;
  }
  Brake();
  while (mainTask == 1)
  {
    Ir_Sensor();
    Count_Mid();
    if (Mid_Count == 0)
    {
      Wall_Maze();
    }
    else
    {
      mainTask +=1;
    }
  }
}

