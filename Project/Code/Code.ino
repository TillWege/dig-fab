#include <DFRobotDFPlayerMini.h>
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <U8g2lib.h>

const int xAxis = A2; // joystick X axis
const int yAxis = A6; // joystick Y axis
const int volPin = A5;
const int screenWidth = 128;
const int screenHeight = 64;

const int gameWidth = 128 / 2;
const int gameHeight = 64 / 2;

int range = 12;            // output range of X or Y movement
int responseDelay = 100;   // response delay of the mouse, in ms
int threshold = range / 4; // resting threshold
int center = range / 2;    // resting position value

U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/U8X8_PIN_NONE);
DFRobotDFPlayerMini myDFPlayer;

// Game variables
int snakeLength = 3;
int snakeX[32]; // Array to store snake body X positions (assuming max length of 32)
int snakeY[32]; // Array to store snake body Y positions

int foodPosX = 0;
int foodPosY = 0;

void setup()
{
  Serial.begin(9600);
  u8g2.begin();
  randomSeed(analogRead(0));
  myDFPlayer.begin(Serial, true, true);
  myDFPlayer.volume(10);
}

void initPlayer()
{
  snakeLength = 3;
  snakeX[0] = random(0, gameWidth - 4);
  snakeY[0] = random(0, gameHeight - 4);
  snakeX[1] = snakeX[0] + 1;
  snakeY[1] = snakeY[0] + 0;
  snakeX[2] = snakeX[1] + 1;
  snakeY[2] = snakeY[1] + 0;

  foodPosX = random(0, gameWidth);
  foodPosY = random(0, gameHeight);
}

void move(int x, int y)
{
  // Shift all body segments
  for (int i = snakeLength - 1; i > 0; i--)
  {
    snakeX[i] = snakeX[i - 1];
    snakeY[i] = snakeY[i - 1];
  }

  // Move the head
  snakeX[0] += x;
  snakeY[0] += y;
}

void draw()
{
  u8g2.clearBuffer();
  u8g2.firstPage();

  for (int i = 0; i < snakeLength; i++)
  {
    drawPixel(snakeX[i], snakeY[i]);
  }

  drawPixel(foodPosX, foodPosY);

  u8g2.nextPage();
}

void drawPixel(int x, int y)
{
  u8g2.drawPixel(x * 2, y * 2);
  u8g2.drawPixel((x * 2) + 1, y * 2);
  u8g2.drawPixel(x * 2, (y * 2) + 1);
  u8g2.drawPixel((x * 2) + 1, (y * 2) + 1);
}

void checkGameOver()
{
  if (snakeX[0] < 0 || snakeX[0] >= gameWidth || snakeY[0] < 0 || snakeY[0] >= gameHeight)
  {
    initPlayer();
  }

  for (int i = 1; i < snakeLength; i++)
  {
    if (snakeX[0] == snakeX[i] && snakeY[0] == snakeY[i])
    {
      initPlayer();
    }
  }
}

void checkFood()
{
  if (snakeX[0] == foodPosX && snakeY[0] == foodPosY)
  {
    snakeLength++;
    foodPosX = random(0, gameWidth);
    foodPosY = random(0, gameHeight);
    myDFPlayer.play(1);
    delay(500);
  }
}

void loop()
{
  // read and scale the two axes:
  int xReading = readAxis(xAxis);
  int yReading = readAxis(yAxis);

  if ((xReading == 6))
  {
    move(1, 0);
  }
  else if ((xReading == -6))
  {
    move(-1, 0);
  }

  if ((yReading == 6))
  {
    move(0, 1);
  }
  else if ((yReading == -6))
  {
    move(0, -1);
  }

  u8g2.clearBuffer();
  u8g2.firstPage();

  draw();
  checkGameOver();
  checkFood();

  u8g2.nextPage();

  delay(responseDelay);
}

int readAxis(int thisAxis)
{
  int reading = analogRead(thisAxis);

  reading = map(reading, 0, 1023, 0, range);

  int distance = reading - center;

  if (abs(distance) < threshold)
  {
    distance = 0;
  }

  return distance;
}
