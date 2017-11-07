/*------pins--------
 * GND -> GND
 * 5V ->Vcc
 * A4 ->SDA
 * A5 ->SCL
 */


#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);


// Creat a set of new characters
//here buildingblocks for big chars
const uint8_t charBitmap[][8] = {
    { B00111,
      B01111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111 },

    { B11111,
      B11111,
      B11111,
      B00000,
      B00000,
      B00000,
      B11111,
      B11111 },
      
    { B11100,
      B11110,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111 },

    { B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B01111,
      B00111 },

    { B11111,
      B00000,
      B00000,
      B00000,
      B00000,
      B11111,
      B11111,
      B11111 },

    { B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11111,
      B11110,
      B11100 },
                        
   {  B11111,
      B11111,
      B11111,
      B00000,
      B00000,
      B00000,
      B00000,
      B00000 },
      
    { B00000,
      B00000,
      B00000,
      B00000,
      B00000,
      B11111,
      B11111,
      B11111 }
      
      };
//array of function pointers for easy use of custom characters:
void (*customChar[10])(int index);

void setup()
{
  int charBitmapSize = (sizeof(charBitmap ) / sizeof (charBitmap[0]));

  // Switch on the backlight
  
  lcd.begin(16,2);               // initialize the lcd 
  lcd.backlight();

   for ( int i = 0; i < charBitmapSize; i++ )
   {
      lcd.createChar ( i, (uint8_t *)charBitmap[i] );
   }

  //Main blocks forming an 8
   //**0**1**2
   //**3**4**5
   //extra
   //**6**7
   //also:
   //black at 255
   //blank at 254
   //filling array of function pointers with writerfunctions of custom characters
   customChar[0] = custom0;
   customChar[1] = custom1;
   customChar[2] = custom2;
   customChar[3] = custom3;
   customChar[4] = custom4;
   customChar[5] = custom5;
   customChar[6] = custom6;
   customChar[7] = custom7;
   customChar[8] = custom8;
   customChar[9] = custom9;
   

  lcd.setCursor( 16,0 );                  // go home
  lcd.print("Made by Haakon");  
  lcd.setCursor ( 22, 1 );        // go to the next line
  lcd.print("2016");
  for(int i=0;i<30;i++)
  {
    lcd.scrollDisplayLeft();
    delay(250);
  }

  lcd.home();
  lcd.clear();
  
}

void loop()
{

    double volts = 34.9;
    int digits[3];
    int amps = 246;
    int ampLim = 250;
    bool locked = false;
    bool overload = false;

    if(amps>=ampLim)
    {
      overload = true;
    }
    

    bool checkDigitRange = toDigits(digits,volts);



    if(checkDigitRange && !overload)
    {
      (*customChar[digits[2]])(0);
      (*customChar[digits[1]])(3);
      if(locked)
      {
        lcd.setCursor(6,0);
        lcd.print("*");
      }
      lcd.setCursor(6,1);
      lcd.print(",");
      (*customChar[digits[0]])(7);
    }
    else
    {
      lcd.clear();
      lcd.home();
      lcd.print("  OVERLOAD");
      lcd.setCursor(0,1);
      lcd.print("  !!!!!!!!");
    }

    lcd.setCursor(11,0);
    lcd.print(amps);
    lcd.print("/");
    lcd.setCursor(11,1);
    lcd.print(ampLim);
    lcd.print("mA");

  delay(1000);
}

bool toDigits(int *a,double number)
{
    a[0] = (int)(number*10)%10;//decimal
    a[1] = (int)number%10;//firstDigit
    a[2] = (number/10);//secondDigit 

    for(int i=0;i<3;i++)
    {
      if(a[i]>9)
      {
        return false;
      }
    }
    return true;
}


//----------------------- writer functions of custom characters---------------------

void  custom0(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)6);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)7);
  lcd.write((uint8_t)5);
  
}


void custom1(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)255);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)254);
  lcd.write(254);
  lcd.write(255);
}

void  custom2(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)4);
  
}

void  custom3(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)6);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)7);
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)5);
  
}

void  custom4(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)7);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)255);
  
}

void  custom5(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)255);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)1);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)5);
  
}

void  custom6(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)1);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)5);
  
}

void  custom7(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)6);
  lcd.write((uint8_t)6);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)254);
  
}


void  custom8(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)3);
  lcd.write((uint8_t)4);
  lcd.write((uint8_t)5);
  
}

void  custom9(int index)
{
  lcd.setCursor(index,0);//upper line
  lcd.write((uint8_t)0);
  lcd.write((uint8_t)1);
  lcd.write((uint8_t)2);
  lcd.setCursor(index,1);//lower line
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)254);
  lcd.write((uint8_t)255);
  
}



