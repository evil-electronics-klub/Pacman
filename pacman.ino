#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pacmanclosed.h"
#include "pacmanopen.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const int your_bitmap_width = 64; // Replace with the actual width of your bitmaps
const int your_bitmap_height = 64; // Replace with the actual height of your bitmaps

void setup() {
  Serial.begin(9600);

  // initialize the display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

}

void loop() {


          display.clearDisplay();

          // Calculate the starting position to centerize the image horizontally
          int startX = (display.width() - your_bitmap_width) / 2;

          display.drawBitmap(startX, 0, pacmanopen, your_bitmap_width, your_bitmap_height, 1);
          display.display();
          // display the BTC logo for 3 seconds
          delay(3000);
          display.clearDisplay();
          display.drawBitmap(startX, 0, pacmanclosed, your_bitmap_width, your_bitmap_height, 1);
          display.display();
          // display the BTC logo for 3 seconds
          delay(3000);
}
