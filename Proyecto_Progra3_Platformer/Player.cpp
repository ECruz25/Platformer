#include "Player.h"

Player::Player()
{

}

Player::Player(ALLEGRO_DISPLAY* display,list<Character*> *characters)
{
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


//    if(frame%100==0)
//    {
    if(jumping)
    {
       al_draw_bitmap(textura_actual_temp, x, y, 0);

        if(frame%5==0)
        {
            if(jumps<3)
            {
                y-=50;
                jumps++;
             }
            else
            {
                y+=50;
            }
            if(y >= floor)
            {
                jumping = false;
            }
        }
    }
    textura_actual_int++;
    if(textura_actual_int>=(*vector_textura_actual_temp).size())
    {

        al_draw_bitmap(textura_actual_temp, x, y, 0);

        textura_actual_int=0;
        if(vector_actual_str != "walk_right" && vector_actual_str != "walk_left")
        {
            if(vector_actual_str == "punch_right")
                setAnimacion("right");
            if(vector_actual_str == "punch_left")
                setAnimacion("left");
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
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_W))
    {
//        jump();
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_S) && y < 550)
    {
//        jump();
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_D))
    {
        keys[RIGHT] = true;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_A))
    {
        keys[LEFT] = true;
    }
    if(input.IsKeyReleased(ev, ALLEGRO_KEY_W))
    {


    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_S))
    {
        keys[DOWN] = false;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_D))
    {
        keys[RIGHT] = false;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_A))
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
        x+=5;
        setAnimacion("walk_right");
    }
    else if(keys[LEFT])
    {
        if(x < -10)
        {
            keys[LEFT] = false;
        }
        x-=5;
        setAnimacion("walk_left");
    }
    else if(keys[DOWN])
    {
        y+=3;
    }
    else if(keys[UP])
    {
        y-=3;
    }
}

void Player::Movement()
{

}

void Player::jump()
{
    if(vector_actual_str == "walk_right" || vector_actual_str == "right")
    {
//        tempo = vector_actual_str;
        vector_actual_str = "jumping_right";
    }

    if(vector_actual_str == "walk_left" || vector_actual_str == "left")
    {
//        tempo = vector_actual_str;
        vector_actual_str = "jumping_left";
    }

    cout<<"jumping"<<endl;
    jumps = 0;
    floor = y;
    jumping = true;
}

Player::~Player()
{
    //dtor
}


