#include <rgb-controls.h>
#include <Encoder.h>
#include "sound.h"
#include "goggle.h"
#include <clickButton.h>

using namespace RGBControls;

#define SERVO_R D0
#define SERVO_L D1
#define PIEZO D2
#define ENCODER_A D5
#define ENCODER_B D6
#define BUTTON D7
#define RED_LED A0
#define GREEN_LED A1
#define RGB_R RX
#define RGB_G A4
#define RGB_B A5

Goggle goggle = Goggle();
Sound sound = Sound();
ClickButton button(BUTTON, LOW, CLICKBTN_PULLUP);
Encoder encoder(ENCODER_A, ENCODER_B);
Led led(RGB_R, RGB_G, RGB_B, false);
Color red(100, 0, 0);
Color green(0, 100, 0);
Color blue(0, 0, 100);
Color yellow(100, 100, 0);
Color magenta(100, 0, 100);
Color cyan(0, 100, 100);
Color white(100, 100, 100);
int brightness = 50;     // % brightness
int function = 0;        // Current mode
long oldPosition = -999; // monitor encoder movement
int mode = 0;
int colorVal = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(RED_LED, OUTPUT);
  //pinMode(GREEN_LED, OUTPUT);
  goggle.initGoggles(SERVO_L, SERVO_R);
  sound.initSound(PIEZO, RED_LED);
  led.off();
}

void loop() {
  button.Update();  
  if(button.clicks != 0) function = button.clicks;
  if(function == 1) {
    led.fadeOnce(green.withBrightness(0), green.withBrightness(brightness), 500);
    goggle.open();
    sound.beep(a, 50);
    delay(1000);
    led.off();
  }
  else if(function == 2) {
    led.fadeOnce(yellow.withBrightness(0), yellow.withBrightness(brightness), 500);
    if (mode == 1) {
        goggle.closeLeft();
        delay(500);
        goggle.closeRight();
        goggle.openLeft();
        delay(500);
        goggle.openRight();
    } else {
        goggle.blink();
    }
    sound.beep(b, 50);
    sound.beep(b, 50);
    delay(1000);
    led.off();
  }
  else if(function == 3) {
    led.fadeOnce(cyan.withBrightness(0), cyan.withBrightness(brightness), 500);
    if (mode == 4) {
      mode = 0;
    } else {
      mode = mode + 1;
    }
    for (int i=0; i<=mode; i++) {
        sound.beep(c, 50);
    }
    delay(1000);
    led.off();
  }
  else if(function == -1) {
    led.fadeOnce(red.withBrightness(0), red.withBrightness(brightness), 500);
    digitalWrite(RED_LED, HIGH);
    goggle.close();
    sound.beep(d, 500);
    delay(1000);
    led.off();
    digitalWrite(RED_LED, LOW);
  }
  else if(function == -2) {
    int rVal = colorVal;
    if (rVal > 255) {
        rVal = 255;
    }
    int bVal = colorVal - 255;
    if (bVal < 0) {
        bVal = 0;
    } else if (bVal > 255) {
        bVal = 255;
    }
    int gVal = colorVal - (2*255);
    if (gVal < 0) {
        gVal = 0;
    }
    Color c(rVal, gVal, bVal);
    sound.beep(e, 500);
    sound.beep(e, 500);
    led.fadeOnce(c.withBrightness(0), c, 5000);
    led.off();
  }
  else if(function == -3) {
    if (mode == 0) {
      sound.playSW();
    } else if (mode == 1) {
      sound.playDOOM();
    } else if (mode == 2) {
      sound.playVampire();
    } else if (mode == 3) {
      sound.playRick();
    } else if (mode == 4) {
      sound.playPotter();
    }
  }
  
  long newPosition = encoder.read();
  newPosition = newPosition % 175;
  if (newPosition < 5) {
    newPosition = 5;
  }
  if (newPosition < oldPosition) {
    sound.beep(a, 50);
  }
  else if (newPosition > oldPosition) {
    sound.beep(f, 50);
  }
  if (newPosition != oldPosition) {
    int difference = newPosition - oldPosition;
    oldPosition = newPosition;
    colorVal = colorVal + (5*difference);
    if (colorVal < 0) {
        colorVal = 0;
    } else if (colorVal > 765) {
        colorVal = 765;
    }
    if (mode == 1) {
      goggle.adjustOpposite(5*difference);
    } else if (mode == 2) {
      int oldBrightness = brightness;
      brightness = newPosition % 100;
      led.fadeOnce(white.withBrightness(oldBrightness), white.withBrightness(brightness), 500);
    } else {
      goggle.adjustBoth(5*difference);
    }
    led.off();
  }
  
  function = 0;
  led.off();
  return;
}