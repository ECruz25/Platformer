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
    mapa_texturas["punch_right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["punch_left"] = new vector<ALLEGRO_BITMAP*>();

    mapa_texturas["right"]->push_back(al_load_bitmap("assets/Player/standing/1.png"));

    mapa_texturas["left"]->push_back(al_load_bitmap("assets/Player/standing/2.png"));

    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/1.png"));
    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/2.png"));
    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/3.png"));

    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/1.png"));
    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/2.png"));
    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/3.png"));

//    mapa_texturas["punch_right"]->push_back(al_load_bitmap("Player/punch/1.png"));
//    mapa_texturas["punch_right"]->push_back(al_load_bitmap("Player/punch/2.png"));
//    mapa_texturas["punch_right"]->push_back(al_load_bitmap("Player/punch/3.png"));

//    mapa_texturas["punch_left"]->push_back(al_load_bitmap("Player/punch_left/1.png"));
//    mapa_texturas["punch_left"]->push_back(al_load_bitmap("Player/punch_left/2.png"));
//    mapa_texturas["punch_left"]->push_back(al_load_bitmap("Player/punch_left/3.png"));

    vector_actual_str = "right";

    init(display, characters);

}

void Player::act(ALLEGRO_EVENT ev)
{
    if(input.IsKeyPressed(ev, ALLEGRO_KEY_SPACE))
    {
        if(vector_actual_str=="walk_right" || vector_actual_str=="right")
        {
//            setAnimacion("punch_right");
        }
        if(vector_actual_str=="walk_left" || vector_actual_str=="left")
        {
//            setAnimacion("punch_left");
        }
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_W))
    {
        keys[UP] = true;
//        y-=10;
//        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_S) && y < 550)
    {
        keys[DOWN] = true;
//        y+=10;
//        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_D)&& x < 760)
    {
        keys[RIGHT] = true;
//        x+=10;
//        cout<<"("<<x<<","<<y<<")"<<endl;
//        setAnimacion("walk_right");
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_A) && x > -10)
    {
        keys[LEFT] = true;
//        x-=10;
//        cout<<"("<<x<<","<<y<<")"<<endl;
//        setAnimacion("walk_left");
    }
    if(input.IsKeyReleased(ev, ALLEGRO_KEY_W))
    {
        keys[UP] = false;
//        y-=10;
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_S) && y < 550)
    {
        keys[DOWN] = false;
//        y+=10;
        cout<<"("<<x<<","<<y<<")"<<endl;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_D)&& x < 760)
    {
        keys[RIGHT] = false;
//        x+=10;
//        cout<<"("<<x<<","<<y<<")"<<endl;
//        setAnimacion("walk_right");
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_A) && x > -10)
    {
        keys[LEFT] = false;
//        x-=10;
//        cout<<"("<<x<<","<<y<<")"<<endl;
//        setAnimacion("walk_left");
    }
    else
    {
        if(vector_actual_str == "walk_right")
            vector_actual_str = "right";

        if(vector_actual_str == "walk_left")
            vector_actual_str = "left";
    }
//
//    x+=(keys[RIGHT] * 10);
//    x-=(keys[LEFT] * 10);
//    y+=(keys[DOWN] * 10);
//    y-=(keys[UP] * 10);

    if(keys[RIGHT])
    {
        x+=3;
        setAnimacion("walk_right");
    }
    else if(keys[LEFT])
    {
        x-=3;
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
//    al_clear_to_color(al_map_rgb(0,0,0));
}

void Player::Movement()
{

}

Player::~Player()
{
    //dtor
}


