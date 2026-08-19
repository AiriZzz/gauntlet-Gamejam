#pragma once
#include "Level.hpp"
#include "Level1.hpp"
#include "Level2.hpp"

#include <memory>

class LevelManager
{
public:

    LevelManager();
    ~LevelManager();

    void Update();
    void Draw();

    void NextLevel();

private:

    int m_currentLevel;

    std::unique_ptr<Level> m_level;

    Texture2D m_background;
};