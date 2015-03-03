#ifndef GAMEPLAYSCREEN_H
#define GAMEPLAYSCREEN_H

#include "GameScreen.h"

class GamePlayScreen : public GameScreen
{
    public:
        GamePlayScreen();
        ~GamePlayScreen();

        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);

    protected:
    private:
};

#endif // GAMEPLAYSCREEN_H
