#include "LevelManager.hpp"

LevelManager::LevelManager()
    : m_currentLevel(1)
{
    LevelData levelData = CreateLevel1();

    m_level = std::make_unique<Level>(levelData);

    m_background = LoadTexture("codes/Images/Background.png");
}

LevelManager::~LevelManager()
{
    UnloadTexture(m_background);
}

void LevelManager::Update()
{
    m_level->Update();

    if (IsKeyPressed(KEY_N)){
        NextLevel();
    }
}

void LevelManager::Draw()
{
    DrawTexture(m_background,0,0,WHITE);
    m_level->Draw();
}

void LevelManager::NextLevel()
{
    m_currentLevel++;

    TraceLog(
        LOG_INFO,
        "Moving to level %d",
        m_currentLevel
    );

    if (m_currentLevel == 2)
    {
        LevelData levelData = CreateLevel2();

        m_level = std::make_unique<Level>(levelData); //replace old data with new, next level data
    }
}