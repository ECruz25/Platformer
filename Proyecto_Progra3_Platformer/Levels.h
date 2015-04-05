#ifndef LEVELS_H
#define LEVELS_H

#include<iostream>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

class Levels
{
    public:
        Levels();
        virtual void draw(ALLEGRO_DISPLAY* display) = 0;
        virtual bool IsOnSolidGround(int x1, int y1)= 0;
        virtual bool TheresRoof(int x1, int y1)= 0;
        virtual void UnloadContent() = 0;
        virtual ~Levels();
    protected:
    private:
};

#endif // LEVELS_H
