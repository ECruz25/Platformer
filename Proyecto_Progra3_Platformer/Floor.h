#ifndef FLOOR_H
#define FLOOR_H

#include "LevelOne.h"
#include "LevelTwo.h"
#include "LevelThree.h"

class Floor
{
    public:
        Floor();
        LevelOne* level1;
        LevelTwo* level2;
        LevelThree* level3;
        void draw(ALLEGRO_DISPLAY* display, int level);
        void act(ALLEGRO_EVENT event);
        void UnloadContent();
        virtual ~Floor();
    protected:
    private:
};

#endif // FLOOR_H
