#include <neopixel.h>

SYSTEM_MODE(AUTOMATIC);
SYSTEM_THREAD(ENABLED);

#define PIXEL_PIN A3
#define PIXEL_COUNT 1
#define PIXEL_TYPE WS2812

enum Status { good, minor, major, maintenance};
Status status = Status::good;

Thread thread("status_thread", fetchStatus);

int green[3] = {80, 210, 10};
int red[3] = {215, 10, 0};
int yellow[3] = {200, 170, 0};
int blue[3] = {19, 105, 207};

system_tick_t lastThreadTime = 0;

Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void fetchStatus(void);
void statusHandler(const char *event, const char *data);

void setup() {
  Particle.subscribe("GH_STATUS/update", statusHandler, MY_DEVICES);
  Serial.begin(9600);
  strip.begin();
}

void loop() {
  switch(status) {
  case Status::good:
    everythingsOK();
    break;
  case Status::maintenance:
    maintaining();
    break;
  case Status::minor:
    uhOh();
    break;
  case Status::major:
    rip();
    break;
  }
}

void maintaining() {
  strip.setPixelColor(0, blue[0], blue[1], blue[2]);
  strip.setBrightness(30);
  strip.show();
  for (int i = 30; i <= 160; i++) {
    strip.setPixelColor(0, blue[0], blue[1], blue[2]);
    strip.setBrightness(i);
    strip.show();
    delay(10);
  }

  delay(800);

  for (int i = 160; i >= 30; i--) {
    strip.setPixelColor(0, blue[0], blue[1], blue[2]);
    strip.setBrightness(i);
    strip.show();
    delay(10);
  }
}

void everythingsOK() {
  strip.setPixelColor(0, green[0], green[1], green[2]);
  strip.setBrightness(30);
  strip.show();
  for (int i = 30; i <= 160; i++) {
    strip.setPixelColor(0, green[0], green[1], green[2]);
    strip.setBrightness(i);
    strip.show();
    delay(10);
  }

  delay(800);

  for (int i = 160; i >= 30; i--) {
    strip.setPixelColor(0, green[0], green[1], green[2]);
    strip.setBrightness(i);
    strip.show();
    delay(10);
  }
}

void uhOh() {
  strip.setPixelColor(0, yellow[0], yellow[1], yellow[2]);
  strip.setBrightness(30);
  strip.show();
  for (int i = 30; i <= 200; i++) {
    strip.setPixelColor(0, yellow[0], yellow[1], yellow[2]);
    strip.setBrightness(i);
    strip.show();
    delay(2);
  }

  for (int i = 200; i >= 30; i--) {
    strip.setPixelColor(0, yellow[0], yellow[1], yellow[2]);
    strip.setBrightness(i);
    strip.show();
    delay(2);
  }
}

void rip() {
  strip.setBrightness(200);
  strip.setPixelColor(0, red[0], red[1], red[2]);
  strip.show();
  delay(200);
  strip.setBrightness(0);
  strip.setPixelColor(0, red[0], red[1], red[2]);
  strip.show();
  delay(200);
  strip.setBrightness(200);
  strip.setPixelColor(0, red[0], red[1], red[2]);
  strip.show();
  delay(200);
  strip.setBrightness(0);
  strip.setPixelColor(0, red[0], red[1], red[2]);
  strip.show();
  delay(700);
}

void fetchStatus() {
  while (true) {
    Particle.publish("status/check");
    os_thread_delay_until(&lastThreadTime, 20000);
  }
}

void statusHandler(const char *event, const char *data) {
  if (data) {
    Serial.println(data);
    if (strcmp(data, "none") == 0) {
      status = Status::good;
    } else if (strcmp(data, "maintenance") == 0) {
      status = Status::maintenance;
    } else if (strcmp(data, "minor") == 0) {
      status = Status::minor;
    } else if (strcmp(data, "major") == 0) {
      status = Status::major;
    }
  }
}
