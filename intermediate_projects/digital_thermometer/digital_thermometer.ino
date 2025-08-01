//code for a digital thermometer
const int pinADC = 15;

int Dout = 0;
float Vout = 0;
float R = 0;
float TempK = 0;
float TempAcum = 0;
float Temp = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Digital thermometer using a NTC thermistor");
  delay(1000);
}

void loop() {
  for (int i = 0; i<10; i++) {
    Dout = analogRead(pinADC);
    //Serial.println(Dout); //with this we see the digital value directly
    Vout = Dout * (3.3 / 4095.0);  //Voltage reading
    //Serial.println(Vout); //with this we see the voltage value to see if it has sense
    R = ((10000 * 3.3) / Vout) - 10000;
    //Serial.println(R); //with this we see the resistance value
    TempK = 1.0 / ((1.0 / 298.15) + (1.0 / 3950.0) * log(R / 20000));
    Temp= TempK - 273.15;
    TempAcum=TempAcum+Temp;
    delay(100);
  }
  Temp=TempAcum/10;
  TempAcum = 0;
  Serial.print("Temperature: ");
  Serial.print(Temp);
  Serial.println(" ºC");
}
