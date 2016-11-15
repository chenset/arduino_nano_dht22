#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "DHT22.h"
#include <Wire.h>

#include "I2Cdev.h"
#include <SoftwareSerial.h>

// 实例化SPI OLED
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_RESET 13

Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, -1);

DHT22 myDHT22(6);

unsigned long startTime =  millis();

void setup()
{
   Wire.begin();           //I2C总线
//  Serial.begin(9600);

  
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(4);
  display.setTextColor(WHITE);
  display.setCursor(40, 2);
  display.print("GO");
  display.display();

  delay(2000);

}

void loop()
{
  DHT22_ERROR_t errorCode;
  
  errorCode = myDHT22.readData();
  if(errorCode == DHT_ERROR_NONE){
    display.clearDisplay();
    display.setTextSize(2);
    display.setCursor(0, 0);
    display.print(myDHT22.getTemperatureC()-1.7);
    display.print("  ");
    display.println(myDHT22.getHumidityInt()/10);
    
    display.println(ceil((millis()-startTime)/1000/60));
    display.display();
  }

  delay(3000);
}
