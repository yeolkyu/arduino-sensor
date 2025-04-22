int sensorPin = A0; //Potentiometer

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(sensorPin);
  sensorValue = float(sensorValue * 5.0/1024.0);
  Serial.println(sensorValue);
  delay(100);
}
