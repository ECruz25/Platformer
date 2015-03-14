#include "GameplayScreen.h"
GameplayScreen::GameplayScreen()
{
    player = new Player;
    frame = 0;
    background = al_load_bitmap("assets/back.png");
    enemy = al_load_bitmap("assets/assets platformer/grotto_escape_pack/graphics/enemies.png");
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

    player->act(ev);

}

void GameplayScreen::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(background, 0, 0, 0);

    player->draw(display);
    floor.draw(display);

    if(frame%100 == 0)
    {
//        for(int t = 16; t < 64; t+=16)
//        {
//            al_draw_bitmap_region(enemy, frame, 16, 16, 16, 200, 300, 0);
//            al_flip_display();

//            cout<<t<<endl;
//
//            if(t == 48)
//            {
//                t = 16;
//            }
//        }
    }

}
