int firstSensor = 0;
int secondSensor = 0;
int button = 0;
int inByte = 0;

void setup(){
  Serial.begin(9600);
  pinMode(2,INPUT);
  establishContact();
}

void loop(){
  if(Serial.available()> 0){
    inByte = Serial.read();
    firstSensor = analogRead(A0)/4;
    delay(10);
    secondSensor = analogRead(A1)/4;
    button = map(digitalRead(2),0,1,0,255);
    Serial.write(firstSensor);
    Serial.write(secondSensor);
    Serial.write(button);
  }
}
void establishContact(){
  while(Serial.available()<= 0){
    Serial.print('A');
    delay(300);
  }
}
    

