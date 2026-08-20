#include "LevelManager.hpp"

LevelManager::LevelManager()
    : m_currentLevel(1)
{
    LevelData levelData = CreateLevel1();

    m_level = std::make_unique<Level>(levelData);

    m_background = LoadTexture("codes/Images/Background1.png");

    m_startMenu = LoadTexture("codes/Images/Menu.png");

    m_confirmButton = LoadTexture("codes/Images/Levels/Confirm.png");

    m_correctScreen = LoadTexture("codes/Images/Levels/CorrectScreen.png");

    m_backgroundMusic = LoadMusicStream("codes/Images/BGM.mp3");

    m_correctSound = LoadSound("codes/Images/Correct.wav");

    m_backgroundMusic.looping = true;

    PlayMusicStream(m_backgroundMusic);
}

LevelManager::~LevelManager()
{
    UnloadTexture(m_background);
    UnloadTexture(m_startMenu);

    UnloadMusicStream(m_backgroundMusic);
    UnloadSound(m_correctSound);

}

void LevelManager::Update()
{
    UpdateMusicStream(m_backgroundMusic);

    if (m_showStartMenu)
    {
        if (IsKeyPressed(KEY_ENTER))
        {
            m_showStartMenu = false;

        }

        return;
    }

    m_level->Update();

    if(m_level->CheckPuzzle()){
        PlaySound(m_correctSound);
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT) && m_level->CheckPuzzle()){
        NextLevel();
    } //When the screen shows, only move on when player press right mouse button and when the puzzle is complete
}

void LevelManager::Draw()
{
    DrawTexture(m_background,0,0,WHITE);


    m_level->Draw();

    DrawTextureEx(m_confirmButton, {1400, 830,}, 0.0, 0.2, WHITE);

    if(m_showStartMenu) DrawTexture(m_startMenu,0,0,WHITE);

    if(m_level->CheckPuzzle()) {

        DrawTextureEx(
            m_correctScreen, {(static_cast<float>(GetScreenWidth()) / 2) - (m_correctScreen.width/2) , (static_cast<float>(GetScreenHeight()) / 2) - (m_correctScreen.height/2)} //to centre texture in the screen, only works when scale is 1.0
            , 0.0, 1.0, WHITE);
    }
    
}

void LevelManager::NextLevel()
{
    m_currentLevel++;

    if (m_currentLevel == 2)
    {
        LevelData levelData = CreateLevel2();

        m_level = std::make_unique<Level>(levelData); //replace old data with new, next level data
    }
}