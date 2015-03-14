#include "LevelOne.h"

LevelOne::LevelOne()
{
    floor = al_load_bitmap("assets/floor.png");
    floor1 = al_load_bitmap("assets/floor_2.png");
    floor2 = al_load_bitmap("assets/floor2.png");

    platform1 = 135;
    platform1_ = 755;
    platform1_top = 565;
    platform1_bottom = 540;

    platform2 = 15;
    platform2_ = 125;
    platform2_top = 490;
    platform2_bottom = 440;

    platform3 = 170;
    platform3_ = 265;
    platform3_top = 390;
    platform3_bottom = 340;

    platform4 = 425;
    platform4_ = 475;
    platform4_top = 490;
    platform4_bottom = 340;

    platform5 = 598;
    platform5_ = 647;
    platform5_top = 390;
    platform5_bottom = 240;

    platform6 = 70;
    platform6_ = 265;
    platform6_top = 290;
    platform6_bottom = 240;

    platform7 = 310;
    platform7_ = 405;
    platform7_top = 290;
    platform7_bottom = 140;

    platform8 = 480;
    platform8_ = 405;
    platform8_top = 290;
    platform8_bottom = 40;
}

void LevelOne::draw(ALLEGRO_DISPLAY* display)
{
    al_draw_bitmap(floor, 450, 368, 0);
    al_draw_bitmap(floor, 622, 268, 0);
    al_draw_bitmap(floor1, -500, 465, 0);
    al_draw_bitmap(floor1, -350, 365, 0);
    al_draw_bitmap(floor1, -450, 265, 0);
    al_draw_bitmap(floor1, -350, 265, 0);
    al_draw_bitmap(floor1, -200, 165, 0);
    al_draw_bitmap(floor2, 160, 565, 0);
    al_draw_bitmap(floor2, 500, 65, 0);
}

bool LevelOne::IsOnSolidGround(int x1, int y1)
{
    if(y1 == platform1_bottom)
    {
        if(x1 > platform1)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == platform2_bottom)
    {
        if(x1 > platform2 && x1 < platform2_)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == platform3_bottom || y1 == platform4_bottom)
    {
        if(x1 > platform3 && x1 < platform3_)
        {
            can_jump = true;
        }
        else if(x1 > platform4 && x1 < platform4_)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == platform5_bottom)
    {
        if(x1 > platform5 && x1 < platform5_)
        {
            can_jump = true;
        }
        else if(x1 > platform6 && x1 < platform6_)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == platform7_bottom)
    {
        if(x1 > platform7 && x1 < platform7_)
        {
            can_jump = true;
        }
        else
        {
            can_jump = false;
        }
    }
    else if(y1 == platform8_bottom)
    {
        if(x1 > platform8)
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

bool LevelOne::TheresRoof(int x1, int y1)
{
    if(x1 > platform2 && x1 < platform2_)
    {
        if(y1 == platform2_top)
        {
            return true;
        }
    }
    else if(x1 > platform6 && x1 < platform6_)
    {
        if(y1 == platform6_top)
        {
            return true;
        }
    }
    else
    {
        return false;
    }
    return false;
}

LevelOne::~LevelOne()
{
    //dtor
}
