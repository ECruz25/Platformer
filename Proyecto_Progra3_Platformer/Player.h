#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <fstream>
#include <sstream>

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include "InputManager.h"
#include "character.h"
#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"

using namespace std;

class Player
{
    public:
        Player();
        LevelOne* level1;
        LevelTwo* level2;
        LevelThree* level3;
        ALLEGRO_EVENT event;
        ALLEGRO_BITMAP* image;
        ALLEGRO_FONT *font;
        InputManager input;
        ALLEGRO_BITMAP* images_derecha[3];
        ALLEGRO_BITMAP* images_izquierda[3];
        string comma;
        ostringstream oss;
        float x, y;
        int h;
        int w;
        int level;
        int floor;
        int jumps;
        int frame;
        bool jumping;
        bool can_jump;
        bool dead;
        bool win;
        const int maxFrame = 3;
        int curFrame = 0;
        int frameCount = 0;
        int frameDelay = 10;
        int score1;
        int score2;
        int score3;
        int dir;
        void jump();
        enum actions {LEFT, RIGHT};
        bool keys[2] = {false, false};
        virtual ~Player();
        void draw(ALLEGRO_DISPLAY* display, int level);
        void Draw();
        void Save();
        void UnloadContent();
        void PrintScore();
        void act(ALLEGRO_EVENT event);
        bool won(int level_);
        void revive();
    protected:
    private:
};

#endif // PLAYER_H
