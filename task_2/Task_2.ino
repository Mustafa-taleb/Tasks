//Code to control direction and speed of Stepper motor unipolar (Half cycle) without library.
//By: M.Taleb

void setup() {
  pinMode(4,OUTPUT);  //Upper Right Wire
  pinMode(5,OUTPUT);  //Lower Right Wire
  pinMode(6,OUTPUT);  //Lower Left Wire
  pinMode(7,OUTPUT);  //Upper Right Wire
}

void loop() {
  
  // To control speed of rotation
  int v=analogRead(A0);
  v=map(v,10,1023,30,1500);
  
  // To drive motor at clockwise direction
if(digitalRead(A1) ==HIGH && digitalRead(A2)==LOW ){
  digitalWrite(4,HIGH);
  delay(v);
  digitalWrite(5,HIGH);
  delay(v);
  digitalWrite(4,LOW);
  delay(v);
  digitalWrite(6,HIGH);
  delay(v);
  digitalWrite(5,LOW);
  delay(v);
  digitalWrite(7,HIGH);
  delay(v);
  digitalWrite(6,LOW);
  delay(v);
  digitalWrite(4,HIGH);
  delay(v);
  digitalWrite(7,LOW);
  delay(v);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}

  //To drive motor at Anticlockwise direction
else if(digitalRead(A1)==LOW && digitalRead(A2)==HIGH){
  digitalWrite(5,HIGH);
  delay(v);
  digitalWrite(4,HIGH);
  delay(v);
  digitalWrite(5,LOW);
  delay(v);
  digitalWrite(7,HIGH);
  delay(v);
  digitalWrite(4,LOW);
  delay(v);
  digitalWrite(6,HIGH);
  delay(v);
  digitalWrite(7,LOW);
  delay(v);
  digitalWrite(5,HIGH);
  delay(v);
  digitalWrite(6,LOW);
  delay(v);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
}
// TO stop motor
else{
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  }
}
