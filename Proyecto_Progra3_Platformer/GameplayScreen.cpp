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

    level = player->level;
//
////    cout<<"LEVELLLLLLLLLLLL: "<<level<<endl;
//
    al_draw_bitmap(background, 0, 0, 0);
//
    player->draw(display, 1);
    floor.draw(display, 1);

}
