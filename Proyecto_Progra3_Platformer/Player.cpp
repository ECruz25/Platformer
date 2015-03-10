#include "Player.h"

Player::Player()
{

}

Player::Player(ALLEGRO_DISPLAY* display,list<Character*> *characters)
{
    x = 350;
    y = 540;
    floor = 540;
    jumps = 0;
    jumping = false;

    mapa_texturas["left"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["walk_right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["walk_left"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["jumping_right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["jumping_left"] = new vector<ALLEGRO_BITMAP*>();

    mapa_texturas["right"]->push_back(al_load_bitmap("assets/Player/standing/1.png"));

    mapa_texturas["left"]->push_back(al_load_bitmap("assets/Player/standing/2.png"));

    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/1.png"));
//    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/2.png"));
//    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/3.png"));

    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/1.png"));
//    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/2.png"));
//    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/3.png"));

    mapa_texturas["jumping_right"]->push_back(al_load_bitmap("assets/Player/jump/jump_right/1.png"));

    mapa_texturas["jumping_left"]->push_back(al_load_bitmap("assets/Player/jump/jump_left/1.png"));

    vector_actual_str = "right";

    init(display, characters);
}

void Player::draw(ALLEGRO_DISPLAY* display)
{
    vector<ALLEGRO_BITMAP*> *vector_textura_actual_temp = mapa_texturas[vector_actual_str];
    ALLEGRO_BITMAP* textura_actual_temp = (*vector_textura_actual_temp)[textura_actual_int];
    al_draw_bitmap(textura_actual_temp, x, y, 0);
    if(frame%5==0)
    {
        if(jumping)
        {
            if(jumps<3)
            {
                if(!TheresRoof(x,y))
                {
                    y-=50;
                    jumps++;
                }
                else
                {
                    y = 490;
                    jumps=3;
                }
            }
            else
            {
                if(!IsOnSolidGround(x,y))
                {
                    y+=50;
                }
            }
            if(y >= floor)
            {
                jumping = false;
            }
        }
        else if(!IsOnSolidGround(x,y) && !jumping)
        {
            y+=50;
        }
    }
    frame++;
}

void Player::act(ALLEGRO_EVENT ev)
{
    cout<<"("<<x<<","<<y<<")"<<endl;

    if(input.IsKeyPressed(ev, ALLEGRO_KEY_SPACE))
    {
        jump();
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_D) || input.IsKeyPressed(ev, ALLEGRO_KEY_RIGHT))
    {
        keys[RIGHT] = true;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_A) || input.IsKeyPressed(ev, ALLEGRO_KEY_LEFT))
    {
        keys[LEFT] = true;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_D) || input.IsKeyPressed(ev, ALLEGRO_KEY_RIGHT))
    {
        keys[RIGHT] = false;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_A) || input.IsKeyPressed(ev, ALLEGRO_KEY_LEFT))
    {
        keys[LEFT] = false;
    }
    else
    {
        if(vector_actual_str == "walk_right")
            vector_actual_str = "right";

        if(vector_actual_str == "walk_left")
            vector_actual_str = "left";
    }

    if(keys[RIGHT])
    {
        if(x > 750)
        {
            keys[RIGHT] = false;
        }
        else
        {
            x+=5;
            setAnimacion("walk_right");
        }
    }
    else if(keys[LEFT])
    {
        if(x < 0)
        {
            keys[LEFT] = false;
        }
        else
        {
            x-=5;
            setAnimacion("walk_left");
        }
    }
}

void Player::jump()
{
    if(IsOnSolidGround(x,y))
    {
        if(vector_actual_str == "walk_right" || vector_actual_str == "right")
        {
            temp = vector_actual_str;
        }

        if(vector_actual_str == "walk_left" || vector_actual_str == "left")
        {
            temp = vector_actual_str;
        }
        jumps = 0;
        jumping = true;
    }
    else
    {
        jumping = false;
    }
}

bool Player::IsOnSolidGround(int x1, int y1)
{
    if(y1 == 540)
    {
        if(x1 > 135)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == 440)
    {
         if(x1 > 15 && x1 < 120)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == 340)
    {
        if(x1 > 160 && x1 < 265)
        {
            can_jump = true;
        }
        else if(x1 > 425 && x1 < 475)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else
    {
        can_jump = false;
    }

    return can_jump;
}

bool Player::TheresRoof(int x1, int y1)
{
    if(x1 > 15 && x1 < 120)
    {
        if(y1 == 540)
        {
            return true;
        }
    }
    else if(x1 > 160 && x1 < 265)
    {
        if(y1 == 390)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}


Player::~Player()
{
    //dtor
}


