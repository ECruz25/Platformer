#include "Floor.h"

Floor::Floor()
{

    level1 = new LevelOne;
//    image = al_load_bitmap("assets/floor2.png");
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
