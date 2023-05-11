const int ledPin = 13;
const int stopPin = 12;
const int emergencyPin = A0;
int ledState = LOW;
int stopState = HIGH;

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
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
Serial.println(digitalRead(stopPin));

}
