#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#include <Wire.h>

#include "I2Cdev.h"
#include <SoftwareSerial.h>

// 实例化SPI OLED
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_RESET 13

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, -1);


void setup()
{
   Wire.begin();           //I2C总线

  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(40, 2);
  display.print("GO");
  display.display();

  delay(500);

}

void loop()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);

  display.println("hello world");
  display.display();
}


