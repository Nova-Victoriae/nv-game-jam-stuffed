#pragma once

#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
    public:
        Game (std::string title, Settings gameSettings);

        void createRenderWindow();

        void loadAssets (std::string assetFile);

        void run ();

        // Getters and Setters
        std::string getTitle () { return m_title; }
        uint32_t getWidth () { return m_settings.screenWidth; }
        uint32_t getHeight () { return m_settings.screenHeight; }
        uint8_t getScaleFactor () { return m_settings.scaleFactor; }

        void setGameRunning (uint8_t gameRunning) { m_gameRunning = gameRunning; }
        uint8_t isGameRunning () { return m_gameRunning; }
    private:
        std::string m_title;
        Settings m_settings;

        sf::RenderWindow m_window;

        uint8_t m_gameRunning;
};