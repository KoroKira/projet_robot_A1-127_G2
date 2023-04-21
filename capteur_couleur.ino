#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600);
  if (tcs.begin()) {
    Serial.println("TCS34725 sensor initialized");
  } else {
    Serial.println("Error initializing TCS34725 sensor");
  }
}

void loop() {
  uint16_t clear, red, green, blue;
  tcs.getRawData(&red, &green, &blue, &clear);
  float r, g, b;
  r = red; r /= clear;
  g = green; g /= clear;
  b = blue; b /= clear;
  Serial.print("Color: ");
  if (r > 0.5 && g > 0.5 && b > 0.5) {
    Serial.println("white");
  } else if (r > 0.5) {
    Serial.println("red");
  } else if (g > 0.5) {
    Serial.println("green");
  } else if (b > 0.5) {
    Serial.println("blue");
  } else {
    Serial.println("unknown");
  }
  delay(1000);
}

// Connectez le fil rouge (VCC) du capteur de couleur au port 5V de la carte Uno R3.
// Connectez le fil noir (GND) du capteur de couleur au port GND de la carte Uno R3.
// Connectez le fil blanc (SCL) du capteur de couleur au port SCL (A5) de la carte Uno R3.
// Connectez le fil jaune (SDA) du capteur de couleur au port SDA (A4) de la carte Uno R3.
