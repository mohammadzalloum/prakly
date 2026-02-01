#include <Wire.h>
#include <Adafruit_INA219.h>

// ===== ESP32 I2C pins حسب توصيلك =====
#define I2C_SDA 21
#define I2C_SCL 22

// ===== عنوان TCA9548A =====
// الافتراضي غالباً 0x70 (A0/A1/A2 = GND)
#define TCA_ADDR 0x70

// ===== قنوات INA219 عندك على TCA =====
const uint8_t INA_CHANNELS[] = {2, 3, 4};   // sda2/scl2, sda3/scl3, sda4/scl4
const uint8_t NUM_INA = sizeof(INA_CHANNELS) / sizeof(INA_CHANNELS[0]);

// ===== عنوان INA219 =====
#define INA_ADDR 0x40

Adafruit_INA219 ina[NUM_INA] = {
  Adafruit_INA219(INA_ADDR),
  Adafruit_INA219(INA_ADDR),
  Adafruit_INA219(INA_ADDR)
};

// اختيار قناة في TCA9548A
void tcaSelect(uint8_t channel) {
  if (channel > 7) return;
  Wire.beginTransmission(TCA_ADDR);
  Wire.write(1 << channel);  // يفعّل قناة واحدة
  Wire.endTransmission();
  delayMicroseconds(200);
}

// فحص وجود جهاز I2C (عنوان معيّن) على القناة الحالية
bool i2cPing(uint8_t addr) {
  Wire.beginTransmission(addr);
  return (Wire.endTransmission() == 0);
}

// سكان سريع لكل قناة (اختياري)
void scanTcaChannels() {
  Serial.println("\n=== I2C Scan عبر قنوات TCA9548A ===");
  for (uint8_t ch = 0; ch < 8; ch++) {
    tcaSelect(ch);
    bool found = false;

    for (uint8_t addr = 1; addr < 127; addr++) {
      Wire.beginTransmission(addr);
      if (Wire.endTransmission() == 0) {
        if (!found) {
          Serial.printf("CH%d: ", ch);
          found = true;
        }
        Serial.printf("0x%02X ", addr);
      }
    }

    if (found) Serial.println();
  }
  Serial.println("==================================\n");
}

void setup() {
  Serial.begin(115200);
  Wire.begin(I2C_SDA, I2C_SCL);

  // (مفيد) اعمل scan لتتأكد كل شيء ظاهر
  scanTcaChannels();

  // تهيئة كل INA219 على قناته
  for (uint8_t i = 0; i < NUM_INA; i++) {
    uint8_t ch = INA_CHANNELS[i];
    tcaSelect(ch);

    if (!i2cPing(INA_ADDR)) {
      Serial.printf("INA219 غير موجود على CH%d (العنوان 0x%02X)\n", ch, INA_ADDR);
      continue;
    }

    if (!ina[i].begin()) {
      Serial.printf("فشل تهيئة INA219 على CH%d\n", ch);
    } else {
      Serial.printf("تم تهيئة INA219 على CH%d (0x%02X)\n", ch, INA_ADDR);
      // لو بدك معايرة مختلفة: ina[i].setCalibration_32V_2A();  (مثلاً)
    }
  }

  Serial.println("\nابدأ قراءة الحساسات...\n");
}

void loop() {
  for (uint8_t i = 0; i < NUM_INA; i++) {
    uint8_t ch = INA_CHANNELS[i];
    tcaSelect(ch);

    // لو الحساس مش موجود، تخطّاه
    if (!i2cPing(INA_ADDR)) {
      Serial.printf("CH%d: لا يوجد INA219\n", ch);
      continue;
    }

    float busV   = ina[i].getBusVoltage_V();      // فولت على خط VBUS
    float shuntmV= ina[i].getShuntVoltage_mV();   // فرق فولت على الشنت
    float currentmA = ina[i].getCurrent_mA();     // تيار mA
    float powermW   = ina[i].getPower_mW();       // قدرة mW

    Serial.printf("CH%d | Bus: %.3f V | Shunt: %.3f mV | I: %.2f mA | P: %.2f mW\n",
                  ch, busV, shuntmV, currentmA, powermW);
  }

  Serial.println("----");
  delay(1000);
}
