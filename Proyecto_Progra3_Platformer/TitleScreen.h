#pragma once

#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "ScreenManager.h"
#include "InputManager.h"

class TitleScreen : public GameScreen
{
    public:
        TitleScreen();
        ~TitleScreen();
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);

    private:
        ALLEGRO_FONT *font;
};

#endif // TITLESCREEN_H
