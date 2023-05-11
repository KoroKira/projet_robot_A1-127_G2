const int ledPin = 13;
const int stopPin = 12;
const int emergencyPin = A0;
int ledState = LOW;
int stopState = HIGH;
int n = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(stopPin, INPUT_PULLUP);
  pinMode(emergencyPin, INPUT_PULLUP);
  digitalWrite(ledPin, ledState);
  Serial.begin(9600);
}

void loop() {
  stopState = digitalRead(stopPin);
  
  if (stopState == LOW) {
    n = n + 1;  // Incrémente la valeur de n si le bouton est cliqué
    delay(200); // Délai pour éviter les rebonds du bouton
  }

  if (n % 2 == 1) { // Si n est impair, allume la lampe
    digitalWrite(ledPin, HIGH);
  } else { // Si n est pair, éteint la lampe
    digitalWrite(ledPin, LOW);
  }

  Serial.println(digitalRead(stopPin));
}
