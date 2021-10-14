#pragma once

#include <string>
#include <bitset>

struct Settings
{
    uint32_t screenWidth;
    uint32_t screenHeight;
    uint8_t scaleFactor;
    uint8_t fullscreen;
    uint8_t vSync;
    uint8_t antialiasing;
};

void loadSettings (std::string configFile, Settings &settings);
void printSettings (Settings &settings);