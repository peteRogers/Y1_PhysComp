//#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "bitmaps.h"

#define screenWidth 128
#define screenHeight 64
#define SCREEN_ADDRESS 0x3D  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(screenWidth, screenHeight, &Wire, -1);



void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
}


void loop() {
  display.clearDisplay();
  //drawing code here
  display.display();
  delay(100);
}
