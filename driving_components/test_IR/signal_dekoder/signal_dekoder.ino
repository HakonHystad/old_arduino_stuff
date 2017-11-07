/* Takes in IR-signals, prints to serial
 
 The IR sensor:
 Pin 1 to Vout (pin 3 on Arduino)
 Pin 2 to GND
 Pin 3 to Vcc (+5v from Arduino)

*/

/*******************CODE BEGINS HERE********************/

#include <IRremote.h>

int IRpin = 3;
IRrecv irrecv(IRpin);
decode_results results;

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}

void loop() 
{
  if (irrecv.decode(&results)) 
    {
      //--- print type ----
    if (results.decode_type == NEC) {
      Serial.print("NEC: ");
    } else if (results.decode_type == SONY) {
      Serial.print("SONY: ");
    } else if (results.decode_type == RC5) {
      Serial.print("RC5: ");
    } else if (results.decode_type == RC6) {
      Serial.print("RC6: ");
    } else if (results.decode_type == UNKNOWN) {
      Serial.print("UNKNOWN: ");
    }
    
    //---- print signal----------
      Serial.println(results.value, HEX); // Print the Serial 'results.value'
      irrecv.resume();   // Receive the next value
      
      // --- print number of bits ---
      Serial.print("Number of bits used: ");
      Serial.println(results.bits,DEC);
    }
    delay(10);
  
  
}

