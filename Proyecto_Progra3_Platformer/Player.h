#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#include "InputManager.h"
#include "character.h"
#include "LevelOne.h"

using namespace std;

class Player
{
    public:
        Player();
        LevelOne* level1;
        ALLEGRO_EVENT event;
        ALLEGRO_BITMAP* image;
        InputManager input;
        vector<ALLEGRO_BITMAP*> images;
        bool dead;
        int jumps;
        int frame;
        int x;
        int y;
        int h;
        int w;
        int level;
        int floor;
        bool jumping;
        bool can_jump;
        void jump();
        enum actions {LEFT, RIGHT};
        bool keys[4] = {false, false};
        virtual ~Player();
        void draw(ALLEGRO_DISPLAY* display);
        void act(ALLEGRO_EVENT event);
        void revive();
//        bool IsOnSolidGround(int x1, int y1);
//        bool TheresRoof(int x1, int y1);
    protected:
    private:
};

#endif // PLAYER_H
