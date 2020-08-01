float p = 10;   
float i = 0;
float d = 2;

float Left_Wall = 5;
float Right_Wall = 5;

float Wallerror=0;
float Wallpreerror = 0;
float Walltoterror = 0;

float Wallpower = 0;

void Wall_Error()
{
  Wallerror = 5-Ldistance ;
}

void Wall_PID()
{
  Wall_Error();
  Walltoterror += Wallerror;
  
  Wallpower = (p*Wallerror) + (d*(Wallerror-Wallpreerror));
  Wallpreerror = Wallerror;
  Wallerror = 0;
  Right_PWM = Right_Base - Wallpower;
  Left_PWM = Left_Base + Wallpower;
  if (Right_PWM > 255) {Right_PWM = 255;}
  if (Left_PWM > 255) {Left_PWM = 255;}
  
}

void Wall_Follow()
{
  Wall_PID();
  Forward();
}

void Wall_Maze()
{
  Fsonar();
  Rsonar();
  Lsonar();
  Sonar_State();
  if (Leftstate == 1 && Forwardstate == 0)
  {
    Wall_Follow(); 
  }
  else if (Leftstate == 1 && Forwardstate == 1 && Rightstate == 0)
  {
    Brake();
    delay(500);
    Forward_Base();
    delay(250);
    Brake();
    delay(500);
    Turn_Rightninety_One();
    Forward_Base();
    delay(100);
    Brake();
    delay(500);
  }
  else if (Leftstate == 0)
  {
    Brake();
    delay(500);
    Forward_Base();
    delay(600);
    Brake();
    delay(500);
    Turn_Leftninety_One();
    Forward_Base();
    delay(500);
    Brake();
    delay(500);
  }
}
