#include "Player.h"

Player::Player()
{

    level1 = new LevelOne;

//    y = 540;
    y = -110;
    x = 225;
    w = 75;
    h = 30;
    floor = 540;
    jumps = 0;
    jumping = false;
    dead = false;
    frame = 0;
    image = al_load_bitmap("assets/Player/standing/1.png");
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));
//    images.push_back(al_load_bitmap("assets/Player/standing/1.png"));

//    x = 350;
//    y = 540;
//
//    mapa_texturas["left"] = new vector<ALLEGRO_BITMAP*>();
//    mapa_texturas["right"] = new vector<ALLEGRO_BITMAP*>();
//    mapa_texturas["walk_right"] = new vector<ALLEGRO_BITMAP*>();
//    mapa_texturas["walk_left"] = new vector<ALLEGRO_BITMAP*>();
//    mapa_texturas["jumping_right"] = new vector<ALLEGRO_BITMAP*>();
//    mapa_texturas["jumping_left"] = new vector<ALLEGRO_BITMAP*>();
//
//    mapa_texturas["right"]->push_back(al_load_bitmap("assets/Player/standing/1.png"));
//
//    mapa_texturas["left"]->push_back(al_load_bitmap("assets/Player/standing/2.png"));
//
//    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/1.png"));
////    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/2.png"));
////    mapa_texturas["walk_right"]->push_back(al_load_bitmap("assets/Player/run/run/3.png"));
//
//    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/1.png"));
////    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/2.png"));
////    mapa_texturas["walk_left"]->push_back(al_load_bitmap("assets/Player/run/run_left/3.png"));
//
//    mapa_texturas["jumping_right"]->push_back(al_load_bitmap("assets/Player/jump/jump_right/1.png"));
//
//    mapa_texturas["jumping_left"]->push_back(al_load_bitmap("assets/Player/jump/jump_left/1.png"));
//
//    vector_actual_str = "right";
//
//    init(display, characters);
}

void Player::draw(ALLEGRO_DISPLAY* display)
{
    al_draw_bitmap(image, x, y, 0);

    if(!dead)
    {
        if(frame%5==0)
        {
            if(jumping)
            {
                if(jumps<3)
                {
                    if(!level1->TheresRoof(x,y))
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

                    jumping = false;

                    if(!level1->IsOnSolidGround(x,y))
                    {
                        y+=50;
                    }
                }
                if(y > floor)
                {
                    jumping = false;
                }
            }
            else if(!level1->IsOnSolidGround(x,y) && !jumping)
            {
                y+=50;
            }
        }

        if(y>=740)
        {
            dead = true;
        }
    }
    else
    {
        revive();
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
        image = al_load_bitmap("assets/Player/standing/1.png");

        keys[RIGHT] = true;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_A) || input.IsKeyPressed(ev, ALLEGRO_KEY_LEFT))
    {
        image = al_load_bitmap("assets/Player/standing/2.png");

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
    }

    if(keys[RIGHT])
    {
        if(x > level1->platform1_)
        {
            keys[RIGHT] = false;
        }
        else
        {
            x+=5;
        }
    }
    else if(keys[LEFT])
    {
        if(x < 0)
        {
            x = 750;
        }
        else
        {
            x-=5;
        }
    }
}

void Player::jump()
{
    if(level1->IsOnSolidGround(x,y))
    {
        jumps = 0;
        jumping = true;
    }
    else
    {
        jumping = false;
    }
}

void Player::revive()
{

    y = -110;
    x = 225;
    dead = false;
}

//bool Player::IsOnSolidGround(int x1, int y1)
//{
//    if(y1 == level1->platform1_bottom)
//    {
//        if(x1 > level1->platform1)
//        {
//            can_jump = true;
//        }
//        else
//        {
//            can_jump = false;
//        }
//    }
//    else if(y1 == level1->platform2_bottom)
//    {
//         if(x1 > level1->platform2 && x1 < level1->platform2_)
//        {
//            can_jump = true;
//        }
//        else
//        {
//            can_jump = false;
//        }
//    }
//    else if(y1 == level1->platform3_bottom || y1 == level1->platform4_bottom)
//    {
//        if(x1 > level1->platform3 && x1 < level1->platform3_)
//        {
//            can_jump = true;
//        }
//        else if(x1 > level1->platform4 && x1 < level1->platform4_)
//        {
//            can_jump = true;
//        }
//        else
//        {
//            can_jump = false;
//        }
//    }else if(y1 == level1->platform5_bottom)
//    {
//        if(x1 > level1->platform5 && x1 < level1->platform5_)
//        {
//            can_jump = true;
//        }
//        else
//        {
//            can_jump = false;
//        }
//    }
//    else
//    {
//        can_jump = false;
//    }
//
//    return can_jump;
//}
//
//bool Player::TheresRoof(int x1, int y1)
//{
//    if(x1 > level1->platform2 && x1 < level1->platform2_)
//    {
//        if(y1 == level1->platform2_top)
//        {
//            return true;
//        }
//    }
//    else if(x1 > level1->platform3 && x1 < level1->platform3_)
//    {
//
//        if(y1 == level1->platform3_top)
//        {
//            return true;
//        }
//    }
//    else
//    {
//        return false;
//    }
//    return false;
//}

Player::~Player()
{
    //dtor
}
