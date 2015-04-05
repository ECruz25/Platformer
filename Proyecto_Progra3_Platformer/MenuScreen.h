#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include <vector>

#include "ScreenManager.h"
#include "InputManager.h"

class MenuScreen : public GameScreen
{
    public:
        MenuScreen();
        ALLEGRO_BITMAP* title[2];
        const int maxFrame = 2;
        int curFrame = 0;
        int frameCount = 0;
        int frameDelay = 10;
        ALLEGRO_BITMAP* menu_background;
        InputManager input;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        virtual ~MenuScreen();
    protected:
    private:
};

#endif // MENUSCREEN_H
