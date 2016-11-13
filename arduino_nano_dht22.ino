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

  delay(5000);

}

void loop()
{
  double *arr = getData();
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(0, 0);
  
  display.println(arr[0]);
  display.println(arr[1]);
  display.display();



//Serial.println(*arr);
//Serial.println(arr[1]);
  delay(3000);
}

double* getData(){
  double *arr = new double[2];

  myDHT22.readData();

  arr[0] = myDHT22.getTemperatureCInt()/10;
  double temp1 = abs(myDHT22.getTemperatureCInt()%10);
  arr[0]= arr[0]+(temp1/10);

  arr[1] = myDHT22.getHumidityInt()/10;
  double temp2 = abs(myDHT22.getHumidityInt()%10);
  arr[1]= arr[1]+(temp2/10);
    
//      sprintf(buf, "{\"temperature\": %hi.%01hi,\"humidity\" %i.%01i ,\"timestamp\":}",
//                   myDHT22.getTemperatureCInt()/10, abs(myDHT22.getTemperatureCInt()%10),
//                   myDHT22.getHumidityInt()/10, myDHT22.getHumidityInt()%10);
//      Serial.print(buf);

 return arr;
}
  

