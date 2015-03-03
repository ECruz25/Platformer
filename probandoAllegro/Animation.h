#ifndef ANIMATION_H
#define ANIMATION_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>

#include "InputManager.h"

using namespace std;

class Animation
{
    public:
        Animation();
        ~Animation();

        virtual void LoadContent(ALLEGRO_BITMAP *image, string text, float position[2]);
        virtual void UnloadContent();
        virtual void Update(InputManager input);
        void Draw(ALLEGRO_DISPLAY *display);
        void SetIsActive(bool value);
        virtual void SetAlpha(float value);
        float GetAlpha();
        bool GetIsActive();

    protected:
        ALLEGRO_BITMAP *image, *source_rect;
        ALLEGRO_FONT *font;
        std::string text;
        float position[2];
        float alpha;
        bool is_active;
};

#endif // ANIMATION_H
