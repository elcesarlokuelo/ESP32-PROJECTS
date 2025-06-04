//Programa sencillo que enciende 4 LEDs consecutivamente. 
//Tambien transmite por el puerto serie que led ha encendido
const int pinLED1 = 5;  //Pin del led1
const int pinLED2 = 18;   //pin del led2
const int pinLED3 = 19;  //pin del led3
const int pinLED4 = 21;  //pin del led4

void setup() {
  pinMode(pinLED1, OUTPUT);
  pinMode(pinLED2, OUTPUT);
  pinMode(pinLED3, OUTPUT);
  pinMode(pinLED4, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(pinLED1, HIGH);
  Serial.write("Led1 encendido\n");
  delay(1000);
  digitalWrite(pinLED1, LOW);
  digitalWrite(pinLED2, HIGH);
  Serial.write("Led2 encendido\n");
  delay(1000);
  digitalWrite(pinLED2, LOW);
  digitalWrite(pinLED3, HIGH);
  Serial.write("Led3 encendido\n");
  delay(1000);
  digitalWrite(pinLED3, LOW);
  digitalWrite(pinLED4, HIGH);
  Serial.write("Led4 encendido\n");
  delay(1000);
  digitalWrite(pinLED4, LOW);
}
