#pragma once
#include <SFML/Graphics.hpp>
#include "Type.h"

class GameEngine
{
    sf::RenderWindow m_window;

    std::shared_ptr<Scene> m_currenScene;

    void init();

    SceneMap scenes;

    void sUserInput();

public:
    void run();
    sf::RenderWindow & getWindow();

    GameEngine();
};
