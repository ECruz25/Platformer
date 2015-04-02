#include "Player.h"

Player::Player()
{
    level1 = new LevelOne;
    level2 = new LevelTwo;
    level3 = new LevelThree;

    y = 490;
    x = 680;
    w = 75;
    h = 30;
    floor = 540;
    jumps = 0;
    level = 1;
    jumping = false;
    win = false;
    dead = false;
    frame = 0;
    image = al_load_bitmap("assets/Player/standing/1.png");
}

void Player::draw(ALLEGRO_DISPLAY* display, int level_)
{
    al_draw_bitmap(image, x, y, 0);

    if(!dead)
    {
        if(frame%5==0)
        {
            switch(level_)
            {
                case 1:
                    if(jumping)
                    {
                        if(jumps<3)
                        {
                            if(!won(level_))
                            {
                                if(!level1->TheresRoof(x,y))
                                {
                                    y-=50;
                                    jumps++;
                                }
                                else
                                {
                                    y+=50;
                                    jumps=3;
                                }
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
                break;
                case 2:
                    if(jumping)
                    {
                        if(jumps<3)
                        {
                            if(!won(level_))
                            {
                                if(!level2->TheresRoof(x,y))
                                {
                                    y-=50;
                                    jumps++;
                                }
                                else
                                {
                                    y+=50;
                                    jumps=3;
                                }
                            }
                        }
                        else
                        {
                            jumping = false;

                            if(!level2->IsOnSolidGround(x,y))
                            {
                                y+=50;
                            }
                        }
                        if(y > floor)
                        {
                            jumping = false;
                        }
                    }
                    else if(!level2->IsOnSolidGround(x,y) && !jumping)
                    {
                        y+=50;
                    }
                break;
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


void Player::Draw()
{
}

void Player::act(ALLEGRO_EVENT ev)
{
    cout<<"("<<x<<","<<y<<")"<<endl;

    if(input.IsKeyPressed(ev, ALLEGRO_KEY_SPACE))
    {
        jump();
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_D))
    {
        image = al_load_bitmap("assets/Player/standing/1.png");

        keys[RIGHT] = true;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_A) )
    {
        image = al_load_bitmap("assets/Player/standing/2.png");

        keys[LEFT] = true;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_D))
    {
        keys[RIGHT] = false;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_W))
    {
        y-=5;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_S))
    {
        y+=5;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_A))
    {
        keys[LEFT] = false;
    }

    if(keys[RIGHT])
    {
        if(x > level1->platform1_)
        {
            keys[RIGHT] = false;
        }
        else if(x > level2->platform1_)
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
    y = 240;
    x = 630;
    dead = false;
}

bool Player::won(int level_)
{
    switch(level_)
    {
        case 1:
            if(y == 140 && (x>605 && x<635))
            {
                level = 2;
                y = 490;
                x = 680;
                return true;
            }
        break;
        case 2:
            if(y == 140 && (x>605 && x<635))
            {
                level = 3;
                y = 490;
                x = 680;
                return true;
            }
        break;
        case 3:
            if(y == 140 && (x>605 && x<635))
            {
                win = true;
                return true;
            }
        break;
    }
    return false;
}

Player::~Player()
{
    //dtor
}
