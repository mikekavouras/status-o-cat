#include <FastLED.h>
FASTLED_USING_NAMESPACE

#define LED_PIN  6

enum State { good, bad };
State currentState = bad;

CRGB leds[1];

CRGB green = CRGB(52, 208, 88);
CRGB red = CRGB(215, 58, 73);
CRGB yellow = CRGB(170, 211, 61);

void setup() {
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, 1);
// void myHandler(const char *event, const char *data) {
//   Serial.println("GOT IT");
//   if (data) {
//     Serial.println(data);
//   }
// }
//
// void setup() {
//   Serial.begin(9600);
//   Particle.subscribe("printer_deliver", myHandler);
// }
//
// void loop() {
//   Particle.publish("Printer/inquire");
//   delay(10000);
// }

}

void loop() {
  while(true) {
    everythingsOK();
    uhOh();
    uhOh();
    rip();
    rip();
    rip();
  }
}

void everythingsOK() {
  showColor(green);
  for (int i = 30; i <= 255; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(10);
  }

  for (int i = 255; i >= 30; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(10);
  }
}

void uhOh() {
  showColor(yellow);
  for (int i = 30; i <= 255; i++) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(2);
  }

  for (int i = 255; i >= 30; i--) {
    FastLED.setBrightness(i);
    FastLED.show();
    delay(2
    );
  }
}

void rip() {
  showColor(red);

//  while (currentState == bad) {
    FastLED.setBrightness(255);
    FastLED.show();
    delay(200);
    FastLED.setBrightness(0);
    FastLED.show();
    delay(200);
    FastLED.setBrightness(255);
    FastLED.show();
    delay(200);
    FastLED.setBrightness(0);
    FastLED.show();
    delay(500);
//  }
}

void showColor(CRGB color) {
  leds[0] = color;
  FastLED.show();
}
  Serial.println("GOT IT");
  if (data) {
    Serial.println(data);
  }
}

void setup() {
  Serial.begin(9600);
  Particle.subscribe("printer_deliver", myHandler);
}

void loop() {
  Particle.publish("Printer/inquire");
  delay(10000);
}
