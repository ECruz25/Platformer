#include <iostream>
#include <fstream>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#include "allegro5/allegro_acodec.h"
#include "allegro5/allegro_native_dialog.h"

#include "ScreenManager.h"
#include "InputManager.h"

using namespace std;

int main() {

    int width = 500;
    int height = 650;

    const float kFPS = 60.0f;

    ALLEGRO_DISPLAY *display;

    if(!al_init())
    {
        al_show_native_message_box(NULL, NULL, NULL,
                                   "failed to initialize allegro!", NULL, NULL);
        return -1;
    }

    display = al_create_display(width,height);

    if(!display)
    {
        al_show_native_message_box(NULL, NULL, NULL,
                                   "failed to initialize allegro!", NULL, NULL);
        return -1;
    }

    al_set_window_position(display, 100, 100);

    al_install_keyboard();
    al_install_mouse();

    al_init_image_addon();
    al_init_acodec_addon();

    al_init_font_addon();
    al_init_ttf_addon();

    ALLEGRO_TIMER *timer = al_create_timer(1.0f / kFPS);
    ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
    ALLEGRO_KEYBOARD_STATE keystate;

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_display_event_source(display));

    bool done = false;

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

        if (input.IsKeyReleased(ev, keys))
        {
            done = true;
        }

        if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            done = true;
        }

        ScreenManager::GetInstance().Update(ev);
        ScreenManager::GetInstance().Draw(display);

        al_flip_display();
        al_clear_to_color(al_map_rgb(0, 0, 0));

    }

    al_destroy_display(display);
    al_destroy_timer(timer);
    al_destroy_event_queue(event_queue);

    return 0;
}
