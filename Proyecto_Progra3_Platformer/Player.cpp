#include "Player.h"

Player::Player()
{
    level1 = new LevelOne;

    y = -110;
    x = 360;
    w = 75;
    h = 30;
    floor = 540;
    jumps = 0;
    jumping = false;
    dead = false;
    frame = 0;
    image = al_load_bitmap("assets/Player/standing/2.png");
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
                        y += 50;
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
    x = 680;
    dead = false;
}

Player::~Player()
{
    //dtor
}
