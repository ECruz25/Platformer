#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>

#include "ScreenManager.h"
#include "InputManager.h"
#include "SplashScreen.h"
#include "Character.h"
#include "Player.h"
#include "Floor.h"

class GameplayScreen : public GameScreen
{
    public:
        GameplayScreen();
        virtual ~GameplayScreen();
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        Player* player;
        int frame;
        int level;
        Floor floor;
        ALLEGRO_BITMAP* enemy;
        ALLEGRO_BITMAP *background;
    protected:
    private:
};

#endif // GAMEPLAYSCREEN_H
