int sensor1 = A0; //Potentiometer
int sensor2 = A1; // Photo Cell(CdS)

void setup() {
  Serial.begin(9600);
}
void loop() {
  int value1 = analogRead(sensor1);
  int value2 = analogRead(sensor2);
  Serial.print("Sensor1: ");
  Serial.print(value1);
  Serial.print(" | Sensor2: ");
  Serial.println(value2); // 마지막 값은 println()으로 줄 바꿈
  delay(500);
}
