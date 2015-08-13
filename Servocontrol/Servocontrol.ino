////Steuerung der Servos

#include <Servo.h>
#include "PIDv1.h"

Servo motor, servoR, servoL, servoH, servoT;     // create servo object (Motordrehzahl, Taumelscheibe Rechts, Taumelscheibe Links, Taumelscheibe Hinten, Heckrotor)
int middle = 100;
int up = 130;
int down = 70;

int nick = middle;  //Neigung nach vorne
int roll = middle;  //Neigung nach rechts
int coll = middle;  //Kollektive Blattverstellung
int yaw = middle;   //Drehung um Rotorachse, in Servo-Form

int servoRval = middle;
int servoLval = middle;
int servoHval = middle;

void setup()
{
  motor.attach(8);
  servoR.attach(9);
  servoL.attach(10);
  servoH.attach(11);
  servoT.attach(12);
  
  motor.write(0);
  
  servoR.write(middle);
  servoL.write(middle);
  servoH.write(middle);
  servoT.write(middle);
  delay(5000);
  
  servoR.write(up);
  servoL.write(down);
  servoH.write(down);
  servoT.write(down);
  delay(2000);
  
  servoR.write(down);
  servoL.write(up);
  servoH.write(up);
  servoT.write(up);
  delay(2000);
  
}

void loop() 
{ 
  //ToDo(da): wenn kein Input, dann aktive Stabilisierung -> Algorithmus mit Output nick, roll, coll, yaw
  //ToDo(da): Input bekommen -> Interrupt? kphochdrölf
  //Output in nick, roll, coll, yaw
  
  nick=middle;  
  roll=middle;
  coll=middle;
  execute();
  delay(5000);
  
  nick=up;  
  roll=middle;
  coll=middle;
  execute();
  delay(5000);
  
  nick=middle;  
  roll=up;
  coll=middle;
  execute();
  delay(5000);
  
  nick=middle;  
  roll=middle;
  coll=up;
  execute();
  delay(5000);
  
  nick=up;  
  roll=up;
  coll=up;
  execute();
  delay(5000);
    
} 

void execute(){
  
  servoRval = (nick-middle) / (-2) + (roll-middle) + (-1) * (coll-middle) + middle;
  servoLval = (nick-middle) / (-2) + (roll-middle) + (coll-middle) + middle;
  servoHval = (nick-middle) + (coll-middle) + middle;

  if(servoRval < down)  { servoRval = down;  }
  if(servoRval > up) { servoRval = up; }
  if(servoLval < down)  { servoLval = down;  }
  if(servoLval > up) { servoLval = up; }
  if(servoHval < down)  { servoHval = down;  }
  if(servoHval > up) { servoHval = up; }
  if(yaw < down)  { yaw = down;  }
  if(yaw > up) { yaw = up; }

  servoR.write(180-servoRval);
  servoL.write(180-servoLval);
  servoH.write(180-servoHval);

  servoT.write(yaw);
}

