#include <PlayRtttl.hpp>

// 스피커가 연결된 핀 번호 (예: 9번 핀)
const int speakerPin = 5;

void setup() {
  // Flintstones RTTTL 멜로디
  startPlayRtttl(speakerPin, Flinstones);
}

void loop() {
  // 멜로디 재생 업데이트
  if (!updatePlayRtttl()) {
    startPlayRtttl(speakerPin, Flinstones);
  }
}
