int capteurGauche = A0; // capteur infrarouge gauche connecté à A0
int capteurDroit = A1; // capteur infrarouge droit connecté à A1
int seuil = 500; // seuil de détection de la ligne noire

void setup() {
  Serial.begin(9600); // initialisation de la communication série à 9600 bauds
}

void loop() {
  int valeurGauche = analogRead(capteurGauche); // lecture de la valeur du capteur gauche
  int valeurDroit = analogRead(capteurDroit); // lecture de la valeur du capteur droit

  // si la valeur est inférieure au seuil, alors la ligne noire est détectée
  if (valeurGauche < seuil) {
    Serial.println("LIGNE NOIRE DETECTEE A GAUCHE");
  }
  if (valeurDroit < seuil) {
    Serial.println("LIGNE NOIRE DETECTEE A DROITE");
  }
}
