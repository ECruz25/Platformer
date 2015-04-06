#include "InstruccionesScreen.h"

InstruccionesScreen::InstruccionesScreen()
{
    //ctor
}

InstruccionesScreen::~InstruccionesScreen()
{
    //dtor
}

void InstruccionesScreen::LoadContent()
{
    background = al_load_bitmap("assets/instrucciones.png");
}

void InstruccionesScreen::UnloadContent()
{
    al_destroy_bitmap(background);
}

void InstruccionesScreen::Update(ALLEGRO_EVENT ev)
{
    if (input.IsKeyPressed(ev, ALLEGRO_KEY_BACKSPACE))
    {
        ScreenManager::GetInstance().AddScreen(new MenuScreen);
    }
}

void InstruccionesScreen::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(background, 0, 0, 0);
}
