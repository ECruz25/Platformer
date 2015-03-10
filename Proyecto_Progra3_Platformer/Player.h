#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "InputManager.h"

class Player : public Character
{
    public:
        Player();
        Player(ALLEGRO_DISPLAY* display, list<Character*> *characters);
        ALLEGRO_EVENT event;
        InputManager input;
        int jumps;
        int floor;
        bool jumping;
        bool can_jump;
        void jump();
        enum actions {LEFT, RIGHT};
        bool keys[4] = {false, false};
        virtual ~Player();
        void draw(ALLEGRO_DISPLAY* display);
        void act(ALLEGRO_EVENT event);
        bool IsOnSolidGround(int x1, int y1);
        bool TheresRoof(int x1, int y1);
    protected:
    private:
};

#endif // PLAYER_H
