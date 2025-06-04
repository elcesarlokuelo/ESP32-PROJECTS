const int pinPIR = 23;
const int pinled = 22;

void setup() {
  Serial.begin(9600);
  pinMode(pinPIR, INPUT);
  pinMode(pinled, OUTPUT);
  digitalWrite(pinled, LOW);
  Serial.println("Comunicacion iniciada");
}

void loop() {
  if (digitalRead(pinPIR)) {
      Serial.println("Detectado movimiento");
      digitalWrite(pinled, HIGH);
  } else {
    digitalWrite(pinled, LOW);
  }
}
