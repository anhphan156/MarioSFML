#pragma once
#include "Scene.h"

class Play : public Scene
{
    void sRender() override;
    void sDoAction() override;

    sf::CircleShape m_circle;

public:
    void update() override;

    Play(class GameEngine* game);
};