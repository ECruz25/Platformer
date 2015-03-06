#pragma once

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <allegro5/allegro.h>
#include <allegro5/keyboard.h>
#include <vector>

using namespace std;

class InputManager
{
    public:
        InputManager();
        ~InputManager();
        bool IsKeyPressed(ALLEGRO_EVENT ev, int key);
        bool IsKeyPressed(ALLEGRO_EVENT ev, vector<int> keys);
        bool IsKeyReleased(ALLEGRO_EVENT ev, int key);
        bool IsKeyReleased(ALLEGRO_EVENT ev, vector<int> keys);
        ALLEGRO_KEYBOARD_STATE keystate;
    private:
};

#endif // INPUTMANAGER_H
