#include <iostream>
#include "Player.h"

Player::Player()
{

}
Player::~Player()
{
    //dtor
}

void Player::LoadContent()
{
    file_manager.LoadContent("Load/Player.txt", attributes, contents);
    for(int i = 0; i < attributes.size(); i++)
    {
        for(int j = 0; j < attributes[i].size(); j++)
        {
            if(attributes[i][j] == "Image")
            {
                player_image = al_load_bitmap(contents[i][j].c_str());
            }
            else if (attributes[i][j] == "Position")
            {
                stringstream str;
                float position[2];
                str << contents[i][j];
                string value;

                int counter = 0;
                while(getline(str, value, ','))
                {
                    position[counter] = atof(value.c_str());
                    counter++;
                }
                this->position.first = position[0];
                this->position.second = position[1];
            }
        }
    }
}
void Player::UnloadContent()
{
    attributes.clear();
    contents.clear();

}
void Player::Update(ALLEGRO_EVENT ev, InputManager input)
{
    al_destroy_bitmap(player_image);
}
void Player::Draw(ALLEGRO_DISPLAY *display)
{
    al_draw_bitmap(player_image, position.first, position.second, NULL);
}
