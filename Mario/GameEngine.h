#pragma once
#include <SFML/Graphics.hpp>
#include "Type.h"

class GameEngine
{
    sf::RenderWindow m_window;
    SceneMap scenes;
    std::shared_ptr<Scene> m_currenScene;

    void init();
    void sUserInput();

public:
    void run();
    sf::RenderWindow & getWindow();

    GameEngine();
};
