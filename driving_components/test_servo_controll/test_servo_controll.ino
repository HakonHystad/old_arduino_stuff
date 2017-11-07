/*Controll a servo
----- Servo wires --------
red - 5v
brown - GND
orange - pin 3
----- pot wires ---------
middle - analog A0
left - 5v
right - GND
*/

#include <Servo.h>

Servo servo1;//servo1 = a servo

//-------- pins --------
int pot = A0;
// ------- other variables ------
int reading;

void setup(){
  servo1.attach(3);//servo sits on pin 3
}

void loop(){
  reading = analogRead(pot);
  reading = map(reading,0,1023,0,180);//servo works on input 0-180
  servo1.write(reading);//write to servo
  delay(15);
  
}


