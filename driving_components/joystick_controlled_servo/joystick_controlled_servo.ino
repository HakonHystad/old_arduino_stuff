/*reading values from joystick

top--> "keyes_sjoys"
left<500
right>500
down<500
up>500

----- Joystick pins -----
joystick pins - pins
5V  - +5V
GND - GND
VRx - A0
VRy - A1
SW - 2

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

Servo servo1;

const int upDown = A0;
const int rightLeft = A1;
const int Press = 2;

int reading;
int angle;
int prevReading = 0;

void setup(){
  pinMode(Press,INPUT);
  servo1.attach(3);//servo sits on pin 3
}

void loop(){
  
  reading = analogRead(rightLeft);
  angle = map(reading, 0, 1023, 0, 180);
  
  if(reading < (prevReading - 5) || reading > (prevReading + 5) ){//account for unstable reading 
    servo1.write(angle);
    reading = prevReading;
  }
  
  delay(15);
}
  
  


