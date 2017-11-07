/*reading values from joystick

top--> "keyes_sjoys"
left<500
right>500
down<500
up>500


joystick pins - pins
5V  - +5V
GND - GND
VRx - A0
VRy - A1
SW - 2

*/
const int upDown = A0;
const int rightLeft = A1;
const int Press = 2;

int reading;

void setup(){
  Serial.begin(9600);
  pinMode(Press,INPUT);
}

void loop(){
  reading = analogRead(rightLeft);
  Serial.print("rightLeft: ");
  Serial.println(reading);
  
  delay(100);
  
  reading = analogRead(upDown);
  Serial.print("upDown: ");
  Serial.println(reading);
  
  delay(100);
  
  reading = digitalRead(Press);
  Serial.print("Press: ");
  Serial.println(reading);
  
  delay(2000);
}


