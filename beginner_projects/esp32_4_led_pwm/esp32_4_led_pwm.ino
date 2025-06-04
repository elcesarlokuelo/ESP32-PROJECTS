//4 LEDs controlled with PWM
const int pinled1 = 5;
const int pinled2 = 18;
const int pinled3 = 19;
const int pinled4 = 21;

int i;

void setup() {
  pinMode(pinled1, OUTPUT);
  pinMode(pinled2, OUTPUT);
  pinMode(pinled3, OUTPUT);
  pinMode(pinled4, OUTPUT);
}

void loop() {
  // increase LED brightness
  for (i = 0; i <= 510; i++) {
    if (i <= 255) {  //control del led1
      analogWrite(pinled1, i);
    } else {
        analogWrite(pinled1, 510 - i);
      }

    if (i <= 127) {  //control del led 2
      analogWrite(pinled2, 127 - i);
    } else if (i > 127 && i <= 382) {
      analogWrite(pinled2, i - 127);
    } else {
      analogWrite(pinled2, 636 - i);
    }

    if (i <= 255) {  //control del led3
      analogWrite(pinled3, 255 - i);
    } else {
        analogWrite(pinled3, i - 255);
      }

    if (i <= 127) {  //control del led 4
      analogWrite(pinled4, 127 + i);
    } else if (i > 127 && i <= 382) {
      analogWrite(pinled4, 382 - i);
    } else {
      analogWrite(pinled4, i - 382);
    }
    delay(2);
  }
}
