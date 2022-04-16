/*!
 * @file LongTest.ino
 * @brief LongTest.
 * @copyright	Copyright (c) 2069 YYZ Co.Ltd (http://www.goddardyyz.com)
 * @licence     The MIT License (MIT)
 * @maintainer [goddardYYZ](matthew@goddardyyz.com)
 * @version  V1.0.1
 * @date  2022-04-15
 * @url https://github.com/goddardYYZ/Waveshare_LCD1602RGB
 */
#include "Waveshare_LCD1602RGB.h"

char dtaUart[15];
char dtaLen = 0;

int r = 0;
int g = 0;
int b = 0;
int Looper = 0;


Waveshare_LCD1602RGB lcd(/*lcdCols*/16,/*lcdRows*/2);  //16 characters and 2 lines of show

void setup() {
	Serial.begin(115200); 
    lcd.init();
    lcd.print("Test Starting...");
    lcd.setRGB(255, 255, 255);
    Looper = 5;
  while(Looper > 0) {
    lcd.setCursor(12, 1);
    lcd.print(String(Looper) + "...");
    Looper--;    
    delay(500);    
  } 
  lcd.clear();
  Looper = 10;
  while(Looper > 0) {
    lcd.setColor(RED);  
    delay(100);
    lcd.setColor(GREEN);  
    delay(100);
    lcd.setColor(BLUE);  
    delay(100);
    Looper--;  
  }  
  lcd.setColorWhite();
  lcd.print("Test Complete!");
  Looper = 5;  
  while(Looper > 0) {
    lcd.setCursor(12, 1);
    lcd.print(String(Looper) + "...");
    Looper--;    
    delay(500);    
  }     
}


void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RED  ");
  r = 255;
  g = 0;
  b = 0;
  lcd.setCursor(0, 1);
  lcd.print("R=" + String(r) + " G=" + String(g) + " B=" + String(b));
  lcd.setRGB(r, g, b);

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("GREEN");
  r = 0;
  g = 255;
  b = 0;
  lcd.setCursor(0, 1);
  lcd.print("R=" + String(r) + " G=" + String(g) + " B=" + String(b));
  lcd.setRGB(r, g, b);

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("BLUE ");
  r = 0;
  g = 0;
  b = 255;
  lcd.setCursor(0, 1);
  lcd.print("R=" + String(r) + " G=" + String(g) + " B=" + String(b));
  lcd.setRGB(r, g, b);

  delay(2000);


}

void serialEvent() {
    while(Serial.available()) {
        dtaUart[dtaLen++] = Serial.read();
    }
}

