#include "lcd.h"
#include "i2c.h"
#include <stdint.h>
#include <util/delay.h>
#define LCD_SETCGRAMADDR 0x40
#define LCD_REGISTER_SELECT_BIT 0b00000001 // Register select bit
static struct {
  uint8_t led_pin;
} lcd;

enum customchars_IDX {
  batteryRightHigh,
  batteryRightLow,
  batteryMiddleHigh,
  batteryMiddleLow,
  batteryLeftHigh,
  batteryLeftLow,
  play,
  pause
};

// clang-format off
uint8_t customChars[8][8] =
    {
        {0b11110, 0b00010, 0b11011, 0b11001, 0b11001, 0b11011, 0b00010, 0b11110}, // char 0 batteryRightHigh
        {0b11110, 0b00010, 0b00011, 0b00001, 0b00001, 0b00011, 0b00010, 0b11110}, // char 1 batteryRightLow
        {0b11111, 0b00000, 0b11111, 0b11111, 0b11111, 0b11111, 0b00000, 0b11111}, // char 2 batteryMiddleHigh
        {0b11111, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b00000, 0b11111}, // char 3 batteryMiddleLow
        {0b11111, 0b10000, 0b10111, 0b10111, 0b10111, 0b10111, 0b10000, 0b11111}, // char 4 batteryLeftHigh
        {0b11111, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b10000, 0b11111}, // char 5 batteryLeftLow
        {0b00000, 0b11000, 0b11100, 0b11110, 0b11110, 0b11100, 0b11000, 0b00000}, // char 6 play
        {0b00000, 0b11011, 0b11011, 0b11011, 0b11011, 0b11011, 0b11011, 0b00000}  // char 7 pause
      };
// clang-format on

void putnibble(char t) {
  t <<= 4;
  i2c_send_packet(lcd.led_pin |= 0x04, SLA_W);
  _delay_us(50);
  i2c_send_packet(lcd.led_pin | t, SLA_W);
  i2c_send_packet(lcd.led_pin &= ~0x04, SLA_W);
  _delay_us(50);
}

void lcd1602_send_byte(char c, char rs) {
  char highc = 0;
  highc = c >> 4;
  if (rs == LCD_COMMAND)
    i2c_send_packet(lcd.led_pin &= ~0x01, SLA_W);
  else
    i2c_send_packet(lcd.led_pin |= 0x01, SLA_W);

  putnibble(highc);
  putnibble(c);
}

void lcd1602_send_char(char c) {
  char highc = 0;
  highc = c >> 4;

  i2c_send_packet(lcd.led_pin |= 0x01, SLA_W);
  putnibble(highc);
  putnibble(c);
}

void lcd1602_init() {
  lcd.led_pin = 0;
  i2c_init();
  _delay_ms(15);
  putnibble(0b00000011);
  _delay_ms(4);
  putnibble(0b00000011);
  _delay_us(100);
  putnibble(0b00000011);
  _delay_ms(1);
  putnibble(0b00000010);
  _delay_ms(1);
  lcd1602_send_byte(0x28, LCD_COMMAND);
  _delay_ms(1);
  lcd1602_send_byte(0x0C, LCD_COMMAND);
  _delay_ms(1);
  lcd1602_send_byte(0x06, LCD_COMMAND);
  _delay_ms(1);
  i2c_send_packet(lcd.led_pin |= 0x08, SLA_W);
  i2c_send_packet(lcd.led_pin &= ~0x02, SLA_W);

  for (uint8_t i = 0; i < 8; i++) {
    lcd1602_createChar(i, customChars[i]);
    _delay_ms(1);
  }

  _delay_ms(10);
}

void lcd1602_clear() {
  lcd1602_send_byte(0x01, LCD_COMMAND);
  _delay_us(1500);
}

void lcd1602_goto_xy(char col, char row) {
  char adr;

  adr = 0x40 * row + col;
  adr |= 0x80;
  lcd1602_send_byte(adr, LCD_COMMAND);
}

void lcd1602_send_string(const char *str) {
  uint8_t i;

  for (i = 0; str[i] != '\0'; i++)
    lcd1602_send_char(str[i]);
}

void lcd1602_createChar(uint8_t slot, uint8_t charmap[8]) {
  uint8_t i = 0;
  slot &= 0x7; // we only have 8 locations 0-7
  lcd1602_send_byte(LCD_SETCGRAMADDR | (slot << 3), LCD_COMMAND);

  for (i = 0; i < 8; i++) {
    lcd1602_send_byte(charmap[i], 1);
  }
}
