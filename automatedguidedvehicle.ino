#include <Servo.h>

int motor1pin1=2;
int motor1pin2=3;
int motor2pin1=4;
int motor2pin2=5;
int motor1speed=11;
int motor2speed=10;
int motor=13;
int trig=8;
int echo=9;
int pushbutton=6;
int push;
int pos;
int buttonstate=0;

Servo myservo;

void setup()
{
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(motor2pin1, OUTPUT);
  pinMode(motor2pin2, OUTPUT);
  myservo.attach(motor);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(pushbutton,INPUT);
  Serial.begin(9600);
}

void loop()
{ 
  buttonstate=digitalRead(pushbutton);
  Serial.println(buttonstate);
  if(buttonstate == LOW){
    tshape();
    delay(500);
  }
  else{
    if(detectobstacle()){
       stopcar();
       ifobstacledetected();
       delay(500);
    }
  }
}

void stopcar(){
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,LOW);
  
  analogWrite(motor1speed,0);
  analogWrite(motor2speed,0);
}

void reverse(){
  digitalWrite(motor1pin1,LOW);
  digitalWrite(motor1pin2,HIGH);
  digitalWrite(motor2pin1,LOW);
  digitalWrite(motor2pin2,HIGH);
  
  analogWrite(motor1speed,200);
  analogWrite(motor2speed,200);
}

void forward(){
  digitalWrite(motor1pin1,HIGH);
  digitalWrite(motor1pin2,LOW);
  digitalWrite(motor2pin1,HIGH);
  digitalWrite(motor2pin2,LOW);
  
  analogWrite(motor1speed,200);
  analogWrite(motor2speed,200);
}

bool detectobstacle(){
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  long time= pulseIn(echo,HIGH);
  int distance=(time*0.034)/2;
  if (distance<25){
    return true;
  }
  else{
    return false;
  }
}

void ifobstacledetected(){
  reverse();
  delay(500);
  stopcar();
  delay(500);
  delay(500);
  detectobstacle();
}

void right(){
  for(int i=0;i<=90;i++){
     myservo.write(i);
    delay(15);
  }
}

void left(){
  for(int i=180;i>=90;i--){
    myservo.write(i);
    delay(15);
  }
}

void tshape(){
  forward();
  delay(500);
  
  stopcar();
  delay(1000);
  
  right();
  delay(1000);
  
  stopcar();
  delay(1000);
  
  forward();
  delay(1000);
  
  stopcar();
  delay(1000);
  
  reverse();
  delay(500);
  
  stopcar();
  delay(1000);
  
  forward();
  delay(1000);
  
  stopcar();
  delay(1000);
  
  right();
  delay(1000);
  
  stopcar();
  delay(1000);
  
  forward();
  delay(1000);
  
  stopcar();
  delay(1000);
  
}
  
