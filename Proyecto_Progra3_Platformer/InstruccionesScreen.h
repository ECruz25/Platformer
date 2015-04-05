#ifndef INSTRUCCIONESSCREEN_H
#define INSTRUCCIONESSCREEN_H

#include "ScreenManager.h"
#include "InputManager.h"
#include "SplashScreen.h"
#include "EndScreen.h"

class InstruccionesScreen : public GameScreen
{
    public:
        InstruccionesScreen();
        ALLEGRO_BITMAP* background;
        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev);
        void Draw(ALLEGRO_DISPLAY *display);
        virtual ~InstruccionesScreen();
    protected:
    private:
};

#endif // INSTRUCCIONESSCREEN_H
