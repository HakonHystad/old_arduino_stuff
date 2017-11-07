//Knock detection, piezo

const int ledPin = 13;
int threshold = 25;
int sensorReading = 0;
int ledState = LOW;

void setup(){
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
}
void loop(){
  sensorReading = analogRead(A0);
  if(sensorReading>=threshold){
    Serial.println("Sound");
    ledState!=ledState;
    digitalWrite(ledPin,ledState);
  }
  delay(100);
}
  
