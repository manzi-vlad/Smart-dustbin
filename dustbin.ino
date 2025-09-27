
#include <Servo.h>
Servo myservo; 

int echopin=5;
int trigpin=4;
long duration;
float distance;
  
void setup() {

pinMode(trigpin,OUTPUT);
pinMode(echopin,INPUT);
 myservo.attach(9); 
Serial.begin(9600);
}

void loop() {
                           
  digitalWrite(trigpin,LOW);
   delayMicroseconds(2);
   digitalWrite(trigpin,HIGH);
   delayMicroseconds(10);
   digitalWrite(trigpin,LOW);

  duration=pulseIn(echopin,HIGH);
  distance=duration*0.0342/2;
Serial.println(distance);

if(distance<10){
 myservo.write(180);
}
else{
  myservo.write(90);
}
}
