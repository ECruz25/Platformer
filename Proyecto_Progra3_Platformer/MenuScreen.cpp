#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
    title[0] = al_load_bitmap("assets/title1.png");
    title[1] = al_load_bitmap("assets/title2.png");

    player[0] = al_load_bitmap("assets/Player/run/run/1.png");
    player[1] = al_load_bitmap("assets/Player/run/run/2.png");
//    player[2] = al_load_bitmap("assets/Player/run/run/3.png");

}

void MenuScreen::LoadContent()
{
    menu_background = al_load_bitmap("assets/menu.png");
}

void MenuScreen::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(menu_background, 0, 0, 0);
    al_draw_bitmap(title[curFrame], 100, -50, 0);
    al_draw_bitmap(player[curFrame], 550, 500, 0);
}

void MenuScreen::UnloadContent()
{
    al_destroy_bitmap(menu_background);
}

void MenuScreen::Update(ALLEGRO_EVENT ev)
{
    if(input.IsKeyPressed(ev, ALLEGRO_KEY_1))
    {
        ScreenManager::GetInstance().AddScreen(new GameplayScreen);

    }
    if(input.IsKeyPressed(ev, ALLEGRO_KEY_2))
    {
        ScreenManager::GetInstance().AddScreen(new InstruccionesScreen);
    }
    else if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        if(++frameCount >= frameDelay)
        {
            if(++curFrame >= maxFrame)
                curFrame = 0;

            frameCount = 0;
        }
    }
}

MenuScreen::~MenuScreen()
{
    //dtor
}
