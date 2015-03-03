#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ScreenManager.h"
#include "InputManager.h"
#include "TitleScreen.h"

class SplashScreen : public GameScreen
{
    public:
        SplashScreen();
        ~SplashScreen();
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);

    private:
        ALLEGRO_FONT *font;
};

#endif // SPLASHSCREEN_H
