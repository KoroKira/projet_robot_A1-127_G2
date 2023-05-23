int capteurGauche = A0; // capteur infrarouge gauche connecté à A0
int capteurDroit = A1; // capteur infrarouge droit connecté à A1
int seuil = 100; // seuil de détection de la ligne noire
int moteur1 = 9;
int moteur2 = 10;

// Sens de rotation. IN1 et IN2 moteur gauche, IN3 et IN4 droite. Si IN1 HIGH IN2 LOW, Sens horaire. Si IN1 LOW IN2 HIGH, Sens antihoraire. Si IN3 HIGH IN4 LOW, Sens horaire. Si IN3 LOW IN4 HIGH, Sens antihoraire
int IN2 = 1;
int IN1 = 2;
int IN4 = 3;
int IN3 = 5;

void setup() {
  Serial.begin(9600); // initialisation de la communication série à 9600 bauds
}

void loop() {
  int valeurGauche = analogRead(capteurGauche); // lecture de la valeur du capteur gauche
  int valeurDroit = analogRead(capteurDroit); // lecture de la valeur du capteur droit
   Serial.print (valeurGauche);
   Serial.print("-");
   Serial.println(valeurDroit);
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

  
  // Lecture du capteur de couleur
  // A FAIRE
  // Lecture de la valeur du capteur infrarouge gauche puis droit
  int valeur_capteur_gauche = analogRead(A0);
  int valeur_capteur_droit = analogRead(A1);

  //Si les deux capteurs sont sur une surface noire
if (valeur_capteur_gauche < 100 && valeur_capteur_droit < 100) {
    avancer();
}
  //Si seul le capteur gauche est sur une surface noire
if (valeur_capteur_gauche < 100 && valeur_capteur_droit > 100) {
    avancer_gauche();
}
  //Si seul le capteur droit est sur une surface noire
if (valeur_capteur_gauche > 100 && valeur_capteur_droit < 100) {
    avancer_droite();
}
  //Si les deux capteurs ne sont pas sur une surface noire
if (valeur_capteur_gauche > 100 && valeur_capteur_droit > 100) {
    stopper();
}
}
void avancer_droite() {
  // Instructions pour avancer à droite
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(moteur1, 200);
  analogWrite(moteur2, 150);
}

void avancer_gauche() {
  // Instructions pour avancer à gauche
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(moteur1, 150);
  analogWrite(moteur2, 200);
}

void avancer() {
  // Instructions pour avancer tout droit
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(moteur1, 200);
  analogWrite(moteur2, 200);
}

void stopper() {
  // Instructions pour arrêter le robot
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(moteur1, 0);
  analogWrite(moteur2, 0);
}

void continuer() {
  // Instructions pour continuer à avancer
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(moteur1, 200);
  analogWrite(moteur2, 200);
}
