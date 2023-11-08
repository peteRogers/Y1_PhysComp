#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define BALL_RADIUS 5
#define GRAVITY 0.4
#define BOUNCE_FACTOR 0.7

Adafruit_SSD1306 display(128, 64, &Wire, -1);

float ballX, ballY;
float velocityY;

void setup() {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3D);
  display.clearDisplay();
  ballX = 0;
  ballY = BALL_RADIUS;
  velocityY = 0;
}

void loop() {
  // Clear the display
  display.clearDisplay();

  // Update ball position
  ballY += velocityY;
  velocityY += GRAVITY;
  ballX = ballX+2;

  // Check for collision with the ground
  if (ballY + BALL_RADIUS >= SCREEN_HEIGHT) {
    ballY = SCREEN_HEIGHT - BALL_RADIUS;
    velocityY = -velocityY * BOUNCE_FACTOR;
  }

  // Draw the ball
  display.fillCircle(ballX, ballY, BALL_RADIUS, SSD1306_WHITE);

  // Display the updated frame
  display.display();
  delay(5); // Adjust this delay for desired frame rate
  if(ballX > SCREEN_WIDTH){
    ballX = -10;
    ballY = -10;
  }
}
