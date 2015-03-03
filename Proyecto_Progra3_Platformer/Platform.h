#ifndef PLATFORM_H
#define PLATFORM_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include <vector>

using namespace std;

class Platform
{
    public:
        bool done;
        vector<ALLEGRO_BITMAP*>platform;
        Platform();
        void draw();
        void act();
        virtual ~Platform();
    protected:
    private:
};

#endif // PLATFORM_H
