/*
 * IRremote: demonstrates sending IR codes with IRsend
 * An IR LED MUST be connected to Arduino PWM pin 3.
 
 Kan sende til NEC, SONY, RC5, RC6
 */

#include <IRremote.h>

IRsend irsend;

unsigned int onOff = 0x540A;

void setup()
{
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()>0) {
    if(Serial.read() == 'a'){//write a to turn on/off
      for (int i = 0; i < 3; i++) {
        irsend.sendSony(onOff, 15); // Sony TV power code
        delay(40);
        Serial.print("sent: ");
        Serial.println(onOff, HEX);
      }
    }
  }
}
