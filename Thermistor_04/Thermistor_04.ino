#include <NTC_Thermistor.h> //ver 2.0.3. NOT 2.1

// 핀과 NTC 써미스터의 특성 정의
#define SENSOR_PIN A0
#define REFERENCE_RESISTANCE 10000  // 기준 저항 값 (10kΩ)
#define NOMINAL_RESISTANCE 10000    // 공칭 저항 값 (25°C에서 10kΩ)
#define NOMINAL_TEMPERATURE 25      // 공칭 온도 (°C)
#define B_VALUE 3950               // 베타 값

// NTC_Thermistor 객체 생성
NTC_Thermistor thermistor(
  SENSOR_PIN,
  REFERENCE_RESISTANCE,
  NOMINAL_RESISTANCE,
  NOMINAL_TEMPERATURE,
  B_VALUE
);

void setup() {
  Serial.begin(9600);
  Serial.println("NTC Thermistor Temperature Reading");
}

void loop() {
  // 온도 읽기
  double celsius = thermistor.readCelsius();
  double fahrenheit = thermistor.readFahrenheit();
  double kelvin = thermistor.readKelvin();

  // 결과 출력
  Serial.print("Temperature: ");
  Serial.print(celsius);
  Serial.print(" °C / ");
  Serial.print(fahrenheit);
  Serial.print(" °F / ");
  Serial.print(kelvin);
  Serial.println(" K");

  delay(1000); // 1초 대기
}
