int Left_PWM, Right_PWM;
int Base_PWM = 60;
int Left_Base = 60;
int Right_Base = 60;

int Leften_Count = 0;
int Righten_Count = 0; 
int encoderCount = 0;
int encoderLeft = 0;
int encoderRight = 0;

int redFrequency = 0;
int greenFrequency = 0;
int blueFrequency = 0;

int k=0;
int z=0;
int flag = 0;
String TEXT;

int color=0;

int gatePos = 0;

int ir[10] = { A14, A13, A12, A11, A10, A9, A8, A7, A6, A5};

int IR[10] = { 0 };
int sens[10] = { 0 };


int Last_Read = 0;
int Last_Mid = 0;
int Left_Sens = 0;
int Right_Sens = 0;
int taskCount = 0;
int mainTask =0;

int pos1 = 0;
int pos2 = 0;
int pos3 = 0;


int y=0;

// line follow PID variables
int Errorval[10] = {0,-3, -2, -1, 0, 0, 1, 2, 3,0};
//7    4
float Kp = 7.5;   
float Ki = 0;
float Kd = 4;

float rp = 10;   
float rd = 4;

float redError=0;
float redPreError = 0;
                       

float Error=0;
float previousError = 0;
float totalError = 0;

float Power = 0;

int All_Count = 0;
int Left_Count = 0;
int Right_Count = 0;
int Mid_Count = 0;
bool Left= false;
bool Right= false;

float fduration;
float Fdistance;
int Forwardstate ;

float lduration;
float Ldistance;
int Leftstate ;

float rduration;
float Rdistance;
int Rightstate ;

//wall follow PID variables
float lp = 4.8;  
float ld = 9;

float p = 4.8;
float d = 9;

float rightp = 2;
float rightd = 9;

float errorLeft = 0;
float preErrorLeft = 0;

float errorWall = 0;
float preErrorWall = 0;

float errorWallR = 0;
float preErrorWallR = 0;


float Wallpower = 0;

int waterCount = 0;
int pos4 = 0;

int mazeCount = 0;

int smallCount = 0;