#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,10,9,8,7);
float value=0;
float rev=0;
int rpm;
int windSpeed; // Newly Added
int oldtime=0;
int time;
 
void isr() //interrupt service routine
{
  rev++;
}
 
void setup()
{
  lcd.begin(16,2); //initialize LCD
  attachInterrupt(0,isr,RISING); //attaching the interrupt
}
 
void loop()
{
  delay(400);
  
  detachInterrupt(0); //detaches the interrupt
  time=millis()-oldtime; //finds the time
  rpm=(rev/time)*20000; //calculates rpm for blades
  windSpeed = rpm*(0.0042);
  oldtime=millis(); //saves the current time
  rev=0;
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("Wind Speed");
  lcd.setCursor(4,1);
  lcd.print(windSpeed);
  lcd.print(" m/s");
  lcd.print(" ");
  attachInterrupt(0,isr,RISING);
}
