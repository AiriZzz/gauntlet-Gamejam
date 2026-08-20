#pragma once
#include "Level.hpp"
#include "Levels/Level1.hpp"
#include "Levels/Level2.hpp"

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
    Texture2D m_startMenu;
    Texture2D m_confirmButton;
    Texture2D m_correctScreen;

    bool m_showStartMenu = true;
    bool m_showCorrectScreen = false;
    Music m_backgroundMusic;
    Sound m_correctSound;

};