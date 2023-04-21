// Déclaration des broches utilisées pour les LEDs et les boutons
const int ledPin = 13;
const int buttonPin = 2;
const int emergencyStopPin = 3;

// Variables pour suivre l'état des boutons
int buttonState = 0;
int emergencyStopState = 0;

// Variable pour suivre l'état de la LED
boolean ledOn = false;

void setup() {
  // Configure les broches en entrée ou en sortie
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(emergencyStopPin, INPUT);
}

void loop() {
  // Lit l'état du bouton
  buttonState = digitalRead(buttonPin);

  // Vérifie si le bouton a été pressé
  if (buttonState == HIGH) {
    delay(50);
    buttonState = digitalRead(buttonPin);
    if (buttonState == HIGH) {
      // Inverse l'état de la LED
      ledOn = !ledOn;
      digitalWrite(ledPin, ledOn);
    }
  }

  // Lit l'état du bouton d'arrêt d'urgence
  emergencyStopState = digitalRead(emergencyStopPin);

  // Vérifie si le bouton d'arrêt d'urgence a été pressé
  if (emergencyStopState == HIGH) {
    // Éteint la LED
    digitalWrite(ledPin, LOW);
  }
  
  
  
// Connectez le fil positif de la LED à la broche 13 de l'Arduino Uno R3.
// Connectez la résistance de 220 ohms entre la broche 13 de l'Arduino Uno R3 et la borne positive de la LED.
//Connectez la borne négative de la LED à la masse (GND) de l'Arduino Uno R3.
// Connectez une extrémité du bouton poussoir à la broche 2 de l'Arduino Uno R3.
// Connectez l'autre extrémité du bouton poussoir à la masse (GND) de l'Arduino Uno R3.
// Connectez une extrémité du bouton d'arrêt d'urgence à la broche 3 de l'Arduino Uno R3.
// Connectez l'autre extrémité du bouton d'arrêt d'urgence à la masse (GND) de l'Arduino Uno R3.
}
