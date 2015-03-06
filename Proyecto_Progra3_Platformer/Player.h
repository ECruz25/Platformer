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
        enum actions {UP, DOWN, LEFT, RIGHT};
        bool keys[4] = {false, false, false, false};
        virtual ~Player();
        void act(ALLEGRO_EVENT event);
    protected:
    private:
};

#endif // PLAYER_H
