# OLED Displays

#### Here are files supporting using OLED displays with Arduino.
OLED uses the adafruit GFX library for doing drawing commands. [GFX Library Documentation](https://cdn-learn.adafruit.com/downloads/pdf/adafruit-gfx-graphics-library.pdf)

Web link to convert images to show on screens [Make BITMAP IMAGES](https://javl.github.io/image2cpp/)

Get animated icons and emojis to show on OLED [WOKWI animator](https://animator.wokwi.com/)

#### Wiring Labelling for OLED
![alt text](https://github.com/peteRogers/Y1_PhysComp/blob/main/OLED/i2cGraphic.jpg "i2c graphics")

#### Draw Image to Screen
```java
  display.clearDisplay();
  display.drawBitmap(0, 0,  eye2, 128, 64, WHITE);
  display.display();
```


