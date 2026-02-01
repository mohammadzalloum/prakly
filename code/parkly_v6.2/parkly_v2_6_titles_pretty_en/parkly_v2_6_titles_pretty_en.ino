// -----------------------------------------------------------------------------
// ========================= RemoteXY include library ==========================
// -----------------------------------------------------------------------------


#define REMOTEXY_MODE__WIFI_POINT

#include <WiFi.h>
#include <EEPROM.h>

#define REMOTEXY_WIFI_SSID "Parkly_wifi"
#define REMOTEXY_WIFI_PASSWORD "12345678"
#define REMOTEXY_SERVER_PORT 6377
#define REMOTEXY_ACCESS_PASSWORD "12345678"


#include <RemoteXY.h>

#pragma pack(push, 1)  
uint8_t const PROGMEM RemoteXY_CONF_PROGMEM[] =
  { 254,75,0,112,0,1,0,8,0,1,0,65,1,0,120,11,21,0,0,0,
  80,97,114,107,108,121,95,119,105,102,105,0,31,1,106,200,5,6,6,6,
  7,2,37,0,130,1,14,104,85,11,17,1,35,27,33,19,1,2,31,0,
  74,34,33,34,8,17,2,8,64,66,111,111,107,0,12,64,66,111,111,107,
  100,0,129,18,17,76,9,64,8,83,101,99,116,105,111,110,32,49,32,40,
  69,108,101,99,116,114,105,99,41,0,129,36,2,31,11,64,8,80,97,114,
  107,108,121,0,131,5,189,45,9,2,17,2,31,83,101,116,116,105,110,103,
  115,0,166,2,129,3,31,31,12,64,8,112,97,114,107,49,0,129,3,55,
  31,12,64,8,112,97,114,107,50,0,129,3,78,31,12,64,8,112,97,114,
  107,51,0,1,35,50,33,19,1,2,31,0,74,34,56,34,8,17,2,8,
  64,66,111,111,107,0,12,64,66,111,111,107,100,0,1,35,73,33,19,1,
  2,31,0,74,34,79,34,8,17,8,8,64,66,111,111,107,0,12,64,66,
  111,111,107,100,0,130,1,101,104,85,11,17,1,35,115,33,19,1,2,31,
  0,74,34,121,34,8,17,8,8,64,66,111,111,107,0,12,64,66,111,111,
  107,100,0,129,34,104,38,9,64,8,83,101,99,116,105,111,110,32,50,0,
  129,3,119,31,12,64,8,112,97,114,107,52,0,129,3,143,31,12,64,8,
  112,97,114,107,53,0,129,3,167,31,12,64,8,112,97,114,107,54,0,1,
  35,138,33,19,1,2,31,0,74,34,144,34,8,17,12,8,64,66,111,111,
  107,0,12,64,66,111,111,107,100,0,1,35,161,33,19,1,2,31,0,74,
  34,168,34,8,17,2,8,64,66,111,111,107,0,12,64,66,111,111,107,100,
  0,70,70,27,33,19,33,26,37,135,0,74,71,34,31,5,17,2,31,192,
  65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,32,65,118,97,105,
  108,97,98,108,101,0,70,70,50,33,19,33,26,37,135,0,74,71,57,31,
  5,17,2,31,192,65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,
  32,65,118,97,105,108,97,98,108,101,0,70,70,73,33,19,33,26,37,135,
  0,74,72,80,30,5,17,2,31,192,65,118,97,105,108,97,98,108,101,0,
  31,64,110,111,116,32,65,118,97,105,108,97,98,108,101,0,70,70,115,33,
  19,33,26,37,135,0,74,72,123,30,5,17,2,31,192,65,118,97,105,108,
  97,98,108,101,0,31,64,110,111,116,32,65,118,97,105,108,97,98,108,101,
  0,70,70,138,33,19,33,26,37,135,0,74,71,146,31,5,17,2,31,192,
  65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,32,65,118,97,105,
  108,97,98,108,101,0,70,70,161,33,19,33,26,37,135,0,74,71,169,31,
  5,17,2,31,192,65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,
  32,65,118,97,105,108,97,98,108,101,0,131,55,189,45,9,2,17,2,31,
  67,104,97,114,103,101,0,170,1,19,0,130,2,87,102,64,11,17,129,13,
  92,84,12,64,24,65,100,109,97,105,110,32,65,99,99,101,115,115,0,7,
  49,107,43,10,65,64,2,26,11,129,10,108,37,8,64,24,85,115,101,114,
  110,97,109,101,0,129,10,121,36,8,64,24,80,97,115,115,119,111,114,100,
  0,1,26,133,53,13,1,2,31,0,129,42,136,19,8,64,31,69,110,116,
  101,114,0,7,49,120,43,10,65,64,2,26,11,130,2,17,101,64,11,17,
  129,24,22,61,12,64,24,80,114,111,32,65,99,99,101,115,115,0,7,49,
  37,43,10,65,64,2,26,11,129,10,38,37,8,64,24,85,115,101,114,110,
  97,109,101,0,129,10,51,36,8,64,24,80,97,115,115,119,111,114,100,0,
  1,26,63,53,13,1,2,31,0,129,44,66,19,8,64,31,69,110,116,101,
  114,0,7,49,50,43,10,65,64,2,26,11,129,35,4,31,11,64,8,80,
  97,114,107,108,121,0,130,3,155,100,24,11,17,131,8,160,91,14,2,2,
  2,31,66,97,99,107,32,116,111,32,115,116,97,110,100,97,114,100,32,112,
  97,103,101,0,106,2,60,0,130,2,75,102,76,11,17,1,3,91,23,17,
  1,2,31,0,129,11,82,38,9,64,8,83,101,99,116,105,111,110,32,49,
  0,129,59,82,38,9,64,8,83,101,99,116,105,111,110,32,50,0,1,3,
  110,23,17,1,2,31,0,1,3,130,23,17,1,2,31,0,1,54,91,23,
  17,1,2,31,0,1,54,110,23,17,1,2,31,0,1,54,129,23,17,1,
  2,31,0,129,36,2,31,11,64,8,80,97,114,107,108,121,0,130,2,12,
  101,37,11,17,129,20,13,60,8,64,8,102,105,114,101,32,97,108,97,114,
  109,32,115,101,110,115,111,114,0,70,48,22,43,12,33,26,37,135,0,130,
  2,152,102,17,11,17,129,36,153,35,6,64,8,76,105,103,104,116,32,67,
  111,110,116,114,111,108,0,2,22,159,61,9,1,2,26,31,31,79,78,0,
  79,70,70,0,130,2,51,102,23,11,17,129,36,51,32,6,64,8,71,97,
  116,101,32,83,116,97,116,117,115,0,129,9,37,37,8,64,8,70,105,114,
  101,32,65,108,97,114,109,0,1,48,35,43,12,1,2,31,0,129,61,37,
  17,8,64,31,83,116,111,112,0,129,16,23,26,9,64,8,83,116,97,116,
  117,115,0,74,51,24,37,9,17,2,31,192,32,70,105,114,101,0,31,64,
  78,111,32,70,105,114,101,0,129,37,76,31,6,64,8,80,97,114,107,32,
  83,116,97,116,117,115,0,70,28,92,23,17,33,26,37,135,0,74,26,96,
  27,10,17,2,31,192,65,86,76,0,31,64,78,92,47,86,0,70,28,110,
  23,17,33,26,37,135,0,74,26,114,27,10,17,2,31,192,65,86,76,0,
  31,64,78,92,47,86,0,70,28,130,23,17,33,26,37,135,0,74,26,134,
  27,10,17,2,31,192,65,86,76,0,31,64,78,92,47,86,0,70,79,129,
  23,17,33,26,37,135,0,74,78,133,27,10,17,2,31,192,65,86,76,0,
  31,64,78,92,47,86,0,70,79,110,23,17,33,26,37,135,0,74,77,114,
  27,10,17,2,31,192,65,86,76,0,31,64,78,92,47,86,0,70,79,91,
  23,17,33,26,37,135,0,74,77,95,27,10,17,2,31,192,65,86,76,0,
  31,64,78,92,47,86,0,3,21,56,60,13,133,2,26,131,6,190,45,9,
  2,17,2,31,83,101,116,116,105,110,103,115,0,166,2,131,56,190,45,9,
  2,17,2,31,67,104,97,114,103,101,0,170,1,129,57,133,19,10,192,31,
  80,75,54,0,129,57,114,19,10,192,31,80,75,53,0,129,57,95,19,10,
  192,31,80,75,52,0,129,6,134,19,10,192,31,80,75,51,0,129,6,114,
  19,10,192,31,80,75,50,0,129,6,95,19,10,192,31,80,75,49,0,130,
  2,170,102,19,11,17,1,5,176,29,12,1,2,31,0,129,8,178,23,9,
  64,31,82,101,115,116,49,0,1,39,176,29,12,1,2,31,0,1,73,176,
  29,12,1,2,31,0,129,42,178,23,9,64,31,82,101,115,116,50,0,129,
  76,178,23,9,64,31,82,101,115,116,51,0,129,29,170,47,6,64,8,69,
  108,101,99,116,114,105,99,32,99,97,114,115,32,82,101,115,116,0,129,48,
  70,8,4,64,8,78,70,67,0,129,22,70,11,4,64,8,67,108,111,115,
  101,0,129,35,70,10,4,64,8,79,112,101,110,0,129,72,70,5,4,64,
  8,65,108,108,0,129,61,70,4,4,64,8,73,82,0,69,94,24,8,8,
  1,194,93,37,8,8,1,25,0,130,1,15,102,86,11,17,129,36,3,31,
  11,64,8,80,97,114,107,108,121,0,130,2,103,102,84,11,17,129,9,124,
  34,12,64,8,112,97,114,107,32,52,0,129,9,168,34,12,64,8,112,97,
  114,107,32,54,0,129,9,145,34,12,64,8,112,97,114,107,32,53,0,129,
  9,77,34,12,64,8,112,97,114,107,32,51,0,129,9,55,34,12,64,8,
  112,97,114,107,32,50,0,129,9,34,34,12,64,8,112,97,114,107,32,49,
  0,129,33,108,38,9,64,8,83,101,99,116,105,111,110,32,50,0,129,15,
  18,76,9,64,8,83,101,99,116,105,111,110,32,49,32,40,69,108,101,99,
  116,114,105,99,41,0,70,45,29,50,20,33,26,37,135,0,74,46,36,48,
  8,17,2,31,192,65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,
  32,65,118,97,105,108,97,98,108,101,0,70,45,51,50,20,33,26,37,135,
  0,74,46,58,48,8,17,2,31,192,65,118,97,105,108,97,98,108,101,0,
  31,64,110,111,116,32,65,118,97,105,108,97,98,108,101,0,70,45,73,50,
  20,33,26,37,135,0,74,45,80,51,8,17,2,31,192,65,118,97,105,108,
  97,98,108,101,0,31,64,110,111,116,32,65,118,97,105,108,97,98,108,101,
  0,70,48,119,50,20,33,26,37,135,0,74,48,126,50,8,17,2,31,192,
  65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,32,65,118,97,105,
  108,97,98,108,101,0,70,48,141,50,20,33,26,37,135,0,74,48,148,50,
  8,17,2,31,192,65,118,97,105,108,97,98,108,101,0,31,64,110,111,116,
  32,65,118,97,105,108,97,98,108,101,0,70,48,163,50,20,33,26,37,135,
  0,74,49,170,49,8,17,2,31,192,65,118,97,105,108,97,98,108,101,0,
  31,64,110,111,116,32,65,118,97,105,108,97,98,108,101,0,131,5,189,45,
  9,2,17,2,31,83,101,116,116,105,110,103,115,0,166,2,131,55,189,45,
  9,2,17,2,31,67,104,97,114,103,101,0,170,1,65,0,130,1,20,104,
  55,11,17,1,36,22,33,9,1,2,31,0,129,29,14,51,6,64,8,83,
  101,99,116,105,111,110,32,50,32,40,69,108,101,99,116,114,105,99,41,0,
  129,4,25,31,12,64,8,112,97,114,107,49,0,70,70,22,33,19,33,26,
  135,1,0,74,72,29,29,6,17,2,31,192,99,104,97,114,103,105,110,103,
  0,31,64,110,111,116,32,99,104,97,114,103,101,0,129,35,3,31,11,64,
  8,80,97,114,107,108,121,0,67,4,43,36,9,77,2,26,2,67,4,53,
  36,9,77,2,26,2,129,41,44,5,7,64,8,86,0,129,41,54,6,8,
  64,8,65,0,129,41,64,7,7,64,8,87,0,67,4,63,36,9,77,2,
  26,2,129,55,58,16,7,64,8,112,114,105,99,101,0,67,72,58,24,8,
  77,2,26,2,67,72,46,24,8,77,2,26,2,129,55,47,16,7,64,8,
  84,105,109,101,0,129,97,59,8,6,64,8,74,68,0,129,97,46,8,8,
  64,8,109,0,131,7,190,45,9,2,17,2,31,83,101,116,116,105,110,103,
  115,0,166,2,131,57,190,45,9,2,17,2,31,67,104,97,114,103,101,0,
  170,1,1,36,32,33,9,1,2,31,0,130,1,77,104,55,11,17,1,36,
  79,33,9,1,2,31,0,129,3,83,31,12,64,8,112,97,114,107,50,0,
  70,70,79,33,19,33,26,121,1,0,74,72,86,29,6,17,2,31,192,99,
  104,97,114,103,105,110,103,0,31,64,110,111,116,32,99,104,97,114,103,101,
  0,67,4,100,36,9,77,2,26,2,67,4,110,36,9,77,2,26,2,129,
  41,101,5,7,64,8,86,0,129,41,111,6,8,64,8,65,0,129,41,121,
  7,7,64,8,87,0,67,4,120,36,9,77,2,26,2,129,55,115,16,7,
  64,8,112,114,105,99,101,0,67,72,115,24,8,77,2,26,2,67,72,103,
  24,8,77,2,26,2,129,55,104,16,7,64,8,84,105,109,101,0,129,97,
  116,8,6,64,8,74,68,0,129,97,103,8,8,64,8,109,0,1,36,89,
  33,9,1,2,31,0,130,1,134,104,55,11,17,1,36,136,33,9,1,2,
  31,0,129,3,140,31,12,64,8,112,97,114,107,51,0,70,70,136,33,19,
  33,26,135,1,0,74,72,143,29,6,17,2,31,192,99,104,97,114,103,105,
  110,103,0,31,64,110,111,116,32,99,104,97,114,103,101,0,67,4,157,36,
  9,77,2,26,2,67,4,167,36,9,77,2,26,2,129,41,158,5,7,64,
  8,86,0,129,41,168,6,8,64,8,65,0,129,41,178,7,7,64,8,87,
  0,67,4,177,36,9,77,2,26,2,129,55,172,16,7,64,8,112,114,105,
  99,101,0,67,72,172,24,8,77,2,26,2,67,72,160,24,8,77,2,26,
  2,129,55,161,16,7,64,8,84,105,109,101,0,129,96,173,8,6,64,8,
  74,68,0,129,96,160,8,8,64,8,109,0,1,36,146,33,9,1,2,31,
  0,129,7,150,23,6,64,8,87,105,114,101,108,101,115,115,0,129,46,23,
  16,7,192,8,83,116,97,114,116,0,129,46,33,15,7,64,8,83,116,111,
  112,0,129,46,81,16,7,192,8,83,116,97,114,116,0,129,46,147,15,7,
  64,8,83,116,111,112,0,129,46,90,15,7,64,8,83,116,111,112,0,129,
  46,137,16,7,192,8,83,116,97,114,116,0 };
  
struct {

  uint8_t pro;
  uint8_t setting;
  uint8_t admain;
  uint8_t stander;
  uint8_t charge;
  uint8_t button_book1;
  uint8_t button_book2;
  uint8_t button_book3;
  uint8_t button_book4;
  uint8_t button_book5;
  uint8_t button_book6;
  char edit_admn_user[11];
  uint8_t button_enter_admain;
  char edit_admn_pass[11];
  char edit_pro_user[11];
  uint8_t button_enter_pro;
  char edit_pro_pass[11];
  uint8_t button_booka1;
  uint8_t button_booka2;
  uint8_t button_booka3;
  uint8_t button_booka4;
  uint8_t button_booka5;
  uint8_t button_booka6;
  uint8_t switch_light_street;
  uint8_t button_stop_alarm;
  uint8_t selectorSwitch_gate;
  uint8_t button_rest_4;
  uint8_t button_rest_5;
  uint8_t button_rest_6;
  uint8_t button_start4;
  uint8_t button_stop4;
  uint8_t button_start5;
  uint8_t button_stop5;
  uint8_t button_start6;
  uint8_t button_stop6;

  uint8_t strings_book1;
  uint8_t strings_book2;
  uint8_t strings_book3;
  uint8_t strings_book4;
  uint8_t strings_book5;
  uint8_t strings_book6;
  uint8_t led_p1;
  uint8_t strings_p1;
  uint8_t led_p2;
  uint8_t strings_p2;
  uint8_t led_p3;
  uint8_t strings_p3;
  uint8_t led_p4;
  uint8_t strings_p4;
  uint8_t led_p5;
  uint8_t strings_p5;
  uint8_t led_p6;
  uint8_t strings_p6;
  uint8_t led_fier;
  uint8_t strings_2fire;
  uint8_t led_pk1a;
  uint8_t strings_a1;
  uint8_t led_pk2a;
  uint8_t strings_a2;
  uint8_t led_pk3a;
  uint8_t strings_a3;
  uint8_t led_pk6a;
  uint8_t strings_a6;
  uint8_t led_pk5a;
  uint8_t strings_a5;
  uint8_t led_pk4a;
  uint8_t strings_a4;
  int16_t alarm;
  uint8_t led_s1;
  uint8_t strings_s1;
  uint8_t led_s2;
  uint8_t strings_s2;
  uint8_t led_s3;
  uint8_t strings_s3;
  uint8_t led_s4;
  uint8_t strings_s4;
  uint8_t led_s5;
  uint8_t strings_s5;
  uint8_t led_s6;
  uint8_t strings_s6;
  uint8_t led_cha4;
  uint8_t strings_cha4;
  float value_v4;
  float value_a4;
  float value_w4;
  float value_j4;
  float value_t4;
  uint8_t led_cha5;
  uint8_t strings_cha5;
  float value_v5;
  float value_a5;
  float value_w5;
  float value_j5;
  float value_t5;
  uint8_t led_cha6;
  uint8_t strings_cha6;
  float value_v6;
  float value_a6;
  float value_w6;
  float value_j6;
  float value_t6;

  RemoteXYType_Notification Warning;

} RemoteXY;   
#pragma pack(pop)
 
// -----------------------------------------------------------------------------
// =========================== END RemoteXY include ============================
// -----------------------------------------------------------------------------






#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_INA219.h>
#include <Arduino.h>
#include <SPI.h>

const int BUZZER_PIN = 16;

// -----------------------------------------------------------------------------

int fire = 0;
int fireWarnSent = 0; 


// ================================ park_stats =================================
int park1 = 0;
int park2 = 0;
int park3 = 0;
int park4 = 0;
int park5 = 0;
int park6 = 0;

// ================================ park_stats =================================
int book1 = 0;
int book2 = 0;
int book3 = 0;
int book4 = 0;
int book5 = 0;
int book6 = 0;

// ================================ park_stats =================================
int cancel1 = 0;
int cancel2 = 0;
int cancel3 = 0;
int cancel4 = 0;
int cancel5 = 0;
int cancel6 = 0;

// =================================== servo ===================================
Servo myServo;
const int SERVO_PIN = 23;


// -----------------------------------------------------------------------------



// ================================ IR + flame =================================

// =========================== ESP32 <-> CD74HC4067 ============================
const int MUX_SIG = 35;
const int MUX_S3  = 13;
const int MUX_S2  = 4;
const int MUX_S1  = 2;
const int MUX_S0  = 15;

const int MUX_EN = -1;

// ============================= Channel Selection =============================
void muxSelect(uint8_t ch) {
  digitalWrite(MUX_S0, (ch >> 0) & 1);
  digitalWrite(MUX_S1, (ch >> 1) & 1);
  digitalWrite(MUX_S2, (ch >> 2) & 1);
  digitalWrite(MUX_S3, (ch >> 3) & 1);
  delayMicroseconds(50);
}

uint8_t readMuxDigital(uint8_t ch, uint8_t samples = 5) {
  muxSelect(ch);

  int ones = 0;
  for (uint8_t i = 0; i < samples; i++) {
    ones += digitalRead(MUX_SIG);
    delayMicroseconds(200);
  }
  return (ones > (samples / 2)) ? HIGH : LOW;
}

// ==================== Storage Variables (per your table) =====================
uint8_t ir_gate_out;
uint8_t ir_gate_in;

uint8_t ir_sec1[3];

uint8_t ir_sec2[3];

uint8_t flame[3];
// -----------------------------------------------------------------------------

// =================================== TIME ====================================
// ================= Electricity Tariff (adjust for your plan) =================
float tariffJOD_per_kWh = 0.10f;
float chargerEfficiency  = 0.90f;

// ================================== Power 4 ==================================
bool     p4Run = false;
uint32_t p4StartMs = 0, p4AccMs = 0, p4LastEMs = 0;
float    p4Wh = 0.0f;
uint8_t  prevStart4=0, prevStop4=0, prevReset4=0;

// ================================== Power 5 ==================================
bool     p5Run = false;
uint32_t p5StartMs = 0, p5AccMs = 0, p5LastEMs = 0;
float    p5Wh = 0.0f;
uint8_t  prevStart5=0, prevStop5=0, prevReset5=0;

// ================================== Power 6 ==================================
bool     p6Run = false;
uint32_t p6StartMs = 0, p6AccMs = 0, p6LastEMs = 0;
float    p6Wh = 0.0f;
uint8_t  prevStart6=0, prevStop6=0, prevReset6=0;

// -----------------------------------------------------------------------------



// =================================== relay ===================================
const int RELAY1 = 17;
const int RELAY2 = 5;
const int RELAY3 = 18;
const int RELAY4 = 19;

const bool RELAY_ACTIVE_LOW = true;

void relayOn(int pin)  { digitalWrite(pin, RELAY_ACTIVE_LOW ? LOW  : HIGH); }
void relayOff(int pin) { digitalWrite(pin, RELAY_ACTIVE_LOW ? HIGH : LOW ); }
// -----------------------------------------------------------------------------


// ================================ LED & power ================================
// ================================= ESP32 I2C =================================
#define SDA_PIN 21
#define SCL_PIN 22

// ===================== I2C Addresses (change if needed) ======================
#define TCA_ADDR 0x70
#define INA_ADDR 0x40
#define PCF_ADDR 0x20

// ============================ INA219 via TCA9548 =============================
const uint8_t NUM_SENSORS = 3;
const uint8_t INA_CH[NUM_SENSORS] = {2, 3, 4};

Adafruit_INA219 ina[NUM_SENSORS] = {
  Adafruit_INA219(INA_ADDR),
  Adafruit_INA219(INA_ADDR),
  Adafruit_INA219(INA_ADDR)
};

// ======================= Per-Sensor Reading Variables ========================
float V[NUM_SENSORS];
float A[NUM_SENSORS];
float W[NUM_SENSORS];

float V1, A1, W1;
float V2, A2, W2;
float V3, AA3, W3;

// =============================== PCF8574 LEDs ================================
const uint8_t redBit[NUM_SENSORS]   = {0, 2, 4};
const uint8_t greenBit[NUM_SENSORS] = {1, 3, 6};

const bool LED_ACTIVE_LOW = false;

// ============================== Color Constants ==============================
enum {
  COLOR_OFF   = 0,
  COLOR_RED   = 1,
  COLOR_GREEN = 2
};

uint8_t sensorColor[NUM_SENSORS] = {COLOR_OFF, COLOR_OFF, COLOR_OFF};

// ================================ TCA select =================================
void tcaSelect(uint8_t ch) {
  Wire.beginTransmission(TCA_ADDR);
  Wire.write(1 << ch);
  Wire.endTransmission();
  delayMicroseconds(200);
}

// ================================ PCF helpers ================================
void pcfWrite(uint8_t value) {
  Wire.beginTransmission(PCF_ADDR);
  Wire.write(value);
  Wire.endTransmission();
}

uint8_t pcfAllOffByte() {
  return LED_ACTIVE_LOW ? 0xFF : 0x00;
}

void setPcfPinInState(uint8_t &state, uint8_t bit, bool on) {
  if (LED_ACTIVE_LOW) {
    if (on)  state &= ~(1 << bit);
    else     state |=  (1 << bit);
  } else {
    if (on)  state |=  (1 << bit);
    else     state &= ~(1 << bit);
  }
}

void applySensorColors() {
  uint8_t newState = pcfAllOffByte();

  for (uint8_t i = 0; i < NUM_SENSORS; i++) {
    if (sensorColor[i] == COLOR_RED) {
      setPcfPinInState(newState, redBit[i], true);
    } else if (sensorColor[i] == COLOR_GREEN) {
      setPcfPinInState(newState, greenBit[i], true);
    }
  }

  setPcfPinInState(newState, 7, false);

  pcfWrite(newState);
}

void setSensorColor(uint8_t sensorIndex, uint8_t color) {
  if (sensorIndex >= NUM_SENSORS) return;

  const uint8_t CMD_RED_OFF_ONLY   = 3;
  const uint8_t CMD_GREEN_OFF_ONLY = 4;

  bool redOffOnly   = (color == CMD_RED_OFF_ONLY);
  bool greenOffOnly = (color == CMD_GREEN_OFF_ONLY);

  if (!redOffOnly && !greenOffOnly) {
    if (color != COLOR_OFF && color != COLOR_RED && color != COLOR_GREEN) {
      color = COLOR_OFF;
    }
    sensorColor[sensorIndex] = color;
    applySensorColors();
    return;
  }

  uint8_t newState = pcfAllOffByte();

  for (uint8_t i = 0; i < NUM_SENSORS; i++) {
    uint8_t c = sensorColor[i];

    if (i == sensorIndex) {
      if (redOffOnly) {
        if (c == COLOR_GREEN) setPcfPinInState(newState, greenBit[i], true);
      } else if (greenOffOnly) {
        if (c == COLOR_RED) setPcfPinInState(newState, redBit[i], true);
      }
    } else {
      if (c == COLOR_RED)       setPcfPinInState(newState, redBit[i], true);
      else if (c == COLOR_GREEN) setPcfPinInState(newState, greenBit[i], true);
    }
  }

  setPcfPinInState(newState, 6, false);
  setPcfPinInState(newState, 7, false);

  pcfWrite(newState);

  if (redOffOnly && sensorColor[sensorIndex] == COLOR_RED) {
    sensorColor[sensorIndex] = COLOR_OFF;
  }
  if (greenOffOnly && sensorColor[sensorIndex] == COLOR_GREEN) {
    sensorColor[sensorIndex] = COLOR_OFF;
  }
}

inline void sensorOff(uint8_t i)   { setSensorColor(i, COLOR_OFF); }
inline void sensorRed(uint8_t i)   { setSensorColor(i, COLOR_RED); }
inline void sensorGreen(uint8_t i) { setSensorColor(i, COLOR_GREEN); }

void sensorsAllOff() {
  for (uint8_t i = 0; i < NUM_SENSORS; i++) sensorColor[i] = COLOR_OFF;
  applySensorColors();
}

void setOnlyOneSensor(uint8_t idx, uint8_t color) {
  for (uint8_t i = 0; i < NUM_SENSORS; i++) sensorColor[i] = COLOR_OFF;
  if (idx < NUM_SENSORS) sensorColor[idx] = color;
  applySensorColors();
}

// ====================== Read Sensors & Store Variables =======================
void readAllINA219() {
  for (uint8_t i = 0; i < NUM_SENSORS; i++) {
    tcaSelect(INA_CH[i]);

    float busV = ina[i].getBusVoltage_V();
    float current_mA = ina[i].getCurrent_mA();
    float power_mW = ina[i].getPower_mW();

    V[i] = busV;
    A[i] = current_mA / 1000.0;
    W[i] = power_mW  / 1000.0;
  }

  V1 = V[0]; A1 = A[0]; W1 = W[0];
  V2 = V[1]; A2 = A[1]; W2 = W[1];
  V3 = V[2]; AA3 = A[2]; W3 = W[2];
}


// -----------------------------------------------------------------------------

// ================================ LED & power ================================


// -----------------------------------------------------------------------------


// ==================================== NFC ====================================
#include <MFRC522.h>

// =============================== RC522 Wiring ================================
static const uint8_t RFID_PIN_SS   = 32;
static const uint8_t RFID_PIN_RST  = 27;
static const uint8_t RFID_PIN_SCK  = 33;
static const uint8_t RFID_PIN_MISO = 26;
static const uint8_t RFID_PIN_MOSI = 25;

MFRC522 RFID_reader(RFID_PIN_SS, RFID_PIN_RST);

// ========================= Allowed List (Whitelist) ==========================
struct RFID_UID4 { byte b[4]; };

const RFID_UID4 RFID_allowedList[] = {
  {{0x01, 0x2C, 0x5A, 0x06}},
  {{0x03, 0x53, 0xF1, 0x05}},
};

const int RFID_ALLOWED_COUNT = sizeof(RFID_allowedList) / sizeof(RFID_allowedList[0]);

static bool RFID_isAllowed4(const byte *uid) {
  for (int i = 0; i < RFID_ALLOWED_COUNT; i++) {
    bool same = true;
    for (int j = 0; j < 4; j++) {
      if (uid[j] != RFID_allowedList[i].b[j]) { same = false; break; }
    }
    if (same) return true;
  }
  return false;
}

static unsigned long RFID_lastReadMs = 0;
static const unsigned long RFID_COOLDOWN_MS = 500;




// -----------------------------------------------------------------------------

// =================================== Setup ===================================
// -----------------------------------------------------------------------------


void setup() 
{
  Serial.begin(115200);
  RemoteXY_Init ();

  RemoteXY.pro = 0;
  RemoteXY.setting = 0;
  RemoteXY.admain = 0;
  RemoteXY.stander = 1;
  
RemoteXY.selectorSwitch_gate = 4;

// =================================== servo ===================================
myServo.setPeriodHertz(50);
myServo.attach(SERVO_PIN, 500, 2400);

// =================================== Relay ===================================
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);
  pinMode(RELAY3, OUTPUT);
  pinMode(RELAY4, OUTPUT);

  relayOff(RELAY1);
  relayOff(RELAY2);
  relayOff(RELAY3);
  relayOff(RELAY4);
// -----------------------------------------------------------------------------

// ================================ LED & power ================================
Wire.begin(SDA_PIN, SCL_PIN);

pcfWrite(0x00);

for (uint8_t i = 0; i < NUM_SENSORS; i++) {
  tcaSelect(INA_CH[i]);
  if (!ina[i].begin()) {
    Serial.print("INA219 NOT FOUND on TCA channel ");
    Serial.println(INA_CH[i]);
  } else {
    Serial.print("INA219 OK on channel ");
    Serial.println(INA_CH[i]);
  }
}

for (uint8_t i = 0; i < NUM_SENSORS; i++) sensorColor[i] = 0;
applySensorColors();

// -----------------------------------------------------------------------------


// ==================================== NFC ====================================
 SPI.begin(RFID_PIN_SCK, RFID_PIN_MISO, RFID_PIN_MOSI, RFID_PIN_SS);
  RFID_reader.PCD_Init();

// -----------------------------------------------------------------------------

// ================================ IR + flame =================================


  pinMode(MUX_S0, OUTPUT);
  pinMode(MUX_S1, OUTPUT);
  pinMode(MUX_S2, OUTPUT);
  pinMode(MUX_S3, OUTPUT);

  pinMode(MUX_SIG, INPUT);

  if (MUX_EN != -1) {
    pinMode(MUX_EN, OUTPUT);
    digitalWrite(MUX_EN, LOW);
  }

  Serial.println("Digital MUX Read Start...");
// -----------------------------------------------------------------------------

// ================================== BUZZER ===================================
  pinMode(BUZZER_PIN, OUTPUT);

// =================================== book ====================================
RemoteXY.strings_book1 = 1;
RemoteXY.strings_book2 = 1;
RemoteXY.strings_book3 = 1;
RemoteXY.strings_book4 = 1;
RemoteXY.strings_book5 = 1;
RemoteXY.strings_book6 = 1;

// =================================== power ===================================
RemoteXY.strings_cha4 = 2;
RemoteXY.led_cha4 = 2;
RemoteXY.strings_cha5 = 2;
RemoteXY.led_cha5 = 2;
RemoteXY.strings_cha6 = 2;
RemoteXY.led_cha6 = 2;


}


// =================================== Loop ====================================
// -----------------------------------------------------------------------------
int cont = 1;
void loop() 
{ 
  RemoteXY_Handler();


// ================================ IR + flame =================================
// =============================== Read & Store ================================
  ir_gate_out = readMuxDigital(0);
  ir_gate_in  = readMuxDigital(1);

  ir_sec1[0] = readMuxDigital(2);
  ir_sec1[1] = readMuxDigital(3);
  ir_sec1[2] = readMuxDigital(4);

  ir_sec2[0] = readMuxDigital(5);
  ir_sec2[1] = readMuxDigital(6);
  ir_sec2[2] = readMuxDigital(7);

  flame[0] = readMuxDigital(8);
  flame[1] = readMuxDigital(9);
  flame[2] = readMuxDigital(10);

// -----------------------------------------------------------------------------

// =================================== Relay ===================================

// =========================== Relay4)-------------- ===========================


// -----------------------------------------------------------------------------


// =============================== street light ================================
if (RemoteXY.switch_light_street == 1) {
  relayOn(RELAY4);
} else {
  relayOff(RELAY4);
}
// -----------------------------------------------------------------------------


// ==================================== NFC ====================================

if (RemoteXY.selectorSwitch_gate == 2 || RemoteXY.selectorSwitch_gate == 4) {

  if (millis() - RFID_lastReadMs >= RFID_COOLDOWN_MS) {

    if (RFID_reader.PICC_IsNewCardPresent() && RFID_reader.PICC_ReadCardSerial()) {

      RFID_lastReadMs = millis();

      bool RFID_allowed = false;

      if (RFID_reader.uid.size == 4) {
        RFID_allowed = RFID_isAllowed4(RFID_reader.uid.uidByte);
      }
        myServo.write(0);
        

      RFID_reader.PICC_HaltA();
      RFID_reader.PCD_StopCrypto1();
    }
  }
}




// -----------------------------------------------------------------------------

// ================================= IR Gates ==================================
if (RemoteXY.selectorSwitch_gate == 3 || RemoteXY.selectorSwitch_gate == 4) {


  if ( ir_gate_out == 0) {
    myServo.write(90);
      Serial.print("ir_gate_out ");
      Serial.println(ir_gate_out);

  }

  if ( ir_gate_in == 0) {
    delay(500);
    myServo.write(0);
    Serial.print("ir_gate_in ");
    Serial.println(ir_gate_in);
  }


}

  Serial.print("ir_gate_out = ");
  Serial.println(ir_gate_out);
  
    Serial.print("ir_gate_in ");
    Serial.println(ir_gate_in);

// ================================ open Gates =================================
if (RemoteXY.selectorSwitch_gate == 1) {
    myServo.write(0);

}

// ================================ close Gates ================================
if (RemoteXY.selectorSwitch_gate == 0) {
    myServo.write(90);

}

// ================================ LED & power ================================
readAllINA219();

// =================================== power ===================================
  V1 = V[0]; A1 = A[0]; W1 = W[0];
  V2 = V[1]; A2 = A[1]; W2 = W[1];
  V3 = V[2]; AA3 = A[2]; W3 = W[2];




// =================================== TIME ====================================

uint32_t now = millis();

// ================================== power 4 ==================================
if (RemoteXY.button_start4 == 1 && prevStart4 == 0) {
  RemoteXY.strings_cha4 = 1;
  RemoteXY.led_cha4 = 1;
  relayOn(RELAY1);
  if (!p4Run) {
    p4Run = true;
    p4StartMs = now;
    p4LastEMs = now;
  }
}
prevStart4 = RemoteXY.button_start4;

if (RemoteXY.button_stop4 == 1 && prevStop4 == 0) {
  RemoteXY.strings_cha4 = 2;
  RemoteXY.led_cha4 = 2;

  relayOff(RELAY1);
  if (p4Run) {
    float dtH = (now - p4LastEMs) / 3600000.0f;
    p4Wh += (W1 * dtH);

    p4AccMs += (now - p4StartMs);
    p4Run = false;
    p4LastEMs = 0;
  }
}
prevStop4 = RemoteXY.button_stop4;


if (RemoteXY.button_rest_4 == 1 && prevReset4 == 0) {
  p4AccMs = 0;
  p4Wh = 0.0f;
  RemoteXY.strings_cha4 = 2;
  RemoteXY.led_cha4 = 2;
  relayOff(RELAY1);
  if (p4Run) { p4StartMs = now; p4LastEMs = now; }
}
prevReset4 = RemoteXY.button_rest_4;

if (p4Run) {
  float dtH = (now - p4LastEMs) / 3600000.0f;
  p4Wh += (W1 * dtH);
  p4LastEMs = now;
}

uint32_t total4ms = p4AccMs + (p4Run ? (now - p4StartMs) : 0);
float min4 = total4ms / 60000.0f;

float kWh4 = (p4Wh / 1000.0f) / chargerEfficiency;
float jod4 = kWh4 * tariffJOD_per_kWh;

RemoteXY.value_v4 = V1;
RemoteXY.value_a4 = A1;
RemoteXY.value_w4 = W1;
RemoteXY.value_t4 = min4;
RemoteXY.value_j4 = jod4;



// ================================== power 5 ==================================
if (RemoteXY.button_start6 == 1 && prevStart5 == 0) {
  RemoteXY.strings_cha6 = 1;
  RemoteXY.led_cha6 = 1;
  relayOn(RELAY2);
  if (!p5Run) {
    p5Run = true;
    p5StartMs = now;
    p5LastEMs = now;
  }
}
prevStart5 = RemoteXY.button_start6;

if (RemoteXY.button_stop6 == 1 && prevStop5 == 0) {
  RemoteXY.strings_cha6 = 2;
  RemoteXY.led_cha6 = 2;
  relayOff(RELAY2);
  if (p5Run) {
    float dtH = (now - p5LastEMs) / 3600000.0f;
    p5Wh += (W2 * dtH);

    p5AccMs += (now - p5StartMs);
    p5Run = false;
    p5LastEMs = 0;
  }
}
prevStop5 = RemoteXY.button_stop6;

if (RemoteXY.button_rest_6 == 1 && prevReset5 == 0) {
  relayOff(RELAY2);
  RemoteXY.strings_cha6 = 2;
  RemoteXY.led_cha6 = 2;
  p5AccMs = 0;
  p5Wh = 0.0f;
  if (p5Run) { p5StartMs = now; p5LastEMs = now; }
}
prevReset5 = RemoteXY.button_rest_6;

if (p5Run) {
  float dtH = (now - p5LastEMs) / 3600000.0f;
  p5Wh += (W2 * dtH);
  p5LastEMs = now;
}

uint32_t total5ms = p5AccMs + (p5Run ? (now - p5StartMs) : 0);
float min5 = total5ms / 60000.0f;

float kWh5 = (p5Wh / 1000.0f) / chargerEfficiency;
float jod5 = kWh5 * tariffJOD_per_kWh;

RemoteXY.value_v5 = V2;
RemoteXY.value_a5 = A2;
RemoteXY.value_w5 = W2;
RemoteXY.value_t5 = min5;
RemoteXY.value_j5 = jod5;



// ================================== power 6 ==================================
if (RemoteXY.button_start5 == 1 && prevStart6 == 0) {
  RemoteXY.strings_cha5 = 1;
  RemoteXY.led_cha5 = 1;
  relayOn(RELAY3);
  if (!p6Run) {
    p6Run = true;
    p6StartMs = now;
    p6LastEMs = now;
  }
}
prevStart6 = RemoteXY.button_start6;

if (RemoteXY.button_stop5 == 1 && prevStop6 == 0) {
  RemoteXY.strings_cha5 = 2;
  RemoteXY.led_cha5 = 2;
  relayOff(RELAY3);
  if (p6Run) {
    float dtH = (now - p6LastEMs) / 3600000.0f;
    p6Wh += (W3 * dtH);

    p6AccMs += (now - p6StartMs);
    p6Run = false;
    p6LastEMs = 0;
  }
}
prevStop6 = RemoteXY.button_stop5;

if (RemoteXY.button_rest_5 == 1 && prevReset6 == 0) {
  relayOff(RELAY3);
  RemoteXY.strings_cha5 = 2;
  RemoteXY.led_cha5 = 2;
  p6AccMs = 0;
  p6Wh = 0.0f;
  if (p6Run) { p6StartMs = now; p6LastEMs = now; }
}
prevReset6 = RemoteXY.button_rest_5;

if (p6Run) {
  float dtH = (now - p6LastEMs) / 3600000.0f;
  p6Wh += (W3 * dtH);
  p6LastEMs = now;
}

uint32_t total6ms = p6AccMs + (p6Run ? (now - p6StartMs) : 0);
float min6 = total6ms / 60000.0f;

float kWh6 = (p6Wh / 1000.0f) / chargerEfficiency;
float jod6 = kWh6 * tariffJOD_per_kWh;

RemoteXY.value_v6 = V3;
RemoteXY.value_a6 = AA3;
RemoteXY.value_w6 = W3;
RemoteXY.value_t6 = min6;
RemoteXY.value_j6 = jod6;


// -----------------------------------------------------------------------------

// ==================================== LED ====================================
// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------







// -----------------------------------------------------------------------------



// =================================== gates ===================================



  if (MUX_EN != -1) {
    pinMode(MUX_EN, OUTPUT);
    digitalWrite(MUX_EN, LOW);
  }

// -----------------------------------------------------------------------------




// =================================== book1 ===================================
if ( (RemoteXY.button_booka1== 1 ||RemoteXY.button_book1 == 1) && ir_sec2[2] == HIGH)
{
   
  if (cancel1 == 1)
  {
    book1 = 0;
    cancel1 = 0;
    RemoteXY.strings_book1 = 1;

    RemoteXY.strings_p1 = 1;
    RemoteXY.strings_s1 = 1;
    RemoteXY.strings_a1 = 1;

    RemoteXY.button_book1 = 0;
    RemoteXY.button_booka1 = 0;

    RemoteXY.led_s1 = 2;
    RemoteXY.led_pk1a = 2;
    RemoteXY.led_p1 = 2;
    
     setSensorColor(2, COLOR_RED); 
    
  }

  else if(cancel1 == 0)
  {

    book1 = 1;
    cancel1 = 1;
    RemoteXY.strings_book1 = 2;

    RemoteXY.button_book1 = 0;
    RemoteXY.button_booka1 = 0;

    RemoteXY.strings_p1 = 2;
    RemoteXY.strings_s1 = 2;
    RemoteXY.strings_a1 = 2;

    RemoteXY.led_s1 = 1;
    RemoteXY.led_pk1a = 1;
    RemoteXY.led_p1 = 1;

    setSensorColor(2, COLOR_GREEN);   

    
  }
 
}
else
{

  
}

// =================================== book2 ===================================
if ( (RemoteXY.button_booka2== 1 ||RemoteXY.button_book2 == 1) && ir_sec2[0] == HIGH)
{
  if (cancel2 ==1)
  {
    RemoteXY.strings_book2 = 1;

    book2 = 0;
    cancel2 =0;
    RemoteXY.strings_p2 = 1;
    RemoteXY.strings_s2 = 1;
    RemoteXY.strings_a2 = 1;


    RemoteXY.button_book2 = 0;
    RemoteXY.button_booka2 = 0;

    RemoteXY.led_s2 = 2;
    RemoteXY.led_pk2a = 2;
    RemoteXY.led_p2 = 2;
    
    setSensorColor(1, COLOR_GREEN);  

  }
  else if(cancel2 == 0)
  {

    book2 = 1;
    cancel2 =1;
    RemoteXY.strings_book2 = 2;


    RemoteXY.button_book2 = 0;
    RemoteXY.button_booka2 =0;

    RemoteXY.strings_p2 = 2;
    RemoteXY.strings_s2 = 2;
    RemoteXY.strings_a2 = 2;


    RemoteXY.led_s2 = 1;
    RemoteXY.led_pk2a = 1;
    RemoteXY.led_p2 = 1;
    
 setSensorColor(1, COLOR_RED);  

  }
  
}
else
{


}

// =================================== book3 ===================================
if ( (RemoteXY.button_booka3== 1 ||RemoteXY.button_book3 == 1) && ir_sec2[1] == HIGH)
{
  if (cancel3 ==1)
  {
    RemoteXY.strings_book3 = 1;


    book3 = 0;
    cancel3 =0;
    RemoteXY.strings_p3 = 1;
    RemoteXY.strings_s3 = 1;
    RemoteXY.strings_a3 = 1;

    RemoteXY.button_book3 = 0;
    RemoteXY.button_booka3 = 0;

    RemoteXY.led_s3 = 2;
    RemoteXY.led_pk3a = 2;
    RemoteXY.led_p3 = 2;
    setSensorColor(0, COLOR_RED); 
  }
  else if(cancel3 == 0)
  {
    book3 = 1;
    cancel3 =1;
    RemoteXY.strings_book3 = 2;

    RemoteXY.button_book3 = 0;
    RemoteXY.button_booka3 = 0;

    RemoteXY.strings_p3 = 2;
    RemoteXY.strings_s3 = 2;
    RemoteXY.strings_a3 = 2;

    RemoteXY.led_s3 = 1;
    RemoteXY.led_pk3a = 1;
    RemoteXY.led_p3 = 1;

  setSensorColor(0, COLOR_GREEN);

  }
  
}
else
{


}

// =================================== book4 ===================================
if ( (RemoteXY.button_booka4== 1 ||RemoteXY.button_book4 == 1) && ir_sec1[0] == HIGH)
{
  if (cancel4 == 1)
  {
    RemoteXY.strings_book4 = 1;


    book4 = 0;
    cancel4 =0;
    RemoteXY.strings_p4 = 1;
    RemoteXY.strings_s4 = 1;
    RemoteXY.strings_a4 = 1;

    RemoteXY.button_book4 = 0;
    RemoteXY.button_booka4 = 0;

    RemoteXY.led_s4 = 2;
    RemoteXY.led_pk4a = 2;
    RemoteXY.led_p4 = 2;


  }
  else if(cancel4 == 0)
  {
  cancel4 =1;
  book4 = 1;
    RemoteXY.strings_book4 = 2;

    RemoteXY.button_book4 = 0;
    RemoteXY.button_booka4 = 0;

    RemoteXY.strings_p4 = 2;
    RemoteXY.strings_s4 = 2;
    RemoteXY.strings_a4 = 2;
    
    RemoteXY.led_s4 = 1;
    RemoteXY.led_pk4a = 1;
    RemoteXY.led_p4 = 1;



  }
  
}
else
{

}


// =================================== book5 ===================================
if ( (RemoteXY.button_booka5== 1 ||RemoteXY.button_book5 == 1) && ir_sec1[1] == HIGH)
{
  if (cancel5 == 1)
  {
    RemoteXY.strings_book5 = 1;


    book5 = 0;
    cancel5 =0;
    RemoteXY.strings_p5 = 1;
    RemoteXY.strings_s5 = 1;
    RemoteXY.strings_a5 = 1;

    RemoteXY.button_book5 = 0;
    RemoteXY.button_booka5 = 0;

    RemoteXY.led_s5 = 2;
    RemoteXY.led_pk5a = 2;
    RemoteXY.led_p5 = 2;


    }
  else if(cancel5 == 0)
  {
    book5 = 1;
    cancel5 = 1;
    RemoteXY.strings_book5 = 2;
    RemoteXY.strings_a5 = 2;

    RemoteXY.button_book5 = 0;
    RemoteXY.button_booka5 = 0;

    RemoteXY.strings_p5 = 2;
    RemoteXY.strings_s5 = 2;
    RemoteXY.strings_a5 = 2;

    RemoteXY.led_s5 = 1;
    RemoteXY.led_pk5a = 1;
    RemoteXY.led_p5 = 1;


  }
  
}
else
{

}


// =================================== book6 ===================================
if ( (RemoteXY.button_booka6== 1 ||RemoteXY.button_book6 == 1) && ir_sec1[2] == HIGH)
{
  if (cancel6 == 1)
  {
    RemoteXY.strings_book6 = 1;

    book6 = 0;
    cancel6 = 0;
    RemoteXY.strings_p6 = 1;
    RemoteXY.strings_s6 = 1;
    RemoteXY.strings_a6 = 1;

    RemoteXY.button_book6 = 0;
    RemoteXY.button_booka6 = 0;

    RemoteXY.led_s6 = 2;
    RemoteXY.led_pk6a = 2;
    RemoteXY.led_p6 = 2;


  }
  else if(cancel6 == 0)
  {
    book6 = 1;
    cancel6 = 1;  
    RemoteXY.strings_book6 = 2;
    RemoteXY.strings_a6 = 2;

    RemoteXY.button_book6 = 0;
    RemoteXY.button_booka6 = 0;

    RemoteXY.strings_p6 = 2;
    RemoteXY.strings_s6 = 2;
    RemoteXY.strings_a6 = 2;

    RemoteXY.led_s6 = 1;
    RemoteXY.led_pk6a = 1;
    RemoteXY.led_p6 = 1;
    

  }
  
}
else
{

}



// -----------------------------------------------------------------------------
// ================================== park 1 ===================================
  if (ir_sec2[2] == LOW || book1 == 1 )
   {
    park1 = 1;
    RemoteXY.led_s1 = 1;
    RemoteXY.led_pk1a = 1;
    RemoteXY.led_p1 = 1;

    RemoteXY.strings_p1 = 2;
    RemoteXY.strings_s1 = 2; 
    RemoteXY.strings_a1 = 2;


setSensorColor(2, COLOR_GREEN);  


  }
  else if(ir_sec2[2] == HIGH || book1 == 0)
  {
    park1 = 0;
    RemoteXY.led_s1 = 2;
    RemoteXY.led_pk1a = 2;
    RemoteXY.led_p1 = 2;

    RemoteXY.strings_p1 = 1;
    RemoteXY.strings_s1 = 1; 
    RemoteXY.strings_a1 = 1;

    setSensorColor(2, COLOR_RED); 
  }

// ================================== park 2 ===================================
  if (ir_sec2[0] == LOW || book2 == 1 )
   {
    park2 = 1;
    RemoteXY.led_s2 = 1;
    RemoteXY.led_pk2a = 1;
    RemoteXY.led_p2 = 1;

    RemoteXY.strings_p2 = 2;
    RemoteXY.strings_s2 = 2; 
    RemoteXY.strings_a2 = 2;

 setSensorColor(1, COLOR_RED); 

  }
  else if(ir_sec2[0] == HIGH || book2 == 0)
  {
    park2 = 0;
    RemoteXY.led_s2 = 2;
    RemoteXY.led_pk2a = 2;
    RemoteXY.led_p2 = 2;

    RemoteXY.strings_p2 = 1;
    RemoteXY.strings_s2 = 1; 
    RemoteXY.strings_a2 = 1;

  setSensorColor(1, COLOR_GREEN);  
  }

// ================================== park 3 ===================================
    if (ir_sec2[1] == LOW || book3 == 1 )
   {
    park3 = 1;
    RemoteXY.led_s3 = 1;
    RemoteXY.led_pk3a = 1;
    RemoteXY.led_p3 = 1;

    RemoteXY.strings_p3 = 2;
    RemoteXY.strings_s3 = 2; 
    RemoteXY.strings_a3 = 2;
 setSensorColor(0, COLOR_GREEN);
  }
  else if(ir_sec2[1] == HIGH || book3 == 0)
  {
    park3 = 0;
    RemoteXY.led_s3 = 2;
    RemoteXY.led_pk3a = 2;
    RemoteXY.led_p3 = 2;

    RemoteXY.strings_p3 = 1;
    RemoteXY.strings_s3 = 1;
    RemoteXY.strings_a3 = 1; 

 setSensorColor(0, COLOR_RED); 

  }


// ================================== park 4 ===================================
    if (ir_sec1[2] == LOW || book4 == 1 )
   {
    park4 = 1;
    RemoteXY.led_s4 = 1;
    RemoteXY.led_pk4a = 1;
    RemoteXY.led_p4 = 1;
    RemoteXY.strings_p4 = 2;
    RemoteXY.strings_s4 = 2; 
    RemoteXY.strings_a4 = 2;
  }
  else if(ir_sec1[2] == HIGH || book4 == 0)
  {
    park4 = 0;
    RemoteXY.led_s4 = 2;
    RemoteXY.led_pk4a = 2;
    RemoteXY.led_p4 = 2;

    RemoteXY.strings_p4 = 1;
    RemoteXY.strings_s4 = 1;
    RemoteXY.strings_a4 = 1; 
  }


// ================================== park 5 ===================================
    if (ir_sec1[1] == LOW || book5 == 1 )
   {
    park5 = 1;
    RemoteXY.led_s5 = 1;
    RemoteXY.led_pk5a = 1;
    RemoteXY.led_p5 = 1;
    RemoteXY.strings_p5 = 2;
    RemoteXY.strings_s5 = 2; 
    RemoteXY.strings_a5 = 2;
  }
  else if(ir_sec1[1] == HIGH || book5 == 0)
  {
    park5 = 0;
    RemoteXY.led_s5 = 2;
    RemoteXY.led_pk5a = 2;
    RemoteXY.led_p5 = 2;

    RemoteXY.strings_p5 = 1;
    RemoteXY.strings_s5 = 1;
    RemoteXY.strings_a5 = 1; 
  }

// ================================== park 6 ===================================
    if (ir_sec1[0] == LOW || book6 == 1 )
   {
    park6 = 1;
    RemoteXY.led_s6 = 1;
    RemoteXY.led_pk6a = 1;
    RemoteXY.led_p6 = 1;
    RemoteXY.strings_p6 = 2;
    RemoteXY.strings_s6 = 2; 
    RemoteXY.strings_a6 = 2;
  }
  else if(ir_sec1[0] == HIGH || book6 == 0)
  {
    park6 = 0;
    RemoteXY.led_s6 = 2;
    RemoteXY.led_pk6a = 2;
    RemoteXY.led_p6 = 2;

    RemoteXY.strings_p6 = 1;
    RemoteXY.strings_s6 = 1;
    RemoteXY.strings_a6 = 1; 
  }


// -----------------------------------------------------------------------------

// ================================ pro access =================================
if (RemoteXY.button_enter_pro == 1)
{
  if (strcmp(RemoteXY.edit_pro_user, "pro") == 0 && strcmp(RemoteXY.edit_pro_pass, "123") == 0)
  {
    RemoteXY.pro = 1;
    RemoteXY.setting = 0;
    RemoteXY.admain = 0;
    RemoteXY.stander = 0;
    RemoteXY.charge = 0;
    strcpy(RemoteXY.edit_pro_user, "");
    strcpy(RemoteXY.edit_pro_pass, "");
  }
}


// =============================== admain access ===============================
if (RemoteXY.button_enter_admain == 1)
{
  
  if (strcmp(RemoteXY.edit_admn_user, "test") == 0 && strcmp(RemoteXY.edit_admn_pass, "123") == 0)

    {
      RemoteXY.pro = 0;
      RemoteXY.setting = 0;
      RemoteXY.admain = 1;
      RemoteXY.stander = 0;
      RemoteXY.charge = 0;
      strcpy(RemoteXY.edit_admn_user, "");
      strcpy(RemoteXY.edit_admn_pass, "");
    }
}



// ================================ IR + flame =================================

  bool flameDetected = (flame[0] == LOW || flame[1] == LOW || flame[2] == LOW);

  if (flameDetected) {
    fire = 1;
  }

  if (RemoteXY.button_stop_alarm == 1) {
    fire = 0;
    fireWarnSent = 0;
  }

  if (fire == 1) {
    digitalWrite(BUZZER_PIN, HIGH);
    RemoteXY.led_fier = 2;
    RemoteXY.strings_2fire = 1;
    RemoteXY.alarm = 2027;

    if (fireWarnSent == 0) {
      RemoteXY.Warning.print("🚨 Warning: Possible fire detected in your vehicle");
      RemoteXY.Warning.send();
      fireWarnSent = 1;
    }

  } else {
    digitalWrite(BUZZER_PIN, LOW);
    RemoteXY.led_fier = 1;
    RemoteXY.strings_2fire = 2;
    RemoteXY.alarm = 0;
  }


}
