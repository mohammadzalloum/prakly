#include <Wire.h>

// ===== I2C pins على ESP32 حسب توصيلك =====
#define I2C_SDA 21
#define I2C_SCL 22

// ===== عنوان PCF8574 =====
// غالباً 0x20 إذا A0/A1/A2 = GND. إذا ما اشتغل جرّب 0x21..0x27 أو 0x38..0x3F (PCF8574A)
uint8_t PCF_ADDR = 0x20;

// ===== هل الليدات موصلة بطريقة Active-LOW؟ =====
// الشائع مع PCF8574: توصل LED + مقاومة إلى VCC والـ PCF يسحب للأرضي => ON لما تكتب 0
const bool ACTIVE_LOW = true;

// حالة مخارج PCF (كل بت يمثل pin)
uint8_t pcfState = 0xFF; // كلهم HIGH (عادة OFF إذا Active-Low)

void pcfWrite(uint8_t value) {
  Wire.beginTransmission(PCF_ADDR);
  Wire.write(value);
  Wire.endTransmission();
}

void pcfSetPin(uint8_t pin, bool on) {
  // on = true يعني "شغل الليد"
  bool level = on;
  if (ACTIVE_LOW) level = !on; // active-low: شغل = 0

  if (level) pcfState |=  (1 << pin);
  else       pcfState &= ~(1 << pin);

  pcfWrite(pcfState);
}

void pcfAllOff() {
  pcfState = ACTIVE_LOW ? 0xFF : 0x00;
  pcfWrite(pcfState);
}

void pcfAllOn() {
  pcfState = ACTIVE_LOW ? 0x00 : 0xFF;
  pcfWrite(pcfState);
}

// ===== توزيع الليدات على PCF (عدّلها حسب توصيلك الحقيقي) =====
const uint8_t LED1_R = 0; // P0
const uint8_t LED1_G = 1; // P1
const uint8_t LED2_R = 2; // P2
const uint8_t LED2_G = 3; // P3
const uint8_t LED3_R = 4; // P4
const uint8_t LED3_G = 5; // P5
const uint8_t LED4_R = 6; // P6
const uint8_t LED4_G = 7; // P7

// ===== LED5 على ESP32 مباشرة =====
const int LED5_R = 14;
const int LED5_G = 12;

void i2cScan() {
  Serial.println("\nI2C scan...");
  int found = 0;
  for (uint8_t addr = 1; addr < 127; addr++) {
    Wire.beginTransmission(addr);
    if (Wire.endTransmission() == 0) {
      Serial.printf("Found device at 0x%02X\n", addr);
      found++;
    }
  }
  if (!found) Serial.println("No I2C devices found.");
  Serial.println("Done.\n");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  pinMode(LED5_R, OUTPUT);
  pinMode(LED5_G, OUTPUT);
  digitalWrite(LED5_R, LOW);
  digitalWrite(LED5_G, LOW);

  // افحص عناوين I2C (اختياري لكن مفيد)
  i2cScan();

  // اطفئ كل ليدات PCF بالبداية
  pcfAllOff();

  Serial.println("PCF8574 LED Test شروع...");
}

void loop() {
  // 1) شغل/اطفئ كل ليد على PCF بالتسلسل
  uint8_t leds[] = {LED1_R, LED1_G, LED2_R, LED2_G, LED3_R, LED3_G, LED4_R, LED4_G};
  for (uint8_t i = 0; i < sizeof(leds); i++) {
    pcfAllOff();
    pcfSetPin(leds[i], true);
    delay(250);
  }
  pcfAllOff();

  // 2) نمط: كل الأحمر ON ثم كل الأخضر ON
  pcfAllOff();
  pcfSetPin(LED1_R, true); pcfSetPin(LED2_R, true); pcfSetPin(LED3_R, true); pcfSetPin(LED4_R, true);
  delay(400);
  pcfAllOff();
  pcfSetPin(LED1_G, true); pcfSetPin(LED2_G, true); pcfSetPin(LED3_G, true); pcfSetPin(LED4_G, true);
  delay(400);
  pcfAllOff();

  // 3) اختبار LED5 (على ESP32 مباشرة)
  digitalWrite(LED5_R, HIGH);
  digitalWrite(LED5_G, LOW);
  delay(300);
  digitalWrite(LED5_R, LOW);
  digitalWrite(LED5_G, HIGH);
  delay(300);
  digitalWrite(LED5_R, LOW);
  digitalWrite(LED5_G, LOW);

  delay(500);
}
