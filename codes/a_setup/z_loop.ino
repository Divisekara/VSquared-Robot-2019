
void loopw()
{
  //lineMaze();
  //light_blue();
  //Forward_Base();
  //Enable();
  //Right_Forward_Base();
  //Ir_Sensor();
  //Red_Line_PID();
  //Forward();
  //Forward_Base();
  //Wall_Maze();
  //Turn_Half();

    Ir_Sensor();
     Line_PID();
     Forward();
     Ir_Sensor();
     
     if (Left_Sens == 1 || Right_Sens == 1)
      {
  
  
  
          taskCount=1;
  
          encoderCount = 100;
          encoderForward();    //untill the junction is passed
          encoderLeft = 450;
          leftMotor();
          while(y<650)
          {
           Ir_Sensor();
           Red_Line_PID();
           Forward();
           y++;//// the unloading box found - now taskCount=2
          }
          while(1){
          //////// dropping the coin
          Brake();
          delay(500);
          gate_servo(); 
          delay(500);
          break;
          }
          while(1)
          {
            Ir_Sensor();
            Red_Line_PID();
            Forward();
            if (Left_Sens == 1 && Right_Sens == 1)  //next colour junction found
            {
              Brake();
              while(1){}
              break;
            }
          }
          encoderCount = 100;
          encoderForward();    //untill the junction is passed
          encoderLeft = 450;
          leftMotor();
          encoderCount = 150;
          encoderForward();   //untill the junction is passed
          taskCount=3;
          
          
        
      }
  
}
void loop(){
  //lineMaze();
  //Wall_Maze();
  //Line_Follow();
  //Ir_Sensor();
}
