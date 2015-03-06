#include "GameplayScreen.h"
GameplayScreen::GameplayScreen()
{
    background = al_load_bitmap("assets/back.png");
}

GameplayScreen::~GameplayScreen()
{
  //dtor
}

void GameplayScreen::LoadContent()
{

}

void GameplayScreen::UnloadContent()
{

}

void GameplayScreen::Update(ALLEGRO_EVENT ev)
{
    for(list<Character*>::iterator p=characters.begin(); p!=characters.end(); p++)
    {
        (*p)->act(ev);
    }
}

void GameplayScreen::Draw(ALLEGRO_DISPLAY *display)
{
    if(characters.size() < 1)
        characters.push_back(new Player(display,&characters));

    al_draw_bitmap(background, 0, 0, 0);

    for(list<Character*>::iterator p=characters.begin(); p!=characters.end(); p++)
            (*p)->draw(display);
}
