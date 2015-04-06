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
        Floor floor;
        ostringstream oss1;
        ostringstream oss2;
        ostringstream oss3;
        int score1;
        int score2;
        int score3;
        string str_score1;
        string str_score2;
        string str_score3;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        void Save();
        void PrintScore();
        string PrintName();
        virtual ~WinScreen();
    protected:
    private:
};

#endif // WINSCREEN_H
