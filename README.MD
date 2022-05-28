# Esimerkkejä

- [Asetukset](#asetukset)
- [I2C-osoite](#i2c-osoite)
- [Ledit](#ledit)
- [Napit](#napit)
- [Potentiometri](#potentiometri)

---

# Asetukset

Valitse oikea Board, Processor ja Port.

![image](https://user-images.githubusercontent.com/72470168/170723042-c36b605f-f10c-403b-b07c-10a9298c01da.png)

```cpp
Serial.begin(9600);
```

<br>

Paina 'Serial monitor'

![image](https://user-images.githubusercontent.com/72470168/170723976-49afb139-5628-4156-84a8-5f783a06f897.png)

<br>
Valitse oikea Baud Rate.

![image](https://user-images.githubusercontent.com/72470168/170724179-baecb2f5-d22d-409e-9580-63b43cc6628b.png)
<br>

---

# I2C-osoite

<a name="i2c-osoite"></a>

 <details>
 <summary>
 I2C-osoitteen hakemineen
 </summary>

```cpp
#include "Arduino.h" // vain jos käytät VSCode ja PlatformIO
#include <Wire.h> //include Wire.h library

void setup()
{
   Wire.begin();       // Wire communication begin
   Serial.begin(9600); // The baudrate of Serial monitor is set in 9600
   while (!Serial)
       ; // Waiting for Serial Monitor
   Serial.println("\nI2C Scanner");
}

void loop()
{
   byte error, address; // variable for error and I2C address
   int nDevices;

   Serial.println("Scanning...");

   nDevices = 0;
   for (address = 1; address < 127; address++)
   {
       // The i2c_scanner uses the return value of
       // the Write.endTransmisstion to see if
       // a device did acknowledge to the address.
       Wire.beginTransmission(address);
       error = Wire.endTransmission();

       if (error == 0)
       {
           Serial.print("I2C device found at address 0x");
           if (address < 16)
               Serial.print("0");
           Serial.print(address, HEX);
           Serial.println("  !");
           nDevices++;
       }
       else if (error == 4)
       {
           Serial.print("Unknown error at address 0x");
           if (address < 16)
               Serial.print("0");
           Serial.println(address, HEX);
       }
   }
   if (nDevices == 0)
       Serial.println("No I2C devices found\n");
   else
       Serial.println("done\n");

   delay(5000); // wait 5 seconds for the next I2C scan
}
```

 </details>

---

# Ledit

<a name="ledit"></a>

<details>
 <summary>
 led blink
 </summary>

```cpp
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
```

 </details>

---

# Napit

<a name="napit"></a>

<details>
 <summary>
 Nappien käyttö
 </summary>

```cpp
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
```

 </details>

---

# Potentiometri

<a name="potentiometri"></a>

<details>
 <summary>
 Potentiometrin käyttö
 </summary>

```cpp
// potentiometri
```

 </details>
