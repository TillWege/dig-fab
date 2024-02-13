#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>

const int xAxis = A0;       // joystick X axis
const int yAxis = A1;       // joystick Y axis
const int screenWidth = 128;
const int screenHeight = 64;

int range = 12;             // output range of X or Y movement
int responseDelay = 100;      // response delay of the mouse, in ms
int threshold = range / 4;  // resting threshold
int center = range / 2;     // resting position value

#include <U8g2lib.h>
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);

const char *text = "AZ-Delivery";
u8g2_uint_t posX = 30;
u8g2_uint_t posY = 30;

void setup() {
  Serial.begin(9600);  
  u8g2.begin();
  u8g2.setFont(u8g2_font_logisoso32_tf);
  u8g2.setFontMode(0);
}

void loop() {
  // read and scale the two axes:
  int xReading = readAxis(A0);
  int yReading = readAxis(A1);

  if((xReading == 6) && (posX < screenWidth))
  {
    posX++;
  } 
  else if((xReading == -6) && (posX > 1))
  {
    posX--;
  }

  if((yReading == 6) && (posY < screenHeight))
  {
    posY++;
  } 
  else if((yReading == -6) && (posY > 1))
  {
    posY--;
  }

  Serial.print("X:");
  Serial.println(xReading);

  Serial.print("Y:");
  Serial.println(yReading);
  
  u8g2.clearBuffer();
  u8g2.firstPage();
  
  u8g2.drawPixel(posX, posY);
  u8g2.nextPage();
  
  delay(responseDelay);
}

int readAxis(int thisAxis) {
  int reading = analogRead(thisAxis);

  reading = map(reading, 0, 1023, 0, range);

  int distance = reading - center;

  if (abs(distance) < threshold) {
    distance = 0;
  }

  return distance;
}
