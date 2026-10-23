#include <WiFi.h>
#include <WebServer.h>
#include "main_wifi.h"
#include "secrets.h"
#include "serialOut.h"
#include "main.h"

WebServer server(80);

void wifiVerbinden()
{
    WiFi.mode(WIFI_STA); // ESP32 als normaler WLAN-Teilnehmer
    WiFi.begin(WLAN_SSID, WLAN_PASSWORT);
    Serial.println("Verbinde WLAN...");
    Serial.println();
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println();
    Serial.println(WiFi.localIP()); // diese IP brauchst du später
}

void startServer()
{
    server.on("/tor", handleTor); // /tor ist die URL, die der ESP32 aufruft, wenn er das Tor öffnen soll
    server.begin();               // Webserver starten
    Serial.println("Server gestartet");
    server.send(200, "text/plain", "OK"); // Antwort an den Sender
}

void handleTor() // wird bei Aufruf von /tor ausgeführt
{
    if (!server.hasArg("nr") || !server.hasArg("auf"))
    {
        server.send(400, "text/plain", "Fehler: Parameter nr und/oder auf fehlen");
        return;
    }

    int nr = server.arg("nr").toInt();   // 1 = Tor 1 | 2 = Tor 2
    int auf = server.arg("auf").toInt(); // 1 = auf   | 0 = zu

    if (nr < 1 || nr > 2 || auf < 0 || auf > 1)
    {
        server.send(400, "text/plain", "Fehler: Ungueltige Tor-Nummer oder Parameter");
        return;
    }

    if (nr == 1)
    {
        torEinsAuf = (auf == 1);
        Serial.println(torEinsAuf ? "Tor 1 geht auf" : "Tor 1 geht zu");
    }
    else
    {
        torZweiAuf = (auf == 1);
        Serial.println(torZweiAuf ? "Tor 2 geht auf" : "Tor 2 geht zu");
    }

    server.send(200, "text/plain", "OK");
}
