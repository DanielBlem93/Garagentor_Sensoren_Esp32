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
#include "serialOut.h"

// GPIO2 ist bei den meisten ESP32 DevKit-Boards mit der
// eingebauten LED verbunden. Falls deine externe LED an
// einem anderen Pin haengt, hier anpassen.
const int LED_PIN = 2;

// Zustand merken, damit wir beim Wechsel eine Meldung ausgeben
bool ledState = false;

void setup()
{

  pinMode(LED_PIN, OUTPUT); // LED-Pin als Ausgang konfigurieren
  serialSetup();
}

void loop()
{
  // LED-Zustand umschalten
  ledState = !ledState;
  digitalWrite(LED_PIN, ledState);

  // Status auf der seriellen Konsole ausgeben
  Serial.print("LED ist jetzt: ");
  Serial.println(ledState ? "AN" : "AUS");

  // Eine Sekunde warten
  delay(2000);
}
