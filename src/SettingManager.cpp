#include <iostream>
#include <fstream>
#include <string>

#include <jsoncpp/json/json.h>

#include "SettingManager.hpp"

void loadSettings (std::string configFile, Settings &settings)
{
    std::ifstream ifs (configFile);

    Json::Reader reader;
    Json::Value obj;

    reader.parse(ifs, obj);

    settings.fullscreen = obj["fullscreen"].asUInt();
    settings.screenWidth = obj["screen_width"].asUInt();
    settings.screenHeight = obj["screen_height"].asUInt();
    settings.scaleFactor = obj["scale_factor"].asUInt();
    settings.vSync = obj["vSync"].asUInt();
    settings.antialiasing = obj["antialaing"].asUInt();
}

void printSettings (Settings &settings)
{
    std::cout << "Fullscreen: " << std::to_string(settings.fullscreen) << std::endl;
    std::cout << "Width, Height: " << std::to_string(settings.screenWidth) << ", " << std::to_string(settings.screenHeight) << std::endl;
    std::cout << "Scale Factor: " << std::to_string(settings.scaleFactor) << std::endl;
    std::cout << "VSync: " << std::to_string(settings.vSync) << std::endl;
    std::cout << "Antialiasing: " << std::to_string(settings.antialiasing) << std::endl;
}
