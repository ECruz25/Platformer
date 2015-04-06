#ifndef WINSCREEN_H
#define WINSCREEN_H

#include <fstream>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "ScreenManager.h"
#include "InputManager.h"
#include "TitleScreen.h"
#include "GameplayScreen.h"
#include "Character.h"
#include "Player.h"
#include "Floor.h"

class WinScreen : public GameScreen
{
    public:
        WinScreen();
        ALLEGRO_BITMAP *background;
        ALLEGRO_FONT *font;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        void Save();
        virtual ~WinScreen();
    protected:
    private:
};

#endif // WINSCREEN_H
