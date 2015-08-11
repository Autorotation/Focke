//Steuerung der Servos

#include <Servo.h>

Servo motor, servoR, servoL, servoH, servoT;     // create servo object (Motordrehzahl, Taumelscheibe Rechts, Taumelscheibe Links, Taumelscheibe Hinten, Heckrotor)

int pitch = 512; //Neigung nach vorne, 0-1023?
int roll = 512;  //Neigung nach rechts
int coll = 512;  //Kollektive Blattverstellung
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
  //TODO: wenn kein Input, dann aktive Stabilisierung -> Algorithmus mit Output pitch, roll, coll, yaw
  //TODO: Input bekommen -> Interrupt? kphochdrölf
  //Output in pitch, roll, coll, yaw
  
  servoRval = ((-4) * pitch + (-7) * roll + coll);
  servoLval = ((-4) * pitch + (7) * roll + coll);   //TODO: Umrechnung auf Werte für Servos
  servoHval = ((8) * pitch + coll);

  servoR.write(servoRval);
  servoL.write(servoLval);
  servoH.write(servoHval);

  servoT.write(yaw);
} 

