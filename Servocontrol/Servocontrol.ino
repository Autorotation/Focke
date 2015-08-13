////Steuerung der Servos

#include <Servo.h>
#include "PIDv1.h"

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
  motor.write(0);
  
  servoR.write(90);
  servoL.write(90);
  servoH.write(90);
  servoT.write(90);
  delay(5000);
  
  servoR.write(140);
  servoL.write(40);
  servoH.write(40);
  servoT.write(40);
  delay(2000);
  
  servoR.write(40);
  servoL.write(140);
  servoH.write(140);
  servoT.write(140);
  delay(2000);
  
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
        execute();
        delay(100);
      }
    } 
    
  }
  
} 

void execute(){
  
  servoRval = (nick-90) / (-2) + (-1) * (roll-90) + (coll-90) + 90;
  servoLval = (nick-90) / (-2) + (roll-90) + (coll-90) + 90;
  servoHval = (nick-90) + (coll-90) + 90;

  if(servoRval < 70)  { servoRval = 70;  }
  if(servoRval > 110) { servoRval = 110; }
  if(servoLval < 70)  { servoLval = 70;  }
  if(servoLval > 110) { servoLval = 110; }
  if(servoHval < 70)  { servoHval = 70;  }
  if(servoHval > 110) { servoHval = 110; }
  if(yaw < 70)  { yaw = 70;  }
  if(yaw > 110) { yaw = 110; }

  servoR.write(servoRval);
  servoL.write(servoLval);
  servoH.write(servoHval);

  servoT.write(yaw);
}

