#ifndef CHARACTER_H
#define CHARACTER_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <vector>
#include <list>
#include <iostream>
#include <map>

using namespace std;

class Character
{
    public:
        Character();
        virtual ~Character();
        list<Character*> *characters;
        map< string, vector<ALLEGRO_BITMAP*>* > mapa_texturas;

        int frame;
        int textura_actual_int;
        string vector_actual_str;
        string temp;
        float x, y, w, h;

        virtual void draw(ALLEGRO_DISPLAY* display);
        virtual void act(ALLEGRO_EVENT event) = 0;
        void init(ALLEGRO_DISPLAY* display, list<Character*> *characters);
        void setAnimacion(string nombre);
    protected:
    private:
};

#endif // CHARACTER_H
