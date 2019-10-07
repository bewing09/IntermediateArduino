// Ben Ewing
// engineering 2
// 9/4/19
// lcd backpack to print button presses on the lcd screen
int buttonPin = 7; // arduino pin connected to button
int buttonState = 0;
int counter = 0;
int previousbuttonState = 0;
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
void setup()
{
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.setBacklightPin(3, POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.print("Button Presses:"); // first line for LCD
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin); // checks if the button is pressed
  lcd.setCursor(0, 1); // puts the cursor in column 0 row 1
  if (buttonState == HIGH && previousbuttonState == LOW)
  {
    counter += 1; // counter goes up by one
    lcd.print(counter); // lcd displays the counter
  }
  previousbuttonState = buttonState;
  // else statement not needed
  Serial.print("");
  Serial.println(counter); // Serial monitor prints the counter
}
