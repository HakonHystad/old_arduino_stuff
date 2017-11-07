#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity
 
void setup()
{
lcd.begin(16,2);
lcd.backlight();
lcd.setCursor(0, 0);        //First column, first row
lcd.print("Hello world!");
lcd.setCursor(0, 1);        //First column, second row
lcd.print("Row number: ");
lcd.setCursor(12, 1);       //12th column, second row
lcd.print("2");
lcd.blink();                //start blinking cursor
delay (3000);               //delay 3 seconds
}
void loop()
{
demoDisplay();
}
void demoDisplay()
{
lcd.clear();              // clear display, set cursor position to zero
lcd.setBacklight(HIGH);        // Backlight on
lcd.setCursor (0,0);           //col 0 of line 1
lcd.print("Boot sequence");
lcd.setCursor (0,1);           // go col 0 of line 2
lcd.print("starting.");
lcd.noBlink();                 //stop blinking cursor
delay(1000);                   //delay 1 second
wipeLines();                   //run function wipeLines
}
 
void wipeLines() {
for (int y = 0; y < 4; y++) {
for (int x = 0; x < 20; x++) {
lcd.setCursor (x,y);
lcd.print(" ");
delay(10);
}
}
}
