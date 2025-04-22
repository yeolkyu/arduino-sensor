#include <L298N.h>

// 핀 설정 (ENABLE, IN1, IN2)
L298N motor(9, 8, 7); // Enable, IN1, IN2

void setup() {}

void loop() {
  motor.setSpeed(255); // 속도 설정 (0~255)
  motor.forward();     // 전진
  delay(2000);
  motor.stop();        // 정지
  delay(1000);
  motor.backward();    // 후진
  delay(2000);
}
