#include <Arduino.h>
#include <ESP32Servo.h>

Servo myServo;
const int SERVO_PIN = 23;

void setup() {
  Serial.begin(115200);

  // تردد السيرفو عادة 50Hz
  myServo.setPeriodHertz(50);

  // attach(pin, minPulse, maxPulse) — قيم شائعة لمعظم السيرفو
  myServo.attach(SERVO_PIN, 500, 2400);

  Serial.println("Servo test on GPIO23 started");
}

void loop() {
  // 0 إلى 180
  // for (int angle = 0; angle <= 180; angle += 1) {
  //   myServo.write(angle);
  //   delay(15);
  // }

  // delay(500);

  // // 180 إلى 0
  // for (int angle = 180; angle >= 0; angle -= 1) {
  //   myServo.write(angle);
  //   delay(15);
  // }
myServo.write(0);
  delay(500);
myServo.write(180);
  delay(500);
// myServo.write(0);

}
