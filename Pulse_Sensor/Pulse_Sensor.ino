#include <Wire.h>
#include "MAX30105.h"  //sparkfun MAX3010X library
#include "heartRate.h"
#include "Settings.h"
MAX30105 pulse;

void setup() {
  Serial.begin(115200);
  Serial.println("Initializing...");
  // Initialize pulse sensor
  while (!pulse.begin(Wire, I2C_SPEED_FAST)) {
    Serial.println("MAX30102 was not found.");
  }
  // Set up the wanted parameters
  pulse.setup(ledBrightness, sampleAverage, ledMode, sampleRate, pulseWidth, adcRange);
  pulse.enableDIETEMPRDY();
}

void loop() {
  uint32_t red;
  double fred, fir;
  pulse.check();               //Check the sensor, read up to 3 samples
  while (pulse.available()) {  //do we have new data
    red = pulse.getFIFORed();
    if (red > FINGER_ON) {
      fred = (double)red;
      avered = avered * frate + (double)red * (1.0 - frate);  //average red level by low pass filter
      float red_forGraph = (2.0 * fred - avered) / avered * SCALE;
      if (checkForBeat(round(red_forGraph * 100))) {
        Serial.println("beat");
      }
      // if (red_forGraph > 255.0) red_forGraph = 255.0;
      // if (red_forGraph < 0.0) red_forGraph = 0.0;
      // Serial.println(red_forGraph);
    }
    pulse.nextSample();  //We're finished with this sample so move to next sample
  }
}
