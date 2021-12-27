#pragma once
#include "Scene.h"

class Play : public Scene
{
    void sRender() override;
    void sDoAction() override;

    sf::CircleShape m_circle;
    std::vector<std::shared_ptr<sf::VertexArray>> m_grid;

    void GenerateGrid();
    void GenerateGridCoord();

    sf::Font m_font;
    std::vector<std::shared_ptr<sf::Text>> m_texts;

public:
    void update() override;

    Play(class GameEngine* game);
};