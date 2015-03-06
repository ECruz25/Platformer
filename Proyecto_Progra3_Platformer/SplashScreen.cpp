#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
  //ctor
}

SplashScreen::~SplashScreen()
{
  //dtor
}

void SplashScreen::LoadContent()
{
    font = al_load_font("assets/fonts/arial.ttf", 30, 1);
}

void SplashScreen::UnloadContent()
{
    al_destroy_font(font);
}

void SplashScreen::Update(ALLEGRO_EVENT ev)
{
    if (input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen(new GameplayScreen);
    }
}

void SplashScreen::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_text(font, al_map_rgb(0, 0, 255), 100, 100, NULL, "SplashScreen");
}
