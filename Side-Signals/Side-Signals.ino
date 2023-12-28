#include <FastLED.h>

const int PB = A0;
const int LED = 6;
const int NUM = 3;
int i;

CRGB leds[NUM];

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812, LED, GRB>(leds, NUM);
  pinMode(PB, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PB) == HIGH) {
    for (i = 0; i <= 2; i++) {
      leds[i] = CRGB(255, 35, 0);
      FastLED.show();
      delay(50);
    }
    for (i = 2; i >= 0; i--) {
      leds[i] = CRGB(0, 0, 0);
      FastLED.show();
      delay(70);
    }
  } else {
    for (i = 0; i < 3; i++) {
      leds[i] = CRGB(255, 255, 255);
      FastLED.show();
      delay(70);
    }
  }
}
