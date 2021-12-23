#pragma once

class Scene
{
    int m_currentFrame = 0;
    bool m_hasEnded = 0;

public:
    virtual void update() = 0;
    virtual void sDoAction() = 0;
    virtual void sRender() = 0;

    void registerAction();

protected:
    class GameEngine* game = nullptr;
};