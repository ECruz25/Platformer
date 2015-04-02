#ifndef MENUSCREEN_H
#define MENUSCREEN_H

#include "ScreenManager.h"
#include "InputManager.h"

class MenuScreen : public GameScreen
{
    public:
        MenuScreen();
        MenuScreen(string selected, string unselected, int x, int y);
        vector<MenuScreen*>buttons;
        ALLEGRO_BITMAP* selected;
        ALLEGRO_BITMAP* unselected;
        ALLEGRO_BITMAP* menu_background;
        InputManager input;
        int x;
        int y;
        int option;
        void render();
        bool is_selected;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Select();
        void Unselect();
        void Draw(ALLEGRO_DISPLAY *display);
        virtual ~MenuScreen();
    protected:
    private:
};

#endif // MENUSCREEN_H
