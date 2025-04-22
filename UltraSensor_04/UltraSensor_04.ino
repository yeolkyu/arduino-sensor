#include <NewPing.h>

#define TRIGGER_PIN  7    // Trig 핀을 D7에 연결
#define ECHO_PIN     8    // Echo 핀을 D8에 연결
#define MAX_DISTANCE 200  // 최대 측정 거리 (cm 단위)

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing 객체 생성

void setup() {
  Serial.begin(9600); // 시리얼 통신 시작 (9600 baud)
}

void loop() {
  delay(50);                    // 각 측정 사이에 50ms 대기
  unsigned int distance = sonar.ping_cm(); // 거리 측정 (cm 단위)
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
}
