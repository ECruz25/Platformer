#ifndef PLAYER_H
#define PLAYER_H
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include <vector>

#include "InputManager.h"
#include "FileManager.h"

using namespace std;

class Player
{
    private:
        ALLEGRO_BITMAP *player_image;
        pair<float, float> position;
        float move_speed;
        FileManager file_manager;

        vector<vector<string> > attributes;
        vector<vector<string> > contents;

    public:
        Player();
        virtual ~Player();

        void LoadContent();
        void UnloadContent();
        void Update(ALLEGRO_EVENT ev, InputManager input);
        void Draw(ALLEGRO_DISPLAY *display);

    protected:
};

#endif // PLAYER_H
