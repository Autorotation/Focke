////Steuerung der Servos

#include <Servo.h>

Servo motor, servoR, servoL, servoH, servoT;     // create servo object (Motordrehzahl, Taumelscheibe Rechts, Taumelscheibe Links, Taumelscheibe Hinten, Heckrotor)

int nick = 90; //Neigung nach vorne
int roll = 90;  //Neigung nach rechts
int coll = 90;  //Kollektive Blattverstellung
int yaw = 90;   //Drehung um Rotorachse, in Servo-Form

int servoRval = 0;
int servoLval = 0;
int servoHval = 0;

void setup()
{
  motor.attach(8);
  servoR.attach(9);
  servoL.attach(10);
  servoH.attach(11);
  servoT.attach(12);
  
}

void loop() 
{ 
  //ToDo(da): wenn kein Input, dann aktive Stabilisierung -> Algorithmus mit Output nick, roll, coll, yaw
  //ToDo(da): Input bekommen -> Interrupt? kphochdrölf
  //Output in nick, roll, coll, yaw
    
  for(int x=0; x<10; x++){
    nick = 10 * x + 40;
   
    for(int y=0; y<10; y++){
      roll = 10 * y + 40;
      
      for(int z=0; z<10; z++){
        coll = 10 * z + 40;
        
      }
    } 
    execute(); 
  }
  
} 

void execute(){
  
  servoRval = (nick-90) / (-2) + (-1) * (roll-90) + (coll-90) + 90;
  servoLval = (nick-90) / (-2) + (roll-90) + (coll-90) + 90;
  servoHval = (nick-90) + (coll-90) + 90;

  if(servoRval < 40)  { servoRval = 40;  }
  if(servoRval > 140) { servoRval = 140; }
  if(servoLval < 40)  { servoRval = 40;  }
  if(servoLval > 140) { servoRval = 140; }
  if(servoHval < 40)  { servoRval = 40;  }
  if(servoHval > 140) { servoRval = 140; }
  if(yaw < 40)  { servoRval = 40;  }
  if(yaw > 140) { servoRval = 140; }

  servoR.write(servoRval);
  servoL.write(servoLval);
  servoH.write(servoHval);

  servoT.write(yaw);
}

