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

    if(!m_font.loadFromFile("Assets\\Fonts\\OpenSans.ttf"))
    {
        std::cout << "Could not load font" << std::endl;
        exit(1);
    }

    GenerateGrid();
    GenerateGridCoord();
}


void Play::sRender()
{
    m_circle.setPosition(sf::Vector2f(120.f, 120.f));
    m_circle.rotate(2* 3.14f);

    if(game)
    {
        game->getWindow().clear(sf::Color::Blue);
        game->getWindow().draw(m_circle);
        for(const auto & line : m_grid)
        {
            game->getWindow().draw(*line);
        }

        for(const auto & text: m_texts)
        {
            game->getWindow().draw(*text);
        }
        game->getWindow().display();
    }
}

void Play::GenerateGridCoord()
{
    float cellSize = 64.f;
    int VLineCount = 1280 / cellSize;
    int HLineCount = 720 / cellSize;;

    for(int i = 0; i < VLineCount; i++)
    {
        for(int j = 0; j < HLineCount; j++)
        {
            auto text = std::make_shared<sf::Text>();
            text->setFont(m_font);
            text->setCharacterSize(12);
            text->setFillColor(sf::Color::White);
   
            text->setString(std::to_string(i) + ", " + std::to_string(HLineCount - 1 - j));
            text->setPosition(i * cellSize,  j * cellSize);

            m_texts.push_back(text);
        } 
    }
}

void Play::GenerateGrid()
{
    float cellSize = 64.f;
    int VLineCount = 1280 / cellSize;
    int HLineCount = 720 / cellSize;;

    for(int i = 1; i < VLineCount; i++)
    {
        auto VLine = std::make_shared<sf::VertexArray>(sf::Lines, 2);

        VLine->operator[](0).position = sf::Vector2f(i * cellSize, 0.f);
        VLine->operator[](1).position = sf::Vector2f(i * cellSize, 720.f);
        
        VLine->operator[](0).color = sf::Color::White;
        VLine->operator[](1).color = sf::Color::White;
        
        m_grid.push_back(VLine);
    }

    for(int i = 1; i < HLineCount; i++)
    {
        auto HLine = std::make_shared<sf::VertexArray>(sf::Lines, 2);
        
        HLine->operator[](0).position = sf::Vector2f(0.f, i * cellSize);
        HLine->operator[](1).position = sf::Vector2f(1280.f, i * cellSize);
        
        HLine->operator[](0).color = sf::Color::White;
        HLine->operator[](1).color = sf::Color::White;

        m_grid.push_back(HLine);
    }
}

void Play::update()
{
    sRender();
}

void Play::sDoAction()
{
    
}
