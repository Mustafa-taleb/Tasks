//Code to control two servo motor independently
//By: M.Taleb

#include <Servo.h>
Servo motor1; 
Servo motor2;  
 
void setup() {
  motor1.attach(10);
  motor2.attach(9);    
}
void loop() {

  // To control first motor
if(digitalRead(A1)== HIGH){
  int val = analogRead(A0);            
  val = map(val, 0, 1023, 0, 180);     
  motor1.write(val);                  
  delay(15);  
  }
  
  // To control Seconde motor
if (digitalRead(A2)== HIGH){
  int val = analogRead(A3);            
  val = map(val, 0, 1023, 0, 180);     
  motor2.write(val);                  
  delay(15);  
}

  // To stop motor
else{
  motor2.write(LOW);  
  motor1.write(LOW);  
  }
}
                           
