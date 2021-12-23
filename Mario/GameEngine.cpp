#pragma once
#include "GameEngine.h"
#include "Scene/Play.h"

#define PlayScene scenes["play"] 

GameEngine::GameEngine()
{
    init();
}

void GameEngine::init()
{
    // Window setup
    m_window.create(sf::VideoMode(1280, 720), "Mario");
    m_window.setFramerateLimit(60);

    // Scene setup
    PlayScene = std::make_shared<Play>(this);

    // Engine setup
    m_currenScene = PlayScene;
}

sf::RenderWindow& GameEngine::getWindow()
{
    return m_window;
}

void GameEngine::sUserInput()
{
    sf::Event event;
    while(m_window.pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_window.close();
        }
    }
}

void GameEngine::run()
{
    while(m_window.isOpen())
    {
        sUserInput();
        m_currenScene->update();
    }
}
