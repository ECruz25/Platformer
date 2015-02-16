#include <iostream>
#include "Player.h"

enum KEYS{UP, DOWN, RIGHT, LEFT};

using namespace std;

Player::Player()
{

    event_queue = al_create_event_queue();

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_clear_to_color(al_map_rgb(45,185,227));

    player.push_back(al_load_bitmap("Player/stand01.png"));
    player.push_back(al_load_bitmap("Player/stand02.png"));
    player.push_back(al_load_bitmap("Player/run01.png"));
    player.push_back(al_load_bitmap("Player/run02.png"));
    player.push_back(al_load_bitmap("Player/run03.png"));
    player.push_back(al_load_bitmap("Player/run001.png"));
    player.push_back(al_load_bitmap("Player/run002.png"));
    player.push_back(al_load_bitmap("Player/run003.png"));

    pos_x = 250;
    pos_y = 590;
    count = 0;
    FPS = 60;
    curFrame = 0;
    frameCount = 0;
    frameDelay = 8;
    accelerationY = 0;
    gravity = 400;
    maxFrame = 3;
    done = false;

    al_flip_display();

}

void Player::draw()
{

    al_draw_bitmap(player[0], pos_x, pos_y, 0);

}

void Player::act()
{

        al_draw_bitmap(player[0], pos_x, pos_y, 0);

        ALLEGRO_EVENT ev;

        al_wait_for_event(event_queue, &ev);

        count++;

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
        {

            switch(ev.keyboard.keycode)
            {

            case ALLEGRO_KEY_W:
                keys[UP] = true;
                break;

            case ALLEGRO_KEY_S:
                keys[DOWN] = true;
                break;

            case ALLEGRO_KEY_D:
                keys[RIGHT] = true;
                for(int x = 2; x<5; x++)
                    al_draw_bitmap(player[x], pos_x, pos_y, 0);
                break;

            case ALLEGRO_KEY_A:
                keys[LEFT] = true;
                break;

            }

        }

        else if(ev.type == ALLEGRO_EVENT_KEY_UP)
        {

            switch(ev.keyboard.keycode)
            {

            case ALLEGRO_KEY_W:
                keys[UP] = false;
                break;

            case ALLEGRO_KEY_S:
                keys[DOWN] = false;
                break;

            case ALLEGRO_KEY_D:
                keys[RIGHT] = false;

                break;

            case ALLEGRO_KEY_A:
                keys[LEFT] = false;
                break;

            case ALLEGRO_KEY_ESCAPE:
                done = true;
                break;

            }

        }

        else if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {

            done = true;

        }

        pos_y -= keys[UP] * 3;
        pos_y += keys[DOWN] * 3;
        pos_x -= keys[LEFT] * 3;
        pos_x += keys[RIGHT] * 3;

        al_flip_display();

        al_clear_to_color(al_map_rgb(45,185,227));

}

Player::~Player()
{
    //dtor
}
