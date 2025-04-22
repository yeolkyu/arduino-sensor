#include <math.h>

// L298 모터 드라이브 핀 설정
const int IN1 = 7;  // 모터 방향 제어 핀 1
const int IN2 = 8;  // 모터 방향 제어 핀 2
const int ENA = 9;  // 모터 속도 제어 PWM 핀

// 써미스터 관련 상수
const float R_FIXED = 10000.0;  // 고정 저항 (10kΩ)
const float VCC = 5.0;          // 전원 전압 (5V)
const float R0 = 10000.0;       // 기준 저항 (25°C에서 10kΩ)
const float T0 = 298.15;        // 기준 온도 (25°C, 단위: K)
const float BETA = 3950.0;      // 베타 상수 (단위: K, 예: 3950K)

void setup() {
  // 모터 제어 핀을 출력으로 설정
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // 시리얼 통신 시작 (디버깅용)
  Serial.begin(9600);
}

void loop() {
  // A0 핀에서 아날로그 값 읽기 (0~1023)
  int sensorValue = analogRead(A0);

  // 측정된 전압 계산
  float Vout = (sensorValue / 1023.0) * VCC;

  // 써미스터 저항 계산 (전압 분배기 공식)
  float R_thermistor = R_FIXED * (VCC / Vout - 1.0);

  // 베타 상수 공식을 사용하여 온도 계산 (단위: K)
  float T = 1.0 / ((1.0 / T0) + (1.0 / BETA) * log(R_thermistor / R0));
  float tempC = T - 273.15;  // 섭씨 온도로 변환

  // 디버깅용 온도 출력
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println(" C");

  // 온도에 따라 모터 속도 결정
  int speed;
  if (tempC < 20.0) {
    speed = 0;  // 20°C 미만: 모터 정지
  } else if (tempC >= 20.0 && tempC <= 30.0) {
    // 20°C ~ 30°C: 온도에 비례하여 속도 증가 (0~255)
    speed = map(tempC * 10, 200, 300, 0, 255);  // 소수점 처리를 위해 *10
  } else {
    speed = 255;  // 30°C 이상: 최대 속도
  }

  // 모터를 정방향으로 회전
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, speed);  // 계산된 속도로 PWM 출력

  // 1초 대기
  delay(1000);
}
