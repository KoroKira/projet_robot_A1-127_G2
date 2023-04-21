// NOTICE DE CABLAGE :
// -------------------
// Broche 2 du bouton poussoir connectée à la broche 2 (INT0) de la carte Arduino Uno
// Broches IN1 et IN2 du pont en H connectées aux broches 3 et 4 de la carte pour le moteur 1
// Broches IN3 et IN4 du pont en H connectées aux broches 5 et 6 de la carte pour le moteur 2
// Broches ENA et ENB du pont en H connectées à des broches PWM de la carte (ex: 9 et 10) pour contrôler la vitesse des moteurs


const int buttonPin = 2;    // Broche du bouton poussoir
const int motor1Pin1 = 3;   // Broche 1 pour le moteur 1
const int motor1Pin2 = 4;   // Broche 2 pour le moteur 1
const int motor2Pin1 = 5;   // Broche 1 pour le moteur 2
const int motor2Pin2 = 6;   // Broche 2 pour le moteur 2

int motor1Speed = 0;        // Vitesse initiale pour le moteur 1
int motor2Speed = 0;        // Vitesse initiale pour le moteur 2
int buttonState = 0;        // Etat actuel du bouton poussoir
int buttonPressed = 0;      // Indique si le bouton a été pressé

void setup() {
  // Initialisation des broches en entrée ou sortie
  pinMode(buttonPin, INPUT);
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
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
