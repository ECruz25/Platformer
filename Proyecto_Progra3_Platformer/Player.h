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
        void Movement();
        int jumps;
        int floor;
        bool jumping;
        void jump();
        enum actions {UP, DOWN, LEFT, RIGHT};
        bool keys[4] = {false, false, false, false};
        virtual ~Player();
        void draw(ALLEGRO_DISPLAY* display);
        void act(ALLEGRO_EVENT event);
    protected:
    private:
};

#endif // PLAYER_H
