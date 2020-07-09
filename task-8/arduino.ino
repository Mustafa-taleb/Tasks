/*
Code to control a production line based on 3 IR sensors
each one sense size box (10*10*10-20*2*20-30*30*30)
By: M.TALEB
*/

#include<Servo.h>
Servo serv;      // create object serv

void setup() {
serv.attach(6);  // attaches the servo on pin 6 to the servo object
}

void loop() {
if(digitalRead(A2)== HIGH){
serv.write(183);                      // If IR sensor 1 (10*10*10) on,then direct motor to Right    
  delay(15);
}
else if (digitalRead(A1)== HIGH){
  serv.write(93);                     // If IR sensor 2 (20*20*20) on,then direct motor to center
  delay(15);
}
else{
  serv.write(0);                       // If IR sensor 3 (30*30*30) on,then direct motor to left
  delay(15);
}
}
