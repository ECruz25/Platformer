#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ScreenManager.h"
#include "InputManager.h"
#include "TitleScreen.h"
#include "GameScreen.h"

class GamePlayScreen : public GameScreen
{
    public:
        GamePlayScreen();
        ~GamePlayScreen();
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);

    private:
        ALLEGRO_FONT *font;
};

#endif // GAMEPLAYSCREEN_H
