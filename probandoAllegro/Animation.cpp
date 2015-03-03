#include "Animation.h"

Animation::Animation() {
//ctor
}

Animation::~Animation() {
//dtor
}

void Animation::LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2])
{
    this->image = image;
    this->text = text;
    this->position[0] = position[0];
    this->position[1] = position[1];
    alpha = 255;
    font = al_load_font("arial.ttf", 30, NULL);
    source_rect = image;
    is_active = false;
}

void Animation::UnloadContent()
{
    al_destroy_bitmap(image);
    al_destroy_bitmap(source_rect);
    al_destroy_font(font);
    alpha = NULL;
    position[0] = position[1] = NULL;
}

void Animation::Update(InputManager input)
{

}

void Animation::Draw(ALLEGRO_DISPLAY *display)
{
    if (source_rect != NULL)
    {
        al_draw_tinted_bitmap(source_rect, al_map_rgba(0, 0, 0, alpha),
                                position[0], position[1], NULL);
    } else if (image != NULL)
    {
        al_draw_tinted_bitmap(image, al_map_rgba(0, 0, 0, alpha),
                                position[0], position[1], NULL);
    }
    if (text != "")
    {
        al_draw_text(font, al_map_rgba(255, 0, 0, alpha), position[0],
                      position[1], NULL, text.c_str());
    }
}

void Animation::SetAlpha(float alpha)
{
    this->alpha = alpha;
}

void Animation::SetIsActive(bool value)
{
    is_active = value;
}

float Animation::GetAlpha()
{
    return alpha;
}

bool Animation::GetIsActive()
{
    return is_active;
}

