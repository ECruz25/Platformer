#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ScreenManager.h"
#include "InputManager.h"
#include "TitleScreen.h"
#include "GameplayScreen.h"

class SplashScreen : public GameScreen
{
    public:
        SplashScreen();
        virtual ~SplashScreen();
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        ALLEGRO_FONT *font;

    private:
};

#endif // SPLASHSCREEN_H
