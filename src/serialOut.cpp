#include <Arduino.h>
#include <serialOut.h>

void serialSetup(){
     // Serielle Verbindung starten - zeigt uns Debug-Ausgaben
  // im "Serial Monitor" von PlatformIO an
  Serial.begin(115200);
  Serial.println("setup");
  delay(1000);  // Kurze Pause, damit der serielle Monitor Zeit hat, sich zu verbinden
  Serial.println();
  Serial.println("=================================");
  Serial.println("Garagentor-Projekt - Setup-Test");
  Serial.println("=================================");
  Serial.println("Wenn du das hier liest, funktioniert:");
  Serial.println("  - PlatformIO Build");
  Serial.println("  - Upload/Simulation");
  Serial.println("  - Serielle Kommunikation");
  Serial.println();
}