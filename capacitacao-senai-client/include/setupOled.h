#ifndef __SETUPOLED_H__
#define __SETUPOLED_H__
#include <Arduino.h>
#include <I2Cdev.h>
#include <SPI.h>
#include <SSD1306Ascii.h>
#include <SSD1306AsciiWire.h>

#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

#define SCREEN_ADDRESS \
  0x3C  ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

SSD1306AsciiWire display;

void setupOled() {
  Wire.begin();
  Wire.setClock(400000L);
  display.begin(&Adafruit128x64, SCREEN_ADDRESS);
  display.setFont(System5x7);
#if INCLUDE_SCROLLING == 0
#error INCLUDE_SCROLLING must be non-zero.  Edit SSD1306Ascii.h
#endif
  display.setScrollMode(SCROLL_MODE_AUTO);
}

#endif  // __SETUPOLED_H__