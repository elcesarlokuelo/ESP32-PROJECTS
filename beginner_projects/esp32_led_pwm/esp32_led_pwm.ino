//LED control with PWM
const int pinled1=18; //led pin GPIO18

void setup() {
  pinMode(pinled1,OUTPUT);
}

void loop() {
  // increase LED brightness
  for(int dutyCycle = 0; dutyCycle <= 255; dutyCycle++){   
    // changing the LED brightness with PWM
    analogWrite(pinled1, dutyCycle);
    delay(15);
  }
  // decrease the LED brightness
  for(int dutyCycle = 255; dutyCycle >= 0; dutyCycle--){
    // changing the LED brightness with PWM
    analogWrite(pinled1, dutyCycle);
    delay(15);
  }
}
