#include <Arduino.h>

#include <Wire.h>

// https://www.dropbox.com/s/oned8gbbfpy5vja/LiquidCrystal-I2C.zip?dl=0
// toimiva lcd-kirjasto

#include <LiquidCrystal_I2C.h>

// LiquidCrystal_I2C(näytön I2C osoite, sarakkeita ,rivejä));
LiquidCrystal_I2C lcd(0x27, 20, 4);

byte blur[8] = {
    0b01010,
    0b10101,
    0b01010,
    0b10101,
    0b01010,
    0b10101,
    0b01010,
    0b10101,
};

byte smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b10001,
    0b01110,
    0b00000,
    0b00000};

byte empty[8] = {
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000};

void setup()
{
    lcd.begin();

    // luo custom symbolit
    lcd.createChar(0, blur);
    lcd.createChar(1, smiley);
    lcd.createChar(2, empty);

    // tyhjennä näyttö
    lcd.clear();
    lcd.noBlink();
}

void loop()
{
    // käy läpi jokaisen ruudun
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            // asettaa kursorin ruutuun
            lcd.setCursor(j, i);
            // kirjoittaa ruudulle symbolin 0 eli blur
            lcd.write(0);
            // delay 10ms jokaisen symbolin välillä
            delay(10);
        }
    }

    // sama juttu tyhjentäessä ruudun

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            lcd.setCursor(j, i);
            // kirjoittaa ruudulle symbolin 2 eli empty
            lcd.write(2);
            delay(10);
        }
    }
}
