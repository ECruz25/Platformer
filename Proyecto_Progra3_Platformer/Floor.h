#ifndef FLOOR_H
#define FLOOR_H

#include "Character.h"

class Floor : public Character
{
    public:
        Floor(ALLEGRO_DISPLAY* display);
        Floor();
        ALLEGRO_BITMAP* image;
        void draw(ALLEGRO_DISPLAY* display, int x, int y);
        void act(ALLEGRO_EVENT event);
        virtual ~Floor();
    protected:
    private:
};

#endif // FLOOR_H
