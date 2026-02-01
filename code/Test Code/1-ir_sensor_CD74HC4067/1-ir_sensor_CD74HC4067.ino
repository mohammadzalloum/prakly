/*
  ESP32 + CD74HC4067 Test Read
  SIG -> GPIO35 (ADC1)
  S0  -> GPIO15
  S1  -> GPIO2
  S2  -> GPIO4
  S3  -> GPIO13
*/

#include <Arduino.h>

// MUX select pins (حسب جدولك)
const int MUX_S0 = 15;
const int MUX_S1 = 2;
const int MUX_S2 = 4;
const int MUX_S3 = 13;

// MUX SIG pin (Analog in)
const int MUX_SIG = 35;   // GPIO35 = input only, ممتاز للـ ADC

// لو بدك تسمي القنوات
const int CH_GATE_OUT = 0;
const int CH_GATE_IN  = 1;

const int CH_IR_1 = 2;
const int CH_IR_2 = 3;
const int CH_IR_3 = 4;

const int CH_IR_4 = 5;
const int CH_IR_5 = 6;
const int CH_IR_6 = 7;

const int CH_FLAME_1 = 8;
const int CH_FLAME_2 = 9;
const int CH_FLAME_3 = 10;

void muxSelectChannel(uint8_t ch) {
  // CD74HC4067: S0 أقل بت، S3 أعلى بت
  digitalWrite(MUX_S0, (ch >> 0) & 0x01);
  digitalWrite(MUX_S1, (ch >> 1) & 0x01);
  digitalWrite(MUX_S2, (ch >> 2) & 0x01);
  digitalWrite(MUX_S3, (ch >> 3) & 0x01);
}

int muxAnalogRead(uint8_t ch) {
  muxSelectChannel(ch);
  delayMicroseconds(50);          // وقت صغير لاستقرار الإشارة
  return analogRead(MUX_SIG);     // يرجع 0..4095 على ESP32
}

void setup() {
  Serial.begin(115200);

  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);
  pinMode(MUX_S3, OUTPUT);

  // إعدادات ADC في ESP32
  analogReadResolution(12);                 // 0..4095
  analogSetPinAttenuation(MUX_SIG, ADC_11db); // مدى أوسع (تقريباً حتى 3.3V)

  Serial.println("\n=== ESP32 + CD74HC4067 MUX Test ===");
}

void loop() {
  // اقرأ القنوات اللي عندك فقط (0..10)
  int v0  = muxAnalogRead(CH_GATE_OUT);
  int v1  = muxAnalogRead(CH_GATE_IN);

  int ir1 = muxAnalogRead(CH_IR_1);
  int ir2 = muxAnalogRead(CH_IR_2);
  int ir3 = muxAnalogRead(CH_IR_3);
  int ir4 = muxAnalogRead(CH_IR_4);
  int ir5 = muxAnalogRead(CH_IR_5);
  int ir6 = muxAnalogRead(CH_IR_6);

  int f1  = muxAnalogRead(CH_FLAME_1);
  int f2  = muxAnalogRead(CH_FLAME_2);
  int f3  = muxAnalogRead(CH_FLAME_3);

  Serial.println("----- MUX Readings (0..4095) -----");
  Serial.printf("GATES: C0(out)=%4d | C1(in)=%4d\n", v0, v1);

  Serial.printf("IR:    C2=%4d C3=%4d C4=%4d | C5=%4d C6=%4d C7=%4d\n",
                ir1, ir2, ir3, ir4, ir5, ir6);

  Serial.printf("FLAME: C8=%4d C9=%4d C10=%4d\n", f1, f2, f3);

  // مثال “كشف” بسيط بعتبات (عدّلها حسب حساساتك)
  // بعض حساسات IR / Flame تعطي قيمة أقل عند الكشف أو العكس حسب الموديول
  const int TH_IR    = 2000;  // مثال فقط
  const int TH_FLAME = 2000;  // مثال فقط

  Serial.print("Detect: IR(");
  Serial.printf("%d,%d,%d,%d,%d,%d)  ",
                ir1 < TH_IR, ir2 < TH_IR, ir3 < TH_IR, ir4 < TH_IR, ir5 < TH_IR, ir6 < TH_IR);

  Serial.print("Flame(");
  Serial.printf("%d,%d,%d)\n",
                f1 < TH_FLAME, f2 < TH_FLAME, f3 < TH_FLAME);

  delay(500);
}
