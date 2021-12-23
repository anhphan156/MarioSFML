#pragma once
#include <SFML/Graphics.hpp>
#include "../GameEngine.h"
#include "Play.h"

#include <iostream>

Play::Play(GameEngine* game)
{
    this->game = game; 
    m_circle = sf::CircleShape(55.f, 6);
    m_circle.setOrigin(55.f, 55.f);
}


void Play::sRender()
{
    m_circle.setPosition(sf::Vector2f(120.f, 120.f));
    m_circle.rotate(5* 3.14f);

    if(game)
    {
        game->getWindow().clear();
        game->getWindow().draw(m_circle);
        game->getWindow().display();
    }
}

void Play::update()
{
    sRender();
}

void Play::sDoAction()
{
    
}
