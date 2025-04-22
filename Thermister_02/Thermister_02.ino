// Thermister에서 측정한 온도가 20~40도 범위일 때 모터를 온도에 비례하는 속도로 회전한다
#include <L298N.h>  // L298N 라이브러리

// 핀 정의
#define ENA 9
#define IN1 8
#define IN2 7

// L298N 모터 객체 생성
L298N motor(ENA, IN1, IN2);

// 써미스터 파라미터 (수정 필요)
const float BETA = 3950;        // 베타 계수
const float R0 = 10000;         // 25°C 기준 저항
const float T0 = 298.15;        // 25°C 켈빈 온도

// 온도 제어 범위
const float MIN_TEMP = 20;      // 최소 온도 (°C)
const float MAX_TEMP = 40;      // 최대 온도 (°C)

void setup() {
  Serial.begin(9600);
  motor.setSpeed(0);  // 초기 속도 0
  motor.forward();    // 초기 방향: 정방향
}

void loop() {
  // 1. 써미스터 값 읽기
  int analogValue = analogRead(A0);
  
  // 2. 저항값 계산
  float R_thermistor = R0 * (1023.0 / analogValue - 1);
  
  // 3. 온도 계산 (Steinhart-Hart)
  float temperature = 1 / ( (1/BETA) * log(R_thermistor/R0) + (1/T0) );
  temperature -= 273.15;  // 켈빈 → 섭씨
  
  // 4. 모터 속도 계산
  int motorSpeed = 0;
  
  if (temperature >= MIN_TEMP && temperature <= MAX_TEMP) {
    motorSpeed = map(temperature, MIN_TEMP, MAX_TEMP, 0, 255);
    motorSpeed = constrain(motorSpeed, 0, 255);
  } 
  else if (temperature > MAX_TEMP) {
    motorSpeed = 255;  // 최대 속도
  }

  // 5. 모터 제어
  motor.setSpeed(motorSpeed);
  
  // (옵션) 45°C 초과 시 역방향 회전
  if (temperature > 45) {
    motor.backward();
    motor.setSpeed(255);  // 역방향 최대 속도
  }

  // 시리얼 모니터 출력
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print("°C | Speed: ");
  Serial.println(motorSpeed);
  
  delay(500);
}
