const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup(){
  Serial.begin(9600);
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
}

void loop(){
  while(Serial.available()>0){
    int red = Serial.parseInt();
    int green = Serial.parseInt();
    int blue = Serial.parseInt();

      red = constrain(red,0,255);
      green = constrain(green,0,255);
      blue = constrain(blue,0,255);
      analogWrite(redPin,red);
      analogWrite(greenPin,green);
      analogWrite(bluePin,blue);
      Serial.println(red,HEX);
}
}
