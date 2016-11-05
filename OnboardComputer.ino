/* YourDuino.com Example Software Sketch
 20 character 4 line I2C Display
 Backpack Interface labelled "LCM1602 IIC  A0 A1 A2"
 terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here:
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
//none
/*-----( Declare objects )-----*/
// set the LCD address to 0x20 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address


/*-----( Declare Variables )-----*/
//none

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters
  lcd.begin(20, 4);        // initialize the lcd for 20 chars 4 lines and turn on backlight
  Serial.println("Voltage: ");
  Serial.print("V");



//-------- Write characters on the display ----------------
// NOTE: Cursor Position: CHAR, LINE) start at 0
lcd.setCursor(0, 0); //Start at character 4 on line 0
lcd.print("Stand by");
delay(1000);

}/*--(end setup )---*/



void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{


  {
    // when characters arrive over the serial port...
    if (Serial.available())
    {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters

      while (Serial.available() > 0)
      {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
      int val11;
    float temp;
    val11 = analogRead(1);
    temp = (val11 / 40.92) - 1;
    Serial.println(temp);
    delay(1000);
    
    if(temp <0)
    {
    lcd.setCursor(0, 0); //Start at character 4 on line 0
    lcd.print("Voltage: "); lcd.print("0.000");
    }
    
    else
    {
    lcd.setCursor(0, 0); //Start at character 4 on line 0
    lcd.print("Voltage: "); lcd.print(temp, 3);
    }  
  }

}/* --(end main loop )-- */


/* ( THE END ) */
