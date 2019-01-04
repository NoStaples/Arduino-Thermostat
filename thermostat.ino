#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //setup the pints the lcd is using

// setup variabls for the weather sensor
const int sensorPin = A0;


void setup() {
  // startup the LCD and tell it how large it is
  lcd.begin(16, 2);
  lcd.print("Temperature:");

  // For testing purposes, open a serieal connection to read in data
  //Serial.begin(9600);
}

void loop() {
  // 1. Read the temperature
  int sensorVal = analogRead(sensorPin);

  // 2. Convert the sensorValue into a voltage
  float voltage = (sensorVal/1024.0) * 5.0 ;
  // 3. Convert volatage into celcius
  float celcius = (voltage - 0.5) * 100;
  // 4. Convert Celcius to fahrenheit
  float temp = celcius * 9.0/5.0 + 32.0;

  // Print some stuff for testing
  //Serial.print("Sensor Value: ");
  //Serial.print(sensorVal);
  //Serial.print(" Temperature: ");
  //Serial.println(temp);
  
  //5. Display to the LCD
  lcd.setCursor(0, 1); //tell it to go the the second row
  lcd.print(temp);

  // Delay the code
  delay(5000); //should be for five seconds.

}
