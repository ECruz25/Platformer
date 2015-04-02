#include <iostream>
#include <fstream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_native_dialog.h"

//
#include "allegro5/allegro_audio.h"
#include "allegro5/allegro_acodec.h"

#include "ScreenManager.h"
#include "InputManager.h"

using namespace std;

int main() {

    int width = 800;
    int height = 600;

    const float kFPS = 60.0f;
    bool done = false;
    bool redraw = true;

    ALLEGRO_DISPLAY *display;


    ALLEGRO_SAMPLE *sample;

    if(!al_init()){
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
    }

//necesario

    if(!al_install_audio()){
      fprintf(stderr, "failed to initialize audio!\n");
      return -1;
    }

    if(!al_init_acodec_addon()){
      fprintf(stderr, "failed to initialize audio codecs!\n");
      return -1;
    }

    if (!al_reserve_samples(1)){
      fprintf(stderr, "failed to reserve samples!\n");
      return -1;
    }

    sample = al_load_sample( "fight.wav" );

//necesario


    display = al_create_display(width,height);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL,
                                   "failed to initialize allegro!", NULL, NULL);
        return -1;
    }

//    sample = al_load_sample("fight.wav" );

    al_set_window_position(display, 100, 100);

    al_install_keyboard();
    al_install_mouse();

//    al_install_audio(ALLEGRO_AUDIO_DRIVER_AUTODETECT);
//    al_reserve_samples(8);

    al_init_image_addon();
    al_init_acodec_addon();

    al_init_font_addon();
    al_init_ttf_addon();

    al_play_sample(sample, 1, 0, 1, ALLEGRO_PLAYMODE_LOOP,NULL);

    ALLEGRO_TIMER *timer = al_create_timer(1.0f / kFPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_KEYBOARD_STATE keystate;

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    InputManager input;
    ScreenManager::GetInstance().Initialize();
    ScreenManager::GetInstance().LoadContent();

    al_start_timer(timer);

    std::vector<int> keys;

    keys.push_back(ALLEGRO_KEY_DOWN);
    keys.push_back(ALLEGRO_KEY_ESCAPE);

    while(!done)
    {
        ALLEGRO_EVENT ev;
        al_wait_for_event(event_queue, &ev);
        al_get_keyboard_state(&keystate);
//        al_draw_bitmap(image, 160, 565, 0);

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }
        else if(ev.type == ALLEGRO_EVENT_TIMER)
        {
            redraw = true;
        }
        else if (input.IsKeyReleased(ev, keys))
        {
            done = true;
        }

        ScreenManager::GetInstance().Update(ev);

        if(redraw && al_is_event_queue_empty(event_queue))
		{
			redraw = false;

            ScreenManager::GetInstance().Draw(display);

            al_flip_display();
            al_clear_to_color(al_map_rgb(0, 0, 0));
		}

    }
    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_sample(sample);
    al_destroy_event_queue(event_queue);
    return 0;
}
