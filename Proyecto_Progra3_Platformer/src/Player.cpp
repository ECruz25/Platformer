#include "Player.h"

Player::Player(ALLEGRO_DISPLAY* display,list<Character*> *characters)
{
    mapa_texturas["left"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["walk_right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["walk_left"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["punch_right"] = new vector<ALLEGRO_BITMAP*>();
    mapa_texturas["punch_left"] = new vector<ALLEGRO_BITMAP*>();

    mapa_texturas["right"]->push_back(al_load_bitmap("Player/standing/1.png"));
    mapa_texturas["right"]->push_back(al_load_bitmap("Player/standing/2.png"));
    mapa_texturas["right"]->push_back(al_load_bitmap("Player/standing/3.png"));
    mapa_texturas["right"]->push_back(al_load_bitmap("Player/standing/4.png"));

    mapa_texturas["left"]->push_back(al_load_bitmap("Player/standing_left/1.png"));
    mapa_texturas["left"]->push_back(al_load_bitmap("Player/standing_left/2.png"));
    mapa_texturas["left"]->push_back(al_load_bitmap("Player/standing_left/3.png"));
    mapa_texturas["left"]->push_back(al_load_bitmap("Player/standing_left/4.png"));

    mapa_texturas["walk_right"]->push_back(al_load_bitmap("Player/walk/1.png"));
    mapa_texturas["walk_right"]->push_back(al_load_bitmap("Player/walk/2.png"));
    mapa_texturas["walk_right"]->push_back(al_load_bitmap("Player/walk/3.png"));
    mapa_texturas["walk_right"]->push_back(al_load_bitmap("Player/walk/4.png"));
    mapa_texturas["walk_right"]->push_back(al_load_bitmap("Player/walk/5.png"));

    mapa_texturas["walk_left"]->push_back(al_load_bitmap("Player/walk_left/1.png"));
    mapa_texturas["walk_left"]->push_back(al_load_bitmap("Player/walk_left/2.png"));
    mapa_texturas["walk_left"]->push_back(al_load_bitmap("Player/walk_left/3.png"));
    mapa_texturas["walk_left"]->push_back(al_load_bitmap("Player/walk_left/4.png"));
    mapa_texturas["walk_left"]->push_back(al_load_bitmap("Player/walk_left/5.png"));

    mapa_texturas["punch_right"]->push_back(al_load_bitmap("Player/punch/1.png"));
    mapa_texturas["punch_right"]->push_back(al_load_bitmap("Player/punch/2.png"));
    mapa_texturas["punch_right"]->push_back(al_load_bitmap("Player/punch/3.png"));

    mapa_texturas["punch_left"]->push_back(al_load_bitmap("Player/punch_left/1.png"));
    mapa_texturas["punch_left"]->push_back(al_load_bitmap("Player/punch_left/2.png"));
    mapa_texturas["punch_left"]->push_back(al_load_bitmap("Player/punch_left/3.png"));

    eventQueue = al_create_event_queue();

    al_install_keyboard();
    al_register_event_source(eventQueue, al_get_keyboard_event_source());


    vector_actual_str = "right";

    init(display, characters);
}

void Player::act()
{

    al_wait_for_event(eventQueue, &event);


    if(event.type == ALLEGRO_KEY_SPACE)
    {
        if(vector_actual_str=="walk_right" || vector_actual_str=="right")
        {
            setAnimacion("punch_right");
        }

        if(vector_actual_str=="walk_left" || vector_actual_str=="left")
        {
            setAnimacion("punch_left");
        }
    }
    if(event.type == ALLEGRO_KEY_W)
    {
        y--;
    }
    else if(event.type == ALLEGRO_KEY_S)
    {
        y++;
    }

    if(event.type == ALLEGRO_KEY_D)
    {
        x++;
        setAnimacion("walk_right");
    }
    else if(event.type == ALLEGRO_KEY_A)
    {
        x--;
        setAnimacion("walk_left");
    }
    else
    {
        if(vector_actual_str == "walk_right")
            vector_actual_str = "right";

        if(vector_actual_str == "walk_left")
            vector_actual_str = "left";
    }

}

Player::~Player()
{
    //dtor
}
