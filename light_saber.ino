#define FASTLED_INTERNAL
#include <FastLED.h>

// ------ Settings ------
#define LED_PIN     8
#define BUTTON_PIN  5
#define NUM_LEDS    50
#define DELAY       8

bool orange = true;
bool green = true;
bool red = true;
bool white = false;
bool purple = true;
bool yellow = true;
bool blue = true;
// --------------------

int f = 0;  
int g = 0;
int done = 0;

String color = "blue";

void check_color() {
  if (blue == false) {
    color = "orange";
  }
  if (orange == false) {
    color = "green";
  }
  if (green == false) {
    color = "red";
  }
  if (red == false) {
    color = "white";
  }
  if (white == false) {
    color = "purple";
  }
  if (purple == false) {
    color = "yellow";
  }
  if (yellow == false) {
    color = "blue";
  }
} // check_color

CRGB leds[NUM_LEDS];

#include "OneButton.h"
OneButton button(BUTTON_PIN, false); 

void setup() {
  Serial.begin(115200);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);

  button.attachClick(singleclick);
  button.attachDoubleClick(doubleclick);
}

void loop() {
  button.tick();
}

void singleclick() {
  if (f == 0) {
    for (int i = 0; i <= NUM_LEDS; i++) {
      if (blue == true && color == "blue") {
        set_led(i, 0, 0, 255);
      }
      else {
        if (orange == true && color == "orange") {
          set_led(i, 255, 128, 0);
        }
        else {
          if (green == true && color == "green") {
            set_led(i, 0, 255, 0);
          }
          else {
            if (red == true && color == "red") {
              set_led(i, 255, 0, 0);
            }
            else {
              if (white == true && color == "white") {
                set_led(i, 255, 255, 255);
              }
              else {
                if (purple == true && color == "purple") {
                  set_led(i, 127, 0, 255);
                }
                else {
                  if (yellow == true && color == "yellow") {
                    set_led(i, 251, 255, 0);
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
      led(i,0, 0, 0);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 255, 128, 0);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 0, 255, 0);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 255, 0, 0);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 255, 255, 255);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 127, 0, 255);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 251, 255, 0);
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
        }
        for (int i = 0; i <= NUM_LEDS; i++) {
          set_led(i, 0, 0, 255);
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


void set_led(int a, int R, int G, int B){
  leds[a] = CRGB(R, G, B); 
          FastLED.show();
          delay(DELAY);
} // set_led
