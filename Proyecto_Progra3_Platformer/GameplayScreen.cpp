#include "GameplayScreen.h"
GameplayScreen::GameplayScreen()
{
    player = new Player;
    frame = 0;
}

GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::LoadContent()
{
}

void GameplayScreen::UnloadContent()
{
    player->UnloadContent();
    floor.UnloadContent();
}

void GameplayScreen::Update(ALLEGRO_EVENT ev)
{
    player->act(ev);
}

void GameplayScreen::Draw(ALLEGRO_DISPLAY *display)
{
    level = player->level;
    if(!player->dead && !player->win)
    {
        floor.draw(display, level);
        player->draw(display, level);
    }
    else if(player->dead)
    {
//        UnloadContent();
        ScreenManager::GetInstance().AddScreen(new EndScreen);
    }
    else if(player->win)
    {

    }
}
