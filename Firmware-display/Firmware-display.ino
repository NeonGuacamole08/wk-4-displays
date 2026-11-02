#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN D7          // MTX_CS -> D7

const int BTN_1   = D0;    // Button 1 (SW1)
const int BTN_2   = D1;    // Button 2 (SW3)
const int BTN_3   = D2;    // Button 3 (SW2)
const int ENC_A   = D4;    // Encoder A
const int ENC_B   = D5;    // Encoder B
const int ENC_BTN = D6;    // Encoder Switch

MD_Parola display = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

const char *messages[] = { "Hello!", "Make it yours", "8x8 forever" };
int current = 0;
int speed = 50;            
int intensity = 8;
textEffect_t effects[] = { PA_SCROLL_LEFT, PA_SCROLL_RIGHT, PA_OPENING };
int currentEffect = 0;

int lastA = HIGH;
int lastBtn1 = HIGH;
int lastBtn2 = HIGH;
int lastBtn3 = HIGH;
int lastEncBtn = HIGH;

unsigned long lastPress1 = 0;
unsigned long lastPress2 = 0;
unsigned long lastPress3 = 0;
unsigned long lastPressEnc = 0;

void setup() {
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);
  pinMode(BTN_3, INPUT_PULLUP);
  pinMode(ENC_A, INPUT_PULLUP);
  pinMode(ENC_B, INPUT_PULLUP);
  pinMode(ENC_BTN, INPUT_PULLUP);
  
  display.begin();
  display.setIntensity(intensity);
  display.displayScroll(messages[current], PA_LEFT, effects[currentEffect], speed);
}

void loop() {
  // Encoder -> speed control
  int a = digitalRead(ENC_A);
  if (a != lastA && a == LOW) {
    speed += (digitalRead(ENC_B) == HIGH) ? -5 : 5;
    speed = constrain(speed, 10, 200);
    display.setSpeed(speed);
  }
  lastA = a;

  // Button 1 -> Next message
  int btn1 = digitalRead(BTN_1);
  if (btn1 == LOW && lastBtn1 == HIGH && millis() - lastPress1 > 200) {
    current = (current + 1) % 3;
    display.displayScroll(messages[current], PA_LEFT, effects[currentEffect], speed);
    lastPress1 = millis();
  }
  lastBtn1 = btn1;

  // Button 2 -> Cycle scroll effect
  int btn2 = digitalRead(BTN_2);
  if (btn2 == LOW && lastBtn2 == HIGH && millis() - lastPress2 > 200) {
    currentEffect = (currentEffect + 1) % 3;
    display.displayScroll(messages[current], PA_LEFT, effects[currentEffect], speed);
    lastPress2 = millis();
  }
  lastBtn2 = btn2;

  // Button 3 -> Cycle display brightness
  int btn3 = digitalRead(BTN_3);
  if (btn3 == LOW && lastBtn3 == HIGH && millis() - lastPress3 > 200) {
    intensity = (intensity >= 15) ? 4 : intensity + 4;
    display.setIntensity(intensity);
    lastPress3 = millis();
  }
  lastBtn3 = btn3;

  // Encoder Button -> Reset defaults
  int encBtn = digitalRead(ENC_BTN);
  if (encBtn == LOW && lastEncBtn == HIGH && millis() - lastPressEnc > 200) {
    speed = 50;
    intensity = 8;
    display.setSpeed(speed);
    display.setIntensity(intensity);
    lastPressEnc = millis();
  }
  lastEncBtn = encBtn;

  if (display.displayAnimate()) display.displayReset();
}