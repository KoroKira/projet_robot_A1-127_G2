//code du groupe 2 pour le projet ecotech
//Mettez des commentaires bande de sacripans, c'est important pour que les gens qui repassent sur le code comprennent les changements faits et puissent être efficace après <3
//Contributeurs: Guilhem Desarcy-Lemiere, Thomas Del Gatto, Luca Desplat, Yanis Descazals

//Définition des broches pour les moteurs (moteur1 gauche moteur2 droite)
// Vitesse PWM en Digital, de 0 à 255
int moteur1 = 9;
int moteur2 = 10;

// Sens de rotation. IN1 et IN2 moteur gauche, IN3 et IN4 droite. Si IN1 HIGH IN2 LOW, Sens horaire. Si IN1 LOW IN2 HIGH, Sens antihoraire. Si IN3 HIGH IN4 LOW, Sens horaire. Si IN3 LOW IN4 HIGH, Sens antihoraire
int IN1 = 1;
int IN2 = 2;
int IN3 = 3;
int IN4 = 5;

//Définition des broches pour les capteurs infrarouge, en ANALOG
// regarder https://einstronic.com/product/infrared-line-tracking-sensor-module/ pour les capteurs
int capteur_gauche = A0;
int capteur_droit = A1;


//Définition des broches pour les capteurs de couleur
// regarder https://learn.adafruit.com/adafruit-color-sensors/library-reference pour le capteur
// A FAIRE


//Définition bouton marche
int button_marche = 0;
//Définition bouton ARU
int button_ARU = 0;
//Définition Relai
int relai = 0;


// Déclaration de la variable avant la fonction loop()

// Déclarations de fonctions
// Cette étape est indispensable afin que le robot puisse fonctionner. Il faut définir l'ensemble des fonctions qui seront utilisées
void avancer_droite();
void avancer_gauche();
void avancer();
void stopper();
void continuer();
void bascule();
void escalier();
void mousse();
void guillotine();

// Définitions de fonctions
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

void balance() {
  // Instructions pour passer la balance
  // SE METTRE DROIT PAR RAPPORT À LA LIGNE
  // ROULER DOUCEMENT (150-150)
  // UNE FOIS X SECONDES PASSÉES DE ROULER DROIT, SE REMETTRE AU DESSUS DE LA   LIGNE NOIRE BIEN DROITE
  // RELANCER VOID AVANCER
}

void escalier() {
  // Instructions pour passer les escaliers
  // SE METTRE DROIT PAR RAPPORT A LA LIGNE
  // ROULER DOUCEMENT PENDANT 3 SECONDES
  // ALLER À FOND, POUR PASSER L'ESCALIER UNE FOIS QUE L'AVANT EST PASSÉ DESSUS
  // UNE FOIS X TPS PASSÉ DESSUS POUR ETRE EN HAUT DE L'OBSTACLE
  // LÉGÈREMENT AVANCER, SE STOPPER POUR ETRE INCLINÉ CORRECTEMENT SUR LA PENTE DERRIÈRE L'ESCALIER
  // AVANCER ENSUITE POUR PASSER LA PENTE
  // RELANCER VOID AVANCER
}

void mousse() {
  // Instructions pour passer la mousse
  // A AJOUTER
}


void guillotine() {
  // Instructions pour passer la guillotine
  // A AJOUTER
}


void setup()
{
  //Définition des broches comme entrées/sorties
  pinMode(moteur1, OUTPUT);
  pinMode(moteur2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(capteur_gauche, INPUT);
  pinMode(capteur_droit, INPUT);
  pinMode(capteur_couleur, INPUT);
  
}

void loop()
{  
  // Lecture du capteur de couleur
  // A FAIRE
  // Lecture de la valeur du capteur infrarouge gauche puis droit
  int valeur_capteur_gauche = analogRead(A0);
  int valeur_capteur_droit = analogRead(A1);

  //Si les deux capteurs sont sur une surface noire
if (valeur_capteur_gauche < 500 && valeur_capteur_droit < 500) {
    avancer();
}
  //Si seul le capteur gauche est sur une surface noire
if (valeur_capteur_gauche < 500 && valeur_capteur_droit > 500) {
    avancer_gauche();
}
  //Si seul le capteur droit est sur une surface noire
if (valeur_capteur_gauche > 500 && valeur_capteur_droit < 500) {
    avancer_droite();
}
  //Si les deux capteurs ne sont pas sur une surface noire
if (valeur_capteur_gauche < 500 && valeur_capteur_droit < 500) {
    stopper();
}


  // Détection d'obstacle. Il faudra ici changer les valeurs détectées dans couleur. En gros, le ==1 signifie que il faut que la variable couleur soit égale a la variable définie dans 1, donc ici il faudra définir 1 par le code rgb associé
  
  if (couleur == 1) {
    balance();
  } else {
    continuer();
  }
  
  if (couleur == 2) {
    bascule();
  } else {
    continuer();
  }
  
  if (couleur == 3) {
    mousse();
  } else {
    continuer();
  }
  
  if (couleur == 4) {
    guillotine();
  } else {
    continuer();
  }

}

