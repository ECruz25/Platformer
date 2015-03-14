#ifndef ENEMY_H
#define ENEMY_H

#include "character.h"

class Enemy : public character
{
    public:
        Enemy();
        void draw(ALLEGRO_DISPLAY* display);
        void act(ALLEGRO_EVENT event);
        virtual ~Enemy();
    protected:
    private:
};

#endif // ENEMY_H
