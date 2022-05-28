#include "Arduino.h" // vain jos käytät VSCode ja PlatformIO

// sisäänrakennettu ledi (mega2560)
int ledPin = 13;

int tempo = 1000;

// nappien pinnit
int buttonPins[4] = {47, 49, 51, 53};

// 4 kpl nappien pinnejä (alkaa nollasta)

// buttonPins[0] = 47;
// buttonPins[1] = 49;
// buttonPins[2] = 51;
// buttonPins[3] = 53;

// nappi "malli" joka sisältää napin tiedot
struct Button
{
    int number;
    int pin;
};

//#############################################################################
// esimerkki struct käytöstä
struct Car
{
    String manufacturer;
    String model;
    unsigned int year;
    unsigned int price;
};

Car cars[3] = {
    {"Ford", "Mustang", 1969, 200000},
    {"Audi", "A4", 2017, 300000},
    {"BMW", "X5", 2018, 400000}};

// Serial.println(cars[0].manufacturer);       Ford
// Serial.println(cars[2].year);              2018
//#############################################################################

// tehdään 4 nappia
Button buttons[4];

// väliaikainen aika-muuttuja
int tempTime = 0;

void setup()
{

    // ledin pinni
    pinMode(ledPin, OUTPUT);

    // käydään kaikki napit läpi ja aseteaan tiedot
    for (int i = 0; i < sizeof(buttons) / sizeof(buttons[0]); i++)
    {
        pinMode(buttonPins[i], INPUT_PULLUP);
        buttons[i].number = i;
        buttons[i].pin = buttonPins[i];
    }

    Serial.begin(9600);
}

void checkButton(Button button)
{

    int reading = digitalRead(button.pin);

    if (reading == LOW)
    {
        if (millis() - tempTime > 50)
        {
            tempTime = millis();
            Serial.println("Button " + String(button.number) + " pressed, pin " + String(button.pin));
            while (digitalRead(button.pin) == LOW)
            {
                // wait for release
            }
            tempTime = millis();
        }
    }
}

void loop()
{
    checkButton(buttons[0]);
    checkButton(buttons[1]);
    checkButton(buttons[2]);
    checkButton(buttons[3]);
}