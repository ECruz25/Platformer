#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

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
        InputManager input;
        vector<ALLEGRO_BITMAP*> images;
        float x, y;
        float dx, dy;
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
        void jump();
        enum actions {LEFT, RIGHT};
        bool keys[2] = {false, false};
        virtual ~Player();
        void draw(ALLEGRO_DISPLAY* display, int level);
        void Draw();
        void act(ALLEGRO_EVENT event);
        bool won(int level_);
        void revive();
    protected:
    private:
};

#endif // PLAYER_H
