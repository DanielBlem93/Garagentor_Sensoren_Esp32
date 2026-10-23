#pragma once
void handleGarageDoors();
void checkButtonStates();
void meldeWechsel(const char *name, bool aktuell, bool &vorher);
extern bool torEinsAuf;
extern bool torZweiAuf;