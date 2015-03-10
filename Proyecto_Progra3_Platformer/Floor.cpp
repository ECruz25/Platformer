#include "Floor.h"

Floor::Floor(ALLEGRO_DISPLAY* display)
{
    image = al_load_bitmap("assets/floor2.png");
}

Floor::Floor()
{
    //ctor
}

Floor::~Floor()
{
    //dtor
}

void Floor::draw(ALLEGRO_DISPLAY* display, int x, int y)
{
    al_draw_bitmap(image, x, y, 0);
}
void Floor::act(ALLEGRO_EVENT event)
{

}
