// 핀 정의
const int THERMISTOR_PIN = A0;  // NTC-10K 써미스터가 연결된 아날로그 핀

// 분압 저항 값
const float R1 = 10000;         // 10kΩ 분압 저항

// Steinhart-Hart 계수 (NTC-10K 대표값)
const float A = 1.129148e-3;    // A 계수
const float B = 2.34125e-4;     // B 계수
const float C = 8.775468e-8;    // C 계수

void setup() {
  Serial.begin(9600);           // 시리얼 통신 시작
}

void loop() {
  // 아날로그 값 읽기 (0-1023)
  int sensorValue = analogRead(THERMISTOR_PIN);
  
  // 써미스터 저항값 계산
  float resistance = R1 * (1023.0 / sensorValue - 1.0);
  
  // Steinhart-Hart 방정식 적용
  float lnR = log(resistance);  // 자연로그 계산
  float temperature = 1.0 / (A + B * lnR + C * pow(lnR, 3)); // 절대온도(K)
  temperature = temperature - 273.15;  // 섭씨로 변환
  
  // 결과 출력
  Serial.print("Resistance: ");
  Serial.print(resistance);
  Serial.print(" Ω, Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  
  delay(1000);  // 1초 대기
}
