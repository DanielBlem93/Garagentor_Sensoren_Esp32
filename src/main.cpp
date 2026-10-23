#include <Arduino.h>
#include <serialOut.h>
#include "main.h"
#include "secrets.h"


int led1 = 18;
int led2 = 19;
int button1 = 16;
int button2 = 4;

bool torEinsAuf = false;
bool torZweiAuf = false;
bool torEinsAufVorher = false;
bool torZweiAufVorher = false;

void setup()
{
  serialSetup();
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
}

void loop()
{
  checkButtonStates();
  handleGarageDoors();
}

void checkButtonStates()
{
  torEinsAuf = !digitalRead(button1);
  torZweiAuf = !digitalRead(button2);
}

void handleGarageDoors()
{
  digitalWrite(led1, torEinsAuf);
  digitalWrite(led2, torZweiAuf);

  if (torEinsAuf != torEinsAufVorher)
  {
    meldeWechsel("Tor 1", torEinsAuf, torEinsAufVorher);
  }

  if (torZweiAuf != torZweiAufVorher)
  {
    meldeWechsel("Tor 2", torZweiAuf, torZweiAufVorher);
  }
}

void meldeWechsel(const char *name, bool aktuell, bool &vorher)
{
  if (aktuell != vorher)
  {
    Serial.println(String(name) + (aktuell ? ": Auf" : ": Zu"));
    vorher = aktuell;
  }
}