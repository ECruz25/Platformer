#ifndef ENDSCREEN_H
#define ENDSCREEN_H

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

class EndScreen : public GameScreen
{
    public:
        EndScreen();
        ALLEGRO_FONT *font;
        Player player;
        Floor floor;
        ostringstream oss;
        int score;
        string str_score;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        void Save();
        int PrintScore();
        string PrintName();
        virtual ~EndScreen();
    protected:
    private:
};

#endif // ENDSCREEN_H
