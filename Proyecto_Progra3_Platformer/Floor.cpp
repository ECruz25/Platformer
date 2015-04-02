#include "Floor.h"

Floor::Floor()
{
    level1 = new LevelOne;
    level2 = new LevelTwo;
}

Floor::~Floor()
{

}

void Floor::draw(ALLEGRO_DISPLAY* display, int level)
{

    switch(level)
    {
        case 1:
            level1->draw(display);
            break;
        case 2:
            level2->draw(display);
            break;
        case 3:
            break;
    }

}

void Floor::act(ALLEGRO_EVENT event)
{

}
