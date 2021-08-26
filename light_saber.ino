#define FASTLED_INTERNAL
#include <FastLED.h>

// ------ Settings ------
#define LED_PIN       8
#define BUTTON_PIN    5
#define NUM_LEDS      50
#define DELAY         3

bool orange = true;
bool green = true;
bool red = true;
bool white = true;
bool purple = true;
bool yellow = true;
bool blue = true;

bool flickering = true;
// --------------------

int f = 0;  
int g = 0;
int done = 0;

bool toggleBrightness = false;
int flickerBrightness = 255;

String color = "blue";

CRGB leds[NUM_LEDS];

#include "OneButton.h"
OneButton button(BUTTON_PIN, false); 

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  button.attachClick(singleclick);
  button.attachDoubleClick(doubleclick);

  if (blue == false && orange == true) {
    color = "orange";
  }
  else {
    if (blue == false && orange == false && green == true) {
      color = "green";
    }
    else {
      if (blue == false && orange == false && green == false && red == true) {
        color = "red";
      }
      else {
        if (blue == false && orange == false && green == false && red == false && white == true) {
          color = "white";
        }
        else {
          if (blue == false && orange == false && green == false && red == false && white == false && purple == true) {
            color = "purple";
          }
        }
      }
    }
  }
}

void loop() {
  button.tick();
  flicker();
}

void singleclick() {
  if (f == 0) {
    for (int i = 0; i <= NUM_LEDS; i++) {
      if (blue == true && color == "blue") {
        set_led(i, 0, 0, 255);
        flicker();
      }
      else {
        if (orange == true && color == "orange") {
          set_led(i, 255, 128, 0);
          g = 1;
          flicker();
        }
        else {
          if (green == true && color == "green") {
            set_led(i, 0, 255, 0);
            g = 2;
            flicker();
          }
          else {
            if (red == true && color == "red") {
              set_led(i, 255, 0, 0);
              g = 3;
              flicker();
            }
            else {
              if (white == true && color == "white") {
                set_led(i, 255, 255, 255);
                g = 4;
                flicker();
              }
              else {
                if (purple == true && color == "purple") {
                  set_led(i, 127, 0, 255);
                  g = 5;
                  flicker();
                }
                else {
                  if (yellow == true && color == "yellow") {
                    set_led(i, 251, 255, 0);
                    flicker();
                  }
                }
              }
            }
          }
        }
      }
    }
    f = 1;
  }
  else {
    for (int i = NUM_LEDS; i >= 0; i--) {
      set_led(i,0, 0, 0);
      flicker();
    }
    f = 0;
  }
} // singleclick

void doubleclick() {
  if (f == 1) {
    if (g == 0) {
      if (orange == true) {
        color = "orange";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 255, 128, 0);
          flicker();
        }
      }
      else {
        g++;
        done = 1;
      }
    }
    if (g == 1) {
      if (green == true) {
        color = "green";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 0, 255, 0);
          flicker();
        }
      }
      else {
        g++;
        done = 1;
      }
    }
    if (g == 2) {
      if (red == true) {
        color = "red";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 255, 0, 0);
          flicker();
        }
      }
      else {
        g++;
        done = 1;
      }
    }
    if (g == 3) {
      if (white == true) {
        color = "white";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 255, 255, 255);
          flicker();
        }
      }
      else {
        g++;
        done = 1;
      }
    }
    if (g == 4) {
      if (purple == true) {
        color = "purple";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 127, 0, 255);
          flicker();
        }
      }
      else {
        g++;
        done = 1;
      }
    }
    if (g == 5) {
      if (yellow == true) {
        color = "yellow";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 251, 255, 0);
          flicker();
        }
      }
      else {
        g++;
        done = 1;
      }
    }
    if (g == 6) {
      if (blue == true) {
        color = "blue";
        done = 0;
        for (int i = NUM_LEDS; i >= 0; i--) {
          set_led(i, 0, 0, 0);
          flicker();
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 0, 0, 255);
          flicker();
        }
        g = -1;
      }
      else {
        g = -1;
        done = 0;
      }
    }
    if (done == 0) {
      g++;
    }
  }
} // doubleclick

void set_led(int a, int R, int G, int B) {
  leds[a] = CRGB(R, G, B);
  delay(DELAY);
  FastLED.show();
} // set_led

void flicker() {
  if (flickering == true) {
    for (int i = 0; i <= NUM_LEDS; i++) {
      if (toggleBrightness == false) {
        flickerBrightness = flickerBrightness - 1;
      }
      else if (toggleBrightness == true) {
        flickerBrightness = flickerBrightness + 1;
      }
      if (flickerBrightness <= 0) {
        toggleBrightness = true;
      }
      if (flickerBrightness >= 255) {
        toggleBrightness = false;
      }
    }
    FastLED.setBrightness(flickerBrightness);
    FastLED.show();
  }
} // flicker
