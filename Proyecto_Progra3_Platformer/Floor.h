#ifndef FLOOR_H
#define FLOOR_H

#include "LevelOne.h"
#include "LevelTwo.h"

class Floor
{
    public:
        Floor();
        ALLEGRO_BITMAP* floor;
        ALLEGRO_BITMAP* floor1;
        ALLEGRO_BITMAP* floor2;
        LevelOne* level1;
        LevelTwo* level2;
        void draw(ALLEGRO_DISPLAY* display, int level);
        void act(ALLEGRO_EVENT event);
        virtual ~Floor();
    protected:
    private:
};

#endif // FLOOR_H
