#include "TitleScreen.h"

TitleScreen::TitleScreen()
{
  //ctor
}

TitleScreen::~TitleScreen()
{
  //dtor
}

void TitleScreen::LoadContent()
{
    font = al_load_font("assets/fonts/arial.ttf", 30, NULL);
}

void TitleScreen::UnloadContent()
{
    al_destroy_font(font);
}

void TitleScreen::Update(ALLEGRO_EVENT ev)
{
    if (input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen(new SplashScreen);
    }
}

void TitleScreen::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_text(font, al_map_rgb(255, 0, 0), 100, 100, NULL, "TitleScreen");
}
