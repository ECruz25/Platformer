#include "GameplayScreen.h"
GameplayScreen::GameplayScreen()
{
    player = new Player;
    frame = 0;
    background = al_load_bitmap("assets/back.png");
}

GameplayScreen::~GameplayScreen()
{
}

void GameplayScreen::LoadContent()
{
}

void GameplayScreen::UnloadContent()
{
}

void GameplayScreen::Update(ALLEGRO_EVENT ev)
{
    player->act(ev);
}

void GameplayScreen::Draw(ALLEGRO_DISPLAY *display)
{
    if(!player->dead && !player->win)
    {
        level = player->level;

        al_draw_bitmap(background, 0, 0, 0);

        player->draw(display, level);
        floor.draw(display, level);
    }
    else if(player->dead)
    {
        ScreenManager::GetInstance().AddScreen(new EndScreen);
    }
    else if(player->win)
    {

    }
}
