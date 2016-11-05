/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
#include <SFE_BMP180.h>
#include <Wire.h>

SFE_BMP180 pressure;
SFE_BMP180 pressure;


void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters

  void pressureSetup()
  {
    if (pressure.begin())
    Serial.println("BMP180 init success");
    else
    {
    Serial.println("BMP180 init fail (disconnected?)\n\n");
    while(1); // Pause forever.
    }
    // Get the baseline pressure:
    baseline = getPressure();
    Serial.print("baseline pressure: ");
    Serial.print(baseline);
    Serial.println(" mb");  
  }
  

} 





void loop()
{

  void temp()
  {
    int tempsensor = analogRead(1);
    float temperature = (val11 / 40.92) - 1;
    Serial.println(temperature);
    delay(10);
  }
  
  void pressure()
  {
    double a,P;
  
    // Get a new pressure reading:
    P = getPressure();

    // Show the relative altitude difference between
    // the new reading and the baseline reading:

    a = pressure.altitude(P,baseline);
  
    Serial.print("relative altitude: ");
    if (a >= 0.0) Serial.print(" "); // add a space for positive numbers
    Serial.print(a,1);
    Serial.print(" meters, ");

    delay(10);

  } 
     
}

