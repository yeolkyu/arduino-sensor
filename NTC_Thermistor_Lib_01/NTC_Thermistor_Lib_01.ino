#include <NTC_Thermistor.h> // NTC Thermistor Library

// NTC Thermistor 설정
const int pin = A0; // Thermistor 연결 핀
const float R0 = 10000.0; // Thermistor의 기준 저항 (10KΩ)
const float Rn = 10000.0; // Thermistor의 명시 저항 (10KΩ)
const float Tn = 25.0; // Thermistor의 기준 온도 (25°C)
const float B = 3950.0; // Thermistor의 B 값

NTC_Thermistor thermistor(pin, R0, Rn, Tn, B);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // 온도 읽기
  double celsius = thermistor.readCelsius();
  double fahrenheit = thermistor.readFahrenheit();
  double kelvin = thermistor.readKelvin();

  // 온도 출력
  Serial.print("Temperature (Celsius): ");
  Serial.print(celsius);
  Serial.print("°C, ");
  Serial.print("Temperature (Fahrenheit): ");
  Serial.print(fahrenheit);
  Serial.print("°F, ");
  Serial.print("Temperature (Kelvin): ");
  Serial.print(kelvin);
  Serial.println(" K");

  delay(1000); // 1초마다 측정
}
