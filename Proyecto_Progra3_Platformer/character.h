#ifndef CHARACTER_H
#define CHARACTER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

using namespace std;

class character
{
    public:
        int x, y, h, w, frame;
        character();
        virtual ~character();
        virtual void draw(ALLEGRO_DISPLAY* display);
        virtual void act(ALLEGRO_EVENT event) = 0;
    protected:
    private:
};

#endif // CHARACTER_H
