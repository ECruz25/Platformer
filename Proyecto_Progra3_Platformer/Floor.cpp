#include "Floor.h"

Floor::Floor()
{
    level1 = new LevelOne;
    level2 = new LevelTwo;
    level3 = new LevelThree;
}

Floor::~Floor()
{

}

void Floor::UnloadContent()
{
    level1->UnloadContent();
    level2->UnloadContent();
    level3->UnloadContent();
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
            level3->draw(display);
            break;
    }
}

void Floor::act(ALLEGRO_EVENT event)
{

}
