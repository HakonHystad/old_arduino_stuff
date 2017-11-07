//led graph
int sensorReading = 0;
int level;
void setup(){
  Serial.begin(9600);
  for(int ledPin=2;ledPin<=6;ledPin++){
    pinMode(ledPin,OUTPUT);
  }
}
void loop(){
  sensorReading =analogRead(A0);
  level = map(sensorReading,0,1023,2,6);
  Serial.println(level);
  for(int ledPin=2;ledPin<=6;ledPin++){
    if(ledPin<=level){
      digitalWrite(ledPin,HIGH);
    }
    else if(ledPin>level){
      digitalWrite(ledPin,LOW);
    }
  }
  delay(100);
}
