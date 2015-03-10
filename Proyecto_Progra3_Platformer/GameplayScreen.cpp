#include "GameplayScreen.h"
GameplayScreen::GameplayScreen()
{
    floor_ = al_load_bitmap("assets/floor.png");
    floor1 = al_load_bitmap("assets/floor_2.png");
    floor2 = al_load_bitmap("assets/floor2.png");
    background = al_load_bitmap("assets/dark.png");
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

    al_draw_bitmap(floor_, 450, 368, 0);
    al_draw_bitmap(floor2, 160, 565, 0);
    al_draw_bitmap(floor1, -500, 465, 0);
    al_draw_bitmap(floor1, -350, 365, 0);
}
