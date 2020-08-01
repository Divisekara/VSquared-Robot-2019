float lp = 2.5;  
float ld = 1;

float p = 2.6;
float d = 1.4;

float errorLeft = 0;
float preErrorLeft = 0;

float errorWall = 0;
float preErrorWall = 0;


float Wallpower = 0;

void Wall_Error_Left()
{
  errorLeft = 6-Ldistance ;
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
  if (Leftstate == 0)
  {
    Brake();
    delay(2000);
  }
  else
  {
    if (Rightstate == 0)
    {
      Wall_PID_Left();
      Forward();
    }
    else
    {
      Wall_PID();
      Forward();
    }
  }
}



void Wall_Maze()
{
  Fsonar();
  Rsonar();
  Lsonar();
  Sonar_State();
  if (Forwardstate == 1)
  {
    if (Leftstate == 0)
    {
      Brake();
      delay(1000);
      Turn_Leftninety_One();
    }
    else if (Rightstate == 0)
    {
     Brake();
     delay(1000);
     Turn_Rightninety_One();
     delay(1000); 
    }
    else if (Leftstate == 1 && Rightstate == 1)
    {
      Brake();
      delay(1000);
    }
  }
  else if (Leftstate == 0)
  {
    Brake();
    delay(1000);
    encoderCount = 620;
    encoderForward();
    Turn_Leftninety_One();
    encoderCount = 380;
    encoderForward();
  }
  else
  {
    Wall_Follow();
  }
}
