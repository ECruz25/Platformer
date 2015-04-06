#include "Player.h"

Player::Player()
{
    level1 = new LevelOne;
    level2 = new LevelTwo;
    level3 = new LevelThree;

    dir = 1;

    PrintScore();

    score = 0;

    images_derecha[0] = al_load_bitmap("assets/Player/run/run/1.png");
    images_derecha[1] = al_load_bitmap("assets/Player/run/run/2.png");
    images_derecha[2] = al_load_bitmap("assets/Player/run/run/3.png");

    images_izquierda[0]= al_load_bitmap("assets/Player/run/run_left/1.png");
    images_izquierda[1]= al_load_bitmap("assets/Player/run/run_left/2.png");
    images_izquierda[2]= al_load_bitmap("assets/Player/run/run_left/3.png");

    comma = ",";
    y = 540;
    x = 640;
    w = 75;
    h = 30;
    floor = 540;
    jumps = 0;
    level = 1;
    jumping = false;
    win = false;
    dead = false;
    wifion = true;
    frame = 0;
    image = al_load_bitmap("assets/Player/standing/1.png");
}

void Player::draw(ALLEGRO_DISPLAY* display, int level_)
{
    AddPoints(level_);
    if(keys[LEFT])
    {
        al_draw_bitmap(images_izquierda[curFrame], x, y, 0);
    }
    else if(keys[RIGHT])
    {
        al_draw_bitmap(images_derecha[curFrame], x, y, 0);
    }
    else
    {
        al_draw_bitmap(image, x, y, 0);
    }
    if(wifion)
    {
        switch(level_)
        {
            case 1:
                al_draw_bitmap(level1->wifi, level1->wifix, level1->wifiy, 0);
            break;
            case 2:
                al_draw_bitmap(level2->wifi, level2->wifix, level2->wifiy, 0);
            break;
            case 3:
                al_draw_bitmap(level3->wifi, level3->wifix, level3->wifiy, 0);
            break;
        }
    }
    if(won(level_)){}
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
                case 3:
                    if(jumping)
                    {
                        if(jumps<3)
                        {
                            if(!won(level_))
                            {
                                if(!level3->TheresRoof(x,y))
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

                            if(!level3->IsOnSolidGround(x,y))
                            {
                                y+=50;
                            }
                        }
                        if(y > floor)
                        {
                            jumping = false;
                        }
                    }
                    else if(!level3->IsOnSolidGround(x,y) && !jumping)
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
        dead = true;
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
        keys[RIGHT] = true;
    }
    else if(input.IsKeyPressed(ev, ALLEGRO_KEY_A) )
    {
        keys[LEFT] = true;
    }
    else if(input.IsKeyReleased(ev, ALLEGRO_KEY_D))
    {
        image = al_load_bitmap("assets/Player/standing/1.png");
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
        image = al_load_bitmap("assets/Player/standing/2.png");
        keys[LEFT] = false;
    }
    else if(ev.type == ALLEGRO_EVENT_TIMER)
    {
        if(++frameCount >= frameDelay)
        {
            if(++curFrame >= maxFrame)
                curFrame = 0;

            frameCount = 0;
        }
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
    else if(level2->IsOnSolidGround(x,y))
    {
        jumps = 0;
        jumping = true;
    }
    else if(level3->IsOnSolidGround(x,y))
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
            if(y == level1->laptopy && (x>=level1->laptopx-8 && x<=level1->laptopx+8))
            {
                wifion = true;
                score += 500;
                level = 2;
                y = 540;
                x = 640;
                win = false;
                return win;
            }
        break;
        case 2:
            if(y == level2->laptopy &&  (x>=level2->laptopx-8 && x<=level2->laptopx+8))
            {
                wifion = true;
                score += 500;
                level = 3;
                y = 540;
                x = 640;
                win = false;
                return win;
            }
        break;
        case 3:
            if(y == level3->laptopy &&  (x>=level3->laptopx-8&& x<=level3->laptopx+8))
            {
                score += 500;
                Save();
                win = true;
                return win;
            }
        break;
    }
    return win;
}

void Player::Save()
{
    if(score>score1)
    {
        score3 = score2;
        score2 = score1;
        score1 = score;
    }
    else if(score>score2)
    {
        score3 = score2;
        score2 = score;
    }
    else if(score>score3)
    {
        score3 = score;
    }
    ofstream o("assets/Score.txt");
    o<<score1<<'\n';
    o<<score2<<'\n';
    o<<score3<<'\n';
    o.close();
}

void Player::PrintScore()
{
    ifstream i("assets/Score.txt");
    i>>score1;
    i>>score2;
    i>>score3;
    i.close();
}

void Player::AddPoints(int level_)
{
    switch(level_)
    {
        case 1:
            if(wifion && y == level1->wifiy && (x>=level1->wifix-10 && x<=level1->wifix+10))
            {
                wifion = false;
                score+=100;
            }
        break;
        case 2:
            if(wifion && y == level2->wifiy &&  (x>=level2->wifix-10 && x<=level2->wifix+10))
            {
                wifion = false;
                score+=100;
            }
        break;
        case 3:
            if(wifion && y == level3->wifiy &&  (x>=level3->wifix-10 && x<=level3->wifix+10))
            {
                wifion = false;
                score+=100;
            }
        break;
    }
}

void Player::UnloadContent()
{
    level1->UnloadContent();
}

Player::~Player()
{
    //dtor
}
