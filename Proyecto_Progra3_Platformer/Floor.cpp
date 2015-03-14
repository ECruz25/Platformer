#include "Floor.h"

Floor::Floor()
{
    level1 = new LevelOne;
}

Floor::~Floor()
{

}

void Floor::draw(ALLEGRO_DISPLAY* display)
{
    level1->draw(display);
}
void Floor::act(ALLEGRO_EVENT event)
{

}
