int capteurGauche = A0; // capteur infrarouge gauche connecté à A0
int capteurDroit = A1; // capteur infrarouge droit connecté à A1
int seuil = 500; // seuil de détection de la ligne noire

void setup() {
  Serial.begin(9600); // initialisation de la communication série à 9600 bauds
}

void loop() {
  int valeurGauche = analogRead(capteurGauche); // lecture de la valeur du capteur gauche
  int valeurDroit = analogRead(capteurDroit); // lecture de la valeur du capteur droit

  // Si les deux capteurs infrarouges détectent une ligne noire
  if (valeurGauche < seuil && valeurDroit < seuil) {
    Serial.println("DETECTION DE LIGNE NOIRE A GAUCHE ET A DROITE");
  }
  // Si seul le capteur infrarouge gauche détecte une ligne noire
  else if (valeurGauche < seuil) {
    Serial.println("DETECTION DE LIGNE NOIRE A GAUCHE");
  }
  // Si seul le capteur infrarouge droit détecte une ligne noire
  else if (valeurDroit < seuil) {
    Serial.println("DETECTION DE LIGNE NOIRE A DROITE");
  }
  // Si aucun des capteurs infrarouges ne détecte une ligne noire
  else {
    Serial.println("AUCUNE DETECTION DE LIGNE NOIRE");
  }
}


// CABLAGE
// Connectez le fil noir du capteur infrarouge gauche à la broche GND de la carte Uno R3.
// Connectez le fil rouge du capteur infrarouge gauche à la broche A0 de la carte Uno R3.
// Connectez le fil noir du capteur infrarouge droit à la broche GND de la carte Uno R3.
// Connectez le fil rouge du capteur infrarouge droit à la broche A1 de la carte Uno R3



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


// Cablage en dessous + Il faut installer la librairie Adafruit_Sensor pour que le programme fonctionne
// Connectez le fil rouge (VCC) du capteur de couleur au port 5V de la carte Uno R3.
// Connectez le fil noir (GND) du capteur de couleur au port GND de la carte Uno R3.
// Connectez le fil blanc (SCL) du capteur de couleur au port SCL (A5) de la carte Uno R3.
// Connectez le fil jaune (SDA) du capteur de couleur au port SDA (A4) de la carte Uno R3.
