#include "Character.h"

Character::Character()
{
    y = 0;
    x = 0;
    w = 75;
    h = 30;
    int frame = 0;
}

Character::~Character()
{

}

void Character::draw(ALLEGRO_DISPLAY* display)
{
    vector<ALLEGRO_BITMAP*> *vector_textura_actual_temp = mapa_texturas[vector_actual_str];

    ALLEGRO_BITMAP* textura_actual_temp = (*vector_textura_actual_temp)[textura_actual_int];

    al_draw_bitmap(textura_actual_temp, x, y, 0);

    if(frame%100==0)
    {
        textura_actual_int++;
        if(textura_actual_int>=(*vector_textura_actual_temp).size())
        {
            textura_actual_int=0;
            if(vector_actual_str != "walk_right" && vector_actual_str != "walk_left")
            {
                if(vector_actual_str == "punch_right")
                    setAnimacion("right");
                if(vector_actual_str == "punch_left")
                    setAnimacion("left");
            }
        }
    }
    frame++;
}

void Character::init(ALLEGRO_DISPLAY* display, list<Character*> *characters)
{
    frame=0;
    textura_actual_int=0;
    this->characters = characters;
}

void Character::setAnimacion(string nombre)
{
    if(this->vector_actual_str != nombre)
    {
        this->textura_actual_int = 0;

        vector<ALLEGRO_BITMAP*> *vector_textura_actual_temp = mapa_texturas[nombre];

        ALLEGRO_BITMAP* textura_actual_temp = (*vector_textura_actual_temp)[textura_actual_int];

        al_draw_bitmap(textura_actual_temp, x, y, 0);
    }
    this->vector_actual_str = nombre;
}
