#define BUZZER 4  // 부저를 연결한 핀

void setup() {
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    tone(BUZZER, 1000); // 1000Hz 소리 출력 (삐-)
    delay(500);         // 0.5초 대기
    noTone(BUZZER);     // 소리 끄기
    delay(500);         // 0.5초 대기
}
