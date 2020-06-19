//code to control direction and speed of 2 DC motors.
//by m.taleb

void setup() {
pinMode(12,OUTPUT);      //control direction of motor A  (anticlockwise)  
pinMode(13,OUTPUT);      //control direction of motor A  (clockwise)
pinMode(11,OUTPUT);      //control speed of motor A
pinMode(6,OUTPUT);      //control direction of motor B  (clockwise) 
pinMode(7,OUTPUT);      //control direction of motor B  (anticlockwise)  
pinMode(9,OUTPUT);      //control speed of motor B
}

void loop() {
  
//move motor A ; direction-clockwise ; speed-increasly
if(digitalRead(A0)==HIGH && digitalRead(A1)==LOW){
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  
  for(int i=0;i<255;i++){
    if(digitalRead(A0)==HIGH && digitalRead(A1)==LOW){  //to force motor stop immediately
      analogWrite(11,i);
      delay(20);
    }
    else{
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
  }
}
//move motor A ; direction-anticlockwise ; speed-increasly
else if (digitalRead(A0)==LOW && digitalRead(A1)==HIGH){
  digitalWrite(12,LOW);
  digitalWrite(13,HIGH);
  
  for(int i=0;i<255;i++){
    if(digitalRead(A0)==LOW && digitalRead(A1)==HIGH){     //to force motor stop immediately
      analogWrite(11,i);
      delay(20);
    }
  else{
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
  }
}
else{
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
    }
//move motor B ; direction-clockwise ; speed-increasly
if(digitalRead(A2)==HIGH && digitalRead(A3)==LOW){
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);

  for(int i=0;i<255;i++){
    if(digitalRead(A2)==HIGH && digitalRead(A3)==LOW){  //to force motor stop immediately
      analogWrite(9,i);
      delay(20);
    }
    else{
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
  }
}

//move motor B ; direction-anticlockwise ; speed-increasly

else if (digitalRead(A2)==LOW && digitalRead(A3)==HIGH){
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);

  for(int i=0;i<255;i++){
    if(digitalRead(A2)==LOW && digitalRead(A3)==HIGH){  //to prevent execute loop if need to stop motor
      analogWrite(9,i);
      delay(20);
    }
    else{
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
  }
}
else{
      digitalWrite(6,LOW);
      digitalWrite(7,LOW);
    }
}
