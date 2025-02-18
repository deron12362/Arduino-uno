//https://www.tinkercad.com/things/cmatQbwupTS-joystick/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard%2Fdesigns%2Fcircuits

#include <Servo.h>  

int ServoHorizontalPin = 11;   
int ServoVerticalPin = 10;   
int HorizontalPotPin = A0;  
int VerticalPotPin = A1;  
int ServoH_Min = 0;  
int ServoH_Max = 180; 
int ServoV_Min = 0; 
int ServoV_Max = 180; 

Servo HorizontalServo;  
Servo VerticalServo;    

int HorizontalPotValue;         
int HorizontalServoPosition;    
int VerticalPotValue;         
int VerticalServoPosition;    

void setup()   
{
  HorizontalServo.attach(ServoHorizontalPin);   
  VerticalServo.attach(ServoVerticalPin);         
}

void loop()  
{
  HorizontalPotValue  = analogRead(HorizontalPotPin); 
  VerticalPotValue  = analogRead(VerticalPotPin);  
  HorizontalServoPosition  = map(HorizontalPotValue, 0, 1023, ServoH_Min , ServoH_Max); 
  VerticalServoPosition  = map(VerticalPotValue, 0, 1023, ServoH_Min , ServoH_Max);   
  HorizontalServo.write(HorizontalServoPosition);       
  VerticalServo.write(VerticalServoPosition);       
  delay(20);    
}
