int capteurGauche = A0; // capteur infrarouge gauche connecté à A0
int capteurDroit = A1; // capteur infrarouge droit connecté à A1
int seuil = 500; // seuil de détection de la ligne noire


const int buttonPin = 2;    // Broche du bouton poussoir
const int motor1Pin1 = 3;   // Broche 1 pour le moteur 1
const int motor1Pin2 = 4;   // Broche 2 pour le moteur 1
const int motor2Pin1 = 5;   // Broche 1 pour le moteur 2
const int motor2Pin2 = 6;   // Broche 2 pour le moteur 2

int motor1Speed = 0;        // Vitesse initiale pour le moteur 1
int motor2Speed = 0;        // Vitesse initiale pour le moteur 2
int buttonState = 0;        // Etat actuel du bouton poussoir
int buttonPressed = 0;      // Indique si le bouton a été pressé

#include <Wire.h>
#include <Adafruit_TCS34725.h>

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600); // initialisation de la communication série à 9600 bauds
  if (tcs.begin()) {
    Serial.println("TCS34725 sensor initialized");
  } else {
    Serial.println("Error initializing TCS34725 sensor");
  }
    // Initialisation des broches en entrée ou sortie
  pinMode(buttonPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
}
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

void loop() {
  // Lecture de l'état du bouton poussoir
  buttonState = digitalRead(buttonPin);

  // Si le bouton a été pressé, on change l'état des moteurs
  if (buttonState == HIGH && buttonPressed == 0) {
    buttonPressed = 1;
    motor1Speed = 100;      // Vitesse à 100 (MAX) pour les deux moteurs
    motor2Speed = 100;
    digitalWrite(motor1Pin1, HIGH);    // Moteur 1 dans le sens horaire
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, HIGH);    // Moteur 2 dans le sens horaire
    digitalWrite(motor2Pin2, LOW);
  }
  else if (buttonState == HIGH && buttonPressed == 1) {
    buttonPressed = 2;
    motor1Speed = 100;      // Vitesse à 100 (MAX) pour les deux moteurs
    motor2Speed = 100;
    digitalWrite(motor1Pin1, LOW);    // Moteur 1 dans le sens antihoraire
    digitalWrite(motor1Pin2, HIGH);
    digitalWrite(motor2Pin1, HIGH);   // Moteur 2 dans le sens horaire
    digitalWrite(motor2Pin2, LOW);
  }
  else if (buttonState == HIGH && buttonPressed == 2) {
    buttonPressed = 0;
    motor1Speed = 0;        // Arrêt des deux moteurs
    motor2Speed = 0;
    digitalWrite(motor1Pin1, LOW);    // Moteur 1 arrêté
    digitalWrite(motor1Pin2, LOW);
    digitalWrite(motor2Pin1, LOW);    // Moteur 2 arrêté
    digitalWrite(motor2Pin2, LOW);
  }

  // Contrôle des vitesses des moteurs
  analogWrite(motor1Pin1, motor1Speed);
  analogWrite(motor1Pin2, motor1Speed);
  analogWrite(motor2Pin1, motor2Speed);
  analogWrite(motor2Pin2, motor2Speed);

  
  
  // CABLAGE + Il faut installer la librairie Adafruit_Sensor pour que le programme fonctionne
// Connectez le fil noir du capteur infrarouge gauche à la broche GND de la carte Uno R3.
// Connectez le fil rouge du capteur infrarouge gauche à la broche A0 de la carte Uno R3.
// Connectez le fil noir du capteur infrarouge droit à la broche GND de la carte Uno R3.
// Connectez le fil rouge du capteur infrarouge droit à la broche A1 de la carte Uno R3.
  
  
// Connectez le fil rouge (VCC) du capteur de couleur au port 5V de la carte Uno R3.
// Connectez le fil noir (GND) du capteur de couleur au port GND de la carte Uno R3.
// Connectez le fil blanc (SCL) du capteur de couleur au port SCL (A5) de la carte Uno R3.
// Connectez le fil jaune (SDA) du capteur de couleur au port SDA (A4) de la carte Uno R3.

// Broche 2 du bouton poussoir connectée à la broche 2 (INT0) de la carte Arduino Uno
// Broches IN1 et IN2 du pont en H connectées aux broches 3 et 4 de la carte pour le moteur 1
// Broches IN3 et IN4 du pont en H connectées aux broches 5 et 6 de la carte pour le moteur 2
// Broches ENA et ENB du pont en H connectées à des broches PWM de la carte (ex: 9 et 10) pour contrôler la vitesse des moteurs
