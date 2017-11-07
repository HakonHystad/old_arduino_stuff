const int led = 8;
int ledState = LOW;
long prevMillis = 0;
long interval = 1000;

void setup(){
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}

void loop(){
  delay(500);
  
  unsigned long currentMillis = millis();
  Serial.println(currentMillis);
  delay(1);
  if (currentMillis - prevMillis > interval){
    prevMillis = currentMillis;
    if (ledState == LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(led,ledState);
  }
}
     
