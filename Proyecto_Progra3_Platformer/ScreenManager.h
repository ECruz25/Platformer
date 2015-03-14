#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "GameScreen.h"
#include "SplashScreen.h"
#include "GameplayScreen.h"
#include "FadeAnimation.h"

class ScreenManager
{
    public:
        virtual ~ScreenManager();
        static ScreenManager &GetInstance();
        void Initialize();
        bool done;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        void AddScreen(GameScreen *screen);
        ScreenManager();
        ScreenManager(ScreenManager const&);
        void operator = (ScreenManager const&);
        void Transition();
        ALLEGRO_BITMAP *transition_image;
        FadeAnimation transition;
        bool start_transition;
        GameScreen *CurrentScreen, *NewScreen;

    private:

};

#endif // SCREENMANAGER_H
