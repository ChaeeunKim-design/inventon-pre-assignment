#define LED_PIN 9  // LED가 연결된 아두이노 디지털 핀 번호를 9번으로 정의

void setup() {
  pinMode(LED_PIN, OUTPUT);   // LED 핀을 출력 모드로 설정하여 LED를 켜고 끌 수 있게 함
  Serial.begin(9600);         // 시리얼 통신을 9600 보드레이트로 시작 (PC와 아두이노 간 통신 설정)
}

void loop() {
  // 시리얼 버퍼에 데이터가 들어와 있는지 확인
  if (Serial.available()) {
    // 시리얼 입력에서 한 줄(개행문자 '\n'까지) 읽어 문자열로 저장
    String command = Serial.readStringUntil('\n');

    // 입력받은 문자열 앞뒤 공백과 개행문자 제거
    command.trim();

    // 입력된 명령어가 "ON"인지 비교
    if (command == "ON") {
      digitalWrite(LED_PIN, HIGH);   // LED 핀에 HIGH 신호를 줘서 LED 켬
      Serial.println("LED ON");      // LED가 켜졌다는 메시지를 시리얼 모니터에 출력
    }
    // 입력된 명령어가 "OFF"인지 비교
    else if (command == "OFF") {
      digitalWrite(LED_PIN, LOW);    // LED 핀에 LOW 신호를 줘서 LED 끔
      Serial.println("LED OFF");     // LED가 꺼졌다는 메시지를 시리얼 모니터에 출력
    }
    // "ON"이나 "OFF"가 아닌 다른 명령어는 무시됨 (필요시 처리 추가 가능)
  }
  // 시리얼 데이터가 없으면 loop를 계속 돌며 대기함
}
