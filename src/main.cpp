/*
 * Hello World - ESP32 Setup-Test
 *
 * Ziel: Verifizieren, dass PlatformIO + Wokwi-Simulation laufen,
 * bevor es an das eigentliche Garagentor-Projekt geht.
 *
 * Verhalten: Eingebaute LED (bzw. externe LED an Pin 2) blinkt,
 * und wir geben zusätzlich Status-Meldungen über die serielle
 * Konsole aus - das ist beim späteren Debuggen extrem hilfreich.
 */

#include <Arduino.h>
#include <serialOut.h>
#include <main.h>

int led1 = 18;
int led2 = 19;
int button1 = 16;
int button2 = 4;
unsigned long lastTime = 0;

bool ledState = false;
bool torEinsAuf;
bool torZweiAuf;

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
  handleGarageDoor();
}

void checkButtonStates()
{
  torEinsAuf = digitalRead(button1) == LOW ? true : false;
  torZweiAuf = digitalRead(button2) == LOW ? true : false;
}

void handleGarageDoor()
{
  if (torEinsAuf && !torZweiAuf)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  }
  else if (!torEinsAuf && torZweiAuf)
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  else if (torEinsAuf && torZweiAuf)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
  }
  else
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
  }
}