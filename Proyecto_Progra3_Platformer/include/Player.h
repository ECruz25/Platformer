#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
    public:
        Player(ALLEGRO_DISPLAY* display, list<Character*> *characters);
        ALLEGRO_EVENT_QUEUE *eventQueue;
        ALLEGRO_EVENT event;
        virtual ~Player();
        void act();
    protected:
    private:
};

#endif // PLAYER_H
