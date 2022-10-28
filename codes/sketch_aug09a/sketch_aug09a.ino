#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

int sensorPin = A0; 
int sensorValue;  
int limit = 300; 


LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  lcd.init();                      // initialize the lcd 
  lcd.init();
  // Print a message to the LCD.
  lcd.backlight();
  //lcd.noBacklight();
  lcd.setCursor(1,0);
  lcd.print("Athugalpura");
  lcd.setCursor(1,1);
  lcd.print("konichiwaa");
}


void loop() {

 sensorValue = analogRead(sensorPin); 
  delay(1000); 
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Anlg Val:");
  lcd.setCursor(9,0);
  lcd.print(sensorValue);
 
 if (sensorValue<limit) {
 digitalWrite(13, HIGH); 
 }
 else {
 digitalWrite(13, LOW); 
 }
 
 delay(1000); 
}
