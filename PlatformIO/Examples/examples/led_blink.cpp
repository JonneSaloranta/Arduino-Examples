#include <Arduino.h>

// sisäänrakennettu ledi (mega2560)
int ledPin = 13;

void setup()
{

    pinMode(ledPin, OUTPUT);
    pinMode(A0, INPUT_PULLUP);
}

void loop()
{

    // perus ledin vilkkuminen

    // digitalWrite(ledPin, HIGH);
    // delay(1000);
    // digitalWrite(ledPin, LOW);
    // delay(1000);

    // tekee saman kui ylempi koodi
    digitalWrite(ledPin, !digitalRead(ledPin));
    delay(1000);
}