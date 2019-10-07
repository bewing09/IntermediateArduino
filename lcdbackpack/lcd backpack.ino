// lcd backpack.ino
// use a led backpackk to do hello world on lcd.
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7);
// sometimes 0x27 works when 0x3F doesn't
// that's the I2C address of the backpack
void setup()
{
	// put your setup code here, to run once:
	lcd.begin(16, 2); // for 16 x 2 LCD module
	lcd.setBacklightPin(3, POSITIVE);
	lcd.setBacklight(HIGH);
	lcd.print("hello world");
}

void loop()
{
	lcd.setCursor(0, 1);
	lcd.print(1 + millis() /1000);
}
