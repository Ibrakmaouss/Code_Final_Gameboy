#include <SPI.h>
#include <TFT_eSPI.h>
#include <Arduino.h>
#include "driver/i2s.h"
#include "CodeFinal.h"

byte mode = 0;

TFT_eSPI tft = TFT_eSPI();
int L = 0;
int H = 0;


void setup() {
  Serial.begin(115200);

  pinMode(BP1, INPUT);
  pinMode(BP2, INPUT);
  pinMode(BP3, INPUT);
  pinMode(BP4, INPUT);
  pinMode(BP5, INPUT);

  tft.init();
  tft.setRotation(2);

  L = tft.width();
  H = tft.height();

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_PINK, TFT_BLACK);
  tft.setTextSize(5);
  tft.setCursor(70, 150);
  tft.println("GameBoy");
  tft.setTextSize(2);
  tft.setCursor(120, 400);
  tft.print("par Logan");
  delay(600);

  i2s_init_simple();
  beep_A4_50ms();

  tft.fillScreen(TFT_BLACK);
  BarChargement500ms();
  Menu();
}


void loop() {
  if (mode == 0) {
    if (digitalRead(BP1) == 1) {
      mode = 1;
      delay(20);
    } else if (digitalRead(BP2) == 1) {
      mode = 2;
      delay(20);
    } else if (digitalRead(BP3) == 1) {
      mode = 3;
      delay(20);
    } else if (digitalRead(BP4) == 1) {
      mode = 4;
      delay(20);
    }
  }
}
