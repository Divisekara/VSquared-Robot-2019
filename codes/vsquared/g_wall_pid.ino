/*float lp = 4.8;  
float ld = 9;

float p = 4.8;
float d = 9;*/

float lp = 4;  
float ld = 9;

float p = 4;
float d = 9;

float errorLeft = 0;
float preErrorLeft = 0;

float errorWall = 0;
float preErrorWall = 0;


float Wallpower = 0;

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
    encoderCount = 600;
    encoderForward();
    Turn_Leftninety_One();
    encoderCount = 380;
    encoderForward(); 
  }
  
  else if (Forwardstate == 1)
  {
    if (Rightstate == 0)
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
  else
  {
    Wall_Follow();
  }
}
