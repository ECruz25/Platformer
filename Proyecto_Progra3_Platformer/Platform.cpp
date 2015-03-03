#include "Platform.h"


Platform::Platform()
{

    platform.push_back(al_load_bitmap("plataforma.png"));
    platform.push_back(al_load_bitmap("floor2.png"));

}

void Platform::draw()
{

    al_draw_bitmap(platform[1], 0, 615,0);

}

Platform::~Platform()
{
    //dtor
}
