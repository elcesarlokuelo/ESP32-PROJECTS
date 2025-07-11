#include <LiquidCrystal.h>
 
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(14, 27, 26, 25, 33, 32);
 
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}
void loop() {
  // set the cursor to column 0, line 0 and print a message.
  lcd.setCursor(0, 0);
  lcd.print("Hello World!");  // you can change it into any text
  // set the cursor to column 0, line 1 and print a message.
  lcd.setCursor(0, 1);
  lcd.print("Its working!");    // you can change it into any text
}
