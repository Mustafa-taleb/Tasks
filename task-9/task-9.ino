// code to control two DOF of robot arm
// BY. M.Taleb

#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Servo.h>

char key=0;     // user input to choose forward or inverse 
int l1=150;    // the length of first link
int l2=100;   // the length of seconde link

int a,b,c=0;       //the first 3 digits  of first user input
int d,e,f=0;        //the first 3 digits  of seconde user input

Servo ser1;       // object 1 for first motor
Servo ser2;       // object 2 for seconde motor

//define pins wiht LCD
const int rs = A0, en = A1, d4 = A2, d5 = A3, d6 = A4, d7 = A5;  
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// define keypad
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = 
{
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {9,8,7,6}; 
byte colPins[COLS] = {5,4,3}; 
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );



void setup() {
  ser1.attach(11);    // pin 11 to control first motor
  ser2.attach(12);    // pin 12 to control first motor
  lcd.begin(16, 2);   // define the size of LCD
  
  lcd.print("Welcome to ");
  lcd.setCursor(0,1);
  lcd.print("Smart Mehtods ");
  delay(1000);
}

void loop() {
  
  lcd.clear();
  lcd.print("    Press");
  delay(1000);
  lcd.clear();
  lcd.print("1) for forward");
  lcd.setCursor(0,1);
  lcd.print("2) for inverse");
 
  while(key==0) {key = keypad.getKey();}     // wait to user enter value
 
  if (key==49){             // user push 1 (in ascii code 1=49)
    lcd.clear();
    lcd.print("forward");
    delay(2000); 
    forward();              //implement forward function
}
  else if(key==50){         // user push 2 (in ascii code 2=50)
    lcd.clear();
    lcd.print("      inverse");
    delay(2000);
    inverse();             //implement inverse function
}
  else{                   // user push neither 1 or 2
    lcd.clear();
    lcd.print("sorry,enter");
    lcd.setCursor(0,1);
    lcd.print("a valid number");
    delay(1000);
    key=0;
  }
}

void forward(){
  
   int first,seconde;    //th1 and th2 user input
   int x,y;                //the coordinates of user output
   
  // user enter the value of theta 1 (angle 1)
  lcd.clear();
  lcd.print("Enter angle Th1");
  delay(1000);
  lcd.clear();
  lcd.print("press #");
  lcd.setCursor(0,1);
  lcd.print("if done");
  delay(1000);
  lcd.clear();
  
  while(a==0){ a = keypad.getKey();}        // wait user to enter first digit
  a=a-48;                                  // to convert char to int
  lcd.print(a);
  first=a;                               // if the value only one digit, so its store as first angle
  
  while(b==0){ b = keypad.getKey();}   // wait user to enter seconde digit or # if its value just one digit
  if(b!=35){                          // any value exept # (in ascii code #=35)
  b=b-48;                            // to convert char to int
  lcd.print(b);
  first=a*10+b;                    // if the value only two digit, so its store as first angle
  }
  
  if(b!=35){                      // if user don't enter # after enter one digit
  while (c==0){c= keypad.getKey();}
  if(c!=35){
  c=c-48;
  lcd.print(c);
  delay(2000);
  first=a*100+b*10+c;
  }
}

  lcd.clear();
  lcd.print("Enter angle Th2");
  delay(500);
  lcd.clear();
  lcd.print("press #");
  lcd.setCursor(0,1);
  lcd.print(" if done");
  delay(1000);
  lcd.clear();

  // if enter first digit of secone angle
  while(d==0){ d = keypad.getKey();}
  d=d-48;
  lcd.print(d);
  seconde=d;

  // if enter seconde digit of secone angle
  while(e==0){ e = keypad.getKey();}
  if(e!=35){
  e=e-48;
  lcd.print(e);
  seconde=(d*10)+e;
  }
  
  // if enter third digit of secone angle
  if(e!=35){
  while (f==0){f= keypad.getKey();}
  if(f!=35){
  f=f-48;
  lcd.print(f);
  delay(1000);
  seconde=(d*100)+(e*10)+f;
  }
}

lcd.clear();
lcd.print(first);
delay(1000);
lcd.setCursor(0,1);
lcd.print(seconde);
delay(1000);

// to turn servo motor with user angles
lcd.clear();
ser1.write(first);
ser2.write(seconde);
lcd.clear();

// to calculate the position of end effectoe
first=first*0.01745;
seconde=seconde*0.01745;
x=(l1*cos(first))+(l2*cos(first+seconde));
y=(l1*sin(first))+(l2*sin(first+seconde));

// print the resault
lcd.print("the end point:");
delay(1000);
lcd.clear();
lcd.print("X: ");
lcd.setCursor(4,0);
lcd.print(x);
delay(1000);
lcd.clear();
lcd.print("Y: ");
lcd.setCursor(4,0);
lcd.print(y);
delay(1000);
lcd.clear();
}

void inverse(){
  int m=0;              //cos theta 2
  int q1,q2;             //th1 and th2 user output 
  int z,w;                //the coordinates of user input 
  int q=45;    // the angle between end effector and arm joint two
  
  lcd.clear();
  lcd.print("Enter value of x");
  lcd.setCursor(0,1);

  // if enter first digit for X-axis position of end effector
  while(a == 0){ a = keypad.getKey();}
  a=a-48;
  lcd.print(a);
  z=a;

  // if enter seconde digit for X-axis position of end effector
  while(b==0){ b = keypad.getKey();}
  if(b!=35){
  b=b-48;
  lcd.print(b);
  z=a*10+b;
  }

  // if enter third digit for X-axis position of end effector
  if(b!=35){
  while (c==0){c= keypad.getKey();}
  if(c!=35){
  c=c-48;
  lcd.print(c);
  delay(1000);
  z=a*100+b*10+c;
  }
} 


  lcd.clear();
  lcd.print("Enter value of y");
  lcd.setCursor(0,1);

  // if enter first digit for Y-axis position of end effector
  while(d ==0){ d = keypad.getKey();}
  d=d-48;
  lcd.print(d);
  w=d;
  // if enter seconde digit for Y-axis position of end effector
  while(e==0){ e = keypad.getKey();}
  if(e!=35){
  e=e-48;
  lcd.print(e);
  w=d*10+e;
  }
  // if enter third digit for Y-axis position of end effector
  if(e!=35){
  while (f==0){f= keypad.getKey();}
  if(f!=35){
  f=f-48;
  lcd.print(f);
  delay(1000);
  w=d*100+e*10+f;
  }
}
// print user value  
lcd.clear();
lcd.print(z);
delay(1000);
lcd.setCursor(0,1);
lcd.print(w);
delay(1000);
lcd.clear();

// calculate value of th1 and th2 
m=(pow(z,2)+pow(w,2)-pow(l1,2)-pow(l2,2))/(2*l1*l2);
q2=acos(m);
q2=q2/0.01745;
q1=q-q2;

// show result
lcd.print("the angles of arm");
delay(1000);
lcd.clear();
lcd.print("value of th1: ");
delay(1000);
lcd.setCursor(14,0);
lcd.print(q1);
delay(1000);
lcd.setCursor(0,1);
lcd.print("value of th2: ");
delay(1000);
lcd.setCursor(14,1);
lcd.print(q2);
delay(1000);
lcd.clear();

// to turn servo motor
ser1.write(q1);
ser2.write(q2);
delay(4000);
}
