#pragma once
#include "Level.hpp"
#include "Levels/Level1.hpp"
#include "Levels/Level2.hpp"
#include "Levels/Level3.hpp"
#include "Levels/Level4.hpp"
#include "Levels/Level5.hpp"
#include "Levels/Level6.hpp"
#include "Levels/Level7.hpp"
#include "Levels/Level8.hpp"


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
    Texture2D m_thankYouScreen;

    bool m_showStartMenu = true;
    bool m_showCorrectScreen = false;
    Music m_backgroundMusic;
    Sound m_correctSound;

};