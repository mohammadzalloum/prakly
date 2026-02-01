/*
  ESP32 + 4-Channel Relay Test
  IN1=17, IN2=5, IN3=18, IN4=19
*/

#include <Arduino.h>

const int RELAY1 = 17;
const int RELAY2 = 5;
const int RELAY3 = 18;
const int RELAY4 = 19;

const bool ACTIVE_LOW = true;   // غيّرها false إذا ريليه عندك Active-High

void relayWrite(int pin, bool on) {
  if (ACTIVE_LOW) {
    digitalWrite(pin, on ? LOW : HIGH);
  } else {
    digitalWrite(pin, on ? HIGH : LOW);
  }
}

void allRelaysOff() {
  relayWrite(RELAY1, false);
  relayWrite(RELAY2, false);
  relayWrite(RELAY3, false);
  relayWrite(RELAY4, false);
}

void setup() {
  Serial.begin(115200);

  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  allRelaysOff();

  Serial.println("\n=== 4-Channel Relay Test ===");
}

void loop() {
  // 1) تشغيل بالتسلسل
  allRelaysOff();
  Serial.println("Sequence ON one-by-one");

  relayWrite(RELAY1, true); Serial.println("R1 ON"); delay(600);
  relayWrite(RELAY1, false);

  relayWrite(RELAY2, true); Serial.println("R2 ON"); delay(600);
  relayWrite(RELAY2, false);

  relayWrite(RELAY3, true); Serial.println("R3 ON"); delay(600);
  relayWrite(RELAY3, false);

  relayWrite(RELAY4, true); Serial.println("R4 ON"); delay(600);
  relayWrite(RELAY4, false);

  delay(800);

  // 2) تشغيل الكل ثم إطفاء الكل
  Serial.println("All ON");
  relayWrite(RELAY1, true);
  relayWrite(RELAY2, true);
  relayWrite(RELAY3, true);
  relayWrite(RELAY4, true);
  delay(1000);

  Serial.println("All OFF");
  allRelaysOff();
  delay(1200);
}
