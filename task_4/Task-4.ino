// Code to control DC motor using 2 relays 
// BY: M.Taleb

void setup() {
  pinMode(9, OUTPUT);   // to drive motor at clockwise direction
  pinMode(4, OUTPUT);   // to drive motor at Antclockwise direction
}

void loop() {
  
if(digitalRead(A0)== HIGH && digitalRead(A1)== LOW){
  digitalWrite(9, HIGH);   
  }
else if(digitalRead(A1)== HIGH && digitalRead(A0)== LOW){
  digitalWrite(4, HIGH); 
   }
else{
  digitalWrite(4, LOW); 
  digitalWrite(9, LOW); 
   }
}
