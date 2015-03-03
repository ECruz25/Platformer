#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <allegro5/allegro.h>

#include "InputManager.h"
#include "FileManager.h"

class GameScreen
{
    public:
        GameScreen();
        ~GameScreen();
        virtual void LoadContent();
        virtual void UnloadContent();
        virtual void Update(ALLEGRO_EVENT ev);
        virtual void Draw(ALLEGRO_DISPLAY *display);

        InputManager GetInput();

    protected:
        InputManager input;
        vector<vector<string> > attributes;
        vector<vector<string> > contents;
        FileManager file_manager;
};

#endif // GAMESCREEN_H
