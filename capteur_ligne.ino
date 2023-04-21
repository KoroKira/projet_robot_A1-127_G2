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
