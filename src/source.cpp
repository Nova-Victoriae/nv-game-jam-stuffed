#include <iostream>

#include "SettingManager.hpp"
#include "Game.hpp"

int main ()
{
    Settings settings;
    loadSettings ("config.json", settings);

    Game game ("Stuffed INDEV", settings);
    game.createRenderWindow();
    game.run();
    //printSettings (settings);

    return 0;
}