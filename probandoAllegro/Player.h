#ifndef PLAYER_H
#define PLAYER_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <vector>

//enum KEYS{UP, DOWN, LEFT, RIGHT};

using namespace std;

class Player
{
    public:
        vector<ALLEGRO_BITMAP*>player;
        int pos_x;
        int pos_y;
        int count;
        int FPS;
        int curFrame;
        int frameCount;
        int frameDelay;
        float accelerationY;
        float gravity;
        int maxFrame;
        bool done;
        ALLEGRO_EVENT_QUEUE *event_queue = NULL;
        bool keys[4] = {false,false,false,false};
        Player();
        void draw();
        void act();
        void destroy();
        virtual ~Player();
    protected:
    private:
};

#endif // PLAYER_H
