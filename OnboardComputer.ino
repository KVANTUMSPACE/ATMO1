/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters
}  /* --(end setup )---*/





void loop()
{

  void temp()
  {
    int tempsensor = analogRead(1);
    float temperature = (val11 / 40.92) - 1;
    Serial.println(temperature);
    delay(1000);
  }
  
  void pressure()
  {
    
  } 
     
}

