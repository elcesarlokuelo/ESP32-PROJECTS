//Programa sencillo que enciende un LED 1s y lo apaga 1s
const int pinLED=2; //Pin del led integrado

void setup() {
  pinMode(pinLED,OUTPUT);
}

void loop() {
  digitalWrite(pinLED,HIGH);
  delay(1000);
  digitalWrite(pinLED,LOW);
  delay(1000);
}
