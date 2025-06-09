//button with esp32
int button_pin=21;

int last_state = HIGH;
int current_state;

void setup() {
  Serial.begin(9600);
  pinMode(button_pin, INPUT_PULLUP);
}

void loop() {
  current_state= digitalRead(button_pin);
  if(last_state==LOW && current_state==HIGH){
    Serial.println("button touched");
  }
  last_state = current_state;
  delay(50);
}
