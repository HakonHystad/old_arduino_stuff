/*kobling:
SDA - analog 4
SCL - analog 5
VCC - 5V
GND - GND
*/

#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE); // Addr, En, Rw, Rs, d4, d5, d6, d7, backlighpin, polarity
 
void setup()
{
    lcd.begin(16,2);//16 linjer, 2 rader
    lcd.backlight();
    lcd.setCursor(0, 0);//begynn på linje 1, rad 1
    lcd.print("Hei Ida!");
    lcd.setCursor(0, 1);
    /*lcd.print("Row number: ");
    lcd.setCursor(12, 1);
    lcd.print("2");*/
}
void loop()
{
 
}
