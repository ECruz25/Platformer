#ifndef FLOOR_H
#define FLOOR_H

#include "Character.h"
#include "LevelOne.h"

class Floor : public Character
{
    public:
        Floor();
        ALLEGRO_BITMAP* floor;
        ALLEGRO_BITMAP* floor1;
        ALLEGRO_BITMAP* floor2;
        LevelOne* level1;
        void draw(ALLEGRO_DISPLAY* display);
        void act(ALLEGRO_EVENT event);
        virtual ~Floor();
    protected:
    private:
};

#endif // FLOOR_H
