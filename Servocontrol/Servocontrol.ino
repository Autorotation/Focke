////Steuerung der Servos

#include <Servo.h>
#include "PIDv1.h"

Servo motor, servoR, servoL, servoH, servoT;     // create servo object (Motordrehzahl, Taumelscheibe Rechts, Taumelscheibe Links, Taumelscheibe Hinten, Heckrotor)

int nick = 90;  //Neigung nach vorne
int roll = 90;  //Neigung nach rechts
int coll = 90;  //Kollektive Blattverstellung
int yaw = 90;   //Drehung um Rotorachse, in Servo-Form

int servoRval = 90;
int servoLval = 90;
int servoHval = 90;

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
  
  servoR.write(130);
  servoL.write(50);
  servoH.write(50);
  servoT.write(50);
  delay(2000);
  
  servoR.write(50);
  servoL.write(130);
  servoH.write(130);
  servoT.write(130);
  delay(2000);
  
}

void loop() 
{ 
  //ToDo(da): wenn kein Input, dann aktive Stabilisierung -> Algorithmus mit Output nick, roll, coll, yaw
  //ToDo(da): Input bekommen -> Interrupt? kphochdrölf
  //Output in nick, roll, coll, yaw
  
  nick=90;  
  roll=90;
  coll=90;
  execute();
  delay(5000);
  
  nick=130;  
  roll=90;
  coll=90;
  execute();
  delay(5000);
  
  nick=90;  
  roll=130;
  coll=90;
  execute();
  delay(5000);
  
  nick=90;  
  roll=90;
  coll=130;
  execute();
  delay(5000);
  
  nick=110;  
  roll=110;
  coll=110;
  execute();
  delay(5000);
    
} 

void execute(){
  
  servoRval = (nick-90) / (-2) + (roll-90) + (-1) * (coll-90) + 90;
  servoLval = (nick-90) / (-2) + (roll-90) + (coll-90) + 90;
  servoHval = (nick-90) + (coll-90) + 90;

  if(servoRval < 80)  { servoRval = 80;  }
  if(servoRval > 120) { servoRval = 120; }
  if(servoLval < 80)  { servoLval = 80;  }
  if(servoLval > 120) { servoLval = 120; }
  if(servoHval < 80)  { servoHval = 80;  }
  if(servoHval > 120) { servoHval = 120; }
  if(yaw < 60)  { yaw = 60;  }
  if(yaw > 120) { yaw = 120; }

  servoR.write(180-servoRval);
  servoL.write(180-servoLval);
  servoH.write(180-servoHval);

  servoT.write(yaw);
}

