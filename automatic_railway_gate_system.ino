#include<Servo.h>
const int echoPin =2; 
const int  trigPin= 3;
long duration;
int distance;
int distance2;
long duration2;
const int echoPin2 =9;  
const int  trigPin2= 10;
const int buzzer=13;
int angle = 0;
Servo servo_test1;
Servo servo_test2;

void setup()
{
  pinMode(buzzer, OUTPUT);
   pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT); 
  servo_test1.attach(8); 
  servo_test2.attach(4); 
}

void loop()
{
    digitalWrite(trigPin, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPin2, LOW);
  //delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  //delayMicroseconds(10);
   digitalWrite(trigPin2, HIGH);
  //delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
  digitalWrite(trigPin2, LOW);
    duration2 = pulseIn(echoPin2, HIGH);
  distance = duration * 0.034 / 2;
  distance2 = duration2 * 0.034 / 2;
  
  if (distance2<50){                                
    servo_test1.write(90); 
    delay(45);
    servo_test2.write(90);
    delay(45);
    //tone(buzzer, 220, 100);
  }
  
  if (distance<50){                          
    servo_test1.write(0);
    delay(45);
    servo_test2.write(0); 
    delay(45);
    //tone(buzzer, 220, 100);
  
  }
}