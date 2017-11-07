void setup(){
  Serial.begin(9600);
}
void loop(){
  int sensorRead = analogRead(A0);
  Serial.println(sensorRead);
  int thisPitch = map(sensorRead, 600,900,120,1500);
  tone(9,thisPitch,10);
  delay(1);
}
