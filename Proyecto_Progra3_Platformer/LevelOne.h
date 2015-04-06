#ifndef LEVELONE_H
#define LEVELONE_H

#include "Levels.h"

using namespace std;

class LevelOne : public Levels
{
    public:
        LevelOne();
        int platform1;
        int platform1_;
        int platform1_top;
        int platform1_bottom;
        int platform2;
        int platform2_;
        int platform2_bottom;
        int platform2_top;
        int platform3;
        int platform3_;
        int platform3_top;
        int platform3_bottom;
        int platform4;
        int platform4_;
        int platform4_top;
        int platform4_bottom;
        int platform5;
        int platform5_;
        int platform5_top;
        int platform5_bottom;
        int platform6;
        int platform6_;
        int platform6_top;
        int platform6_bottom;
        int platform7;
        int platform7_;
        int platform7_top;
        int platform7_bottom;
        int platform8;
        int platform8_;
        int platform8_top;
        int platform8_bottom;
        int laptopx;
        int laptopy;
        int wifix;
        int wifiy;
        bool wifion;
        bool can_jump;
        ALLEGRO_BITMAP* floor;
        ALLEGRO_BITMAP* floor1;
        ALLEGRO_BITMAP* floor2;
        ALLEGRO_BITMAP* laptop;
        ALLEGRO_BITMAP* background;
        ALLEGRO_BITMAP* wifi;
        void draw(ALLEGRO_DISPLAY* display);
        bool IsOnSolidGround(int x1, int y1);
        bool TheresRoof(int x1, int y1);
        void UnloadContent();
        virtual ~LevelOne();
    protected:
    private:
};

#endif // LEVELONE_H
