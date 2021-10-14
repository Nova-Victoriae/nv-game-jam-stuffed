#include <string>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "SettingManager.hpp"
#include "Game.hpp"

Game::Game (std::string title, Settings gameSettings)
{
    m_title = title;
    m_settings = gameSettings;
}

void Game::createRenderWindow ()
{
    sf::ContextSettings conextSettings;
    conextSettings.antialiasingLevel = m_settings.antialiasing;

    //m_window = sf::RenderWindow (sf::VideoMode (m_settings.screenWidth, m_settings.screenHeight), m_title, (m_settings.fullscreen == true) ? sf::Style::Fullscreen : sf::Style::Default, conextSettings);
    
    m_window.create(sf::VideoMode (m_settings.screenWidth, m_settings.screenHeight), m_title, (m_settings.fullscreen == true) ? sf::Style::Fullscreen : sf::Style::Default, conextSettings);
    m_window.setVerticalSyncEnabled(m_settings.vSync);
}

void Game::run ()
{
    m_gameRunning = true;

    while (m_window.isOpen() && m_gameRunning)
    {
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            m_gameRunning = false;
        }

        m_window.clear();

        // UPDATE ENTITIES
        // RENDER ENTITIES
        
        m_window.display();
    }
}