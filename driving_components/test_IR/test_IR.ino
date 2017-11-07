/* Turns LED on with remote
For å sende MÅ IR-led settes på pin 3

On/of signal MP3: FFA25D
on/of signal TV: F4BA2988

 
 The IR sensor:
 Pin 1 to Vout (pin 3 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

/*******************CODE BEGINS HERE********************/

#include <IRremote.h>

//--------- IR ------------
int IRpin = 3;
IRrecv irrecv(IRpin);
decode_results results;

//--------- LED -----------
const int ledPin = 13;
//--------- signals -------
unsigned long int onOff = 0xF4BA2988;//0x angir HEX

int ledState = LOW;
void setup()
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  irrecv.enableIRIn(); // Start the receiver
}
char reading;
void loop() 
{
  if (irrecv.decode(&results)) 
    {
      Serial.println(results.value, HEX);
      if(results.value == onOff){
          digitalWrite(ledPin,!ledState);
          ledState = !ledState;
          delay(50);
        }
      irrecv.resume();   // Receive the next value
    }
    reading = Serial.read
    
    delay(10);
  
  
}

