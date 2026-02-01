#define BUZZER_PIN 16

int ch = -1;

void setup() {
  Serial.begin(115200);
  // attach PWM to pin, returns channel number
  ch = ledcAttach(BUZZER_PIN, 2000, 10);  // 2kHz, 10-bit
  if (ch < 0) Serial.println("ledcAttach failed");
}

void loop() {
  // صفير 2kHz
  ledcWriteTone(ch, 2000);
  ledcWrite(ch, 512);   // 50% duty (0..1023)
  delay(500);

  // صفير 3kHz
  ledcWriteTone(ch, 3000);
  ledcWrite(ch, 512);
  delay(500);

  // إيقاف
  ledcWrite(ch, 0);
  ledcWriteTone(ch, 0);
  delay(700);
}
