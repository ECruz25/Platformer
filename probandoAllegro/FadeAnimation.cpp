#include "FadeAnimation.h"

FadeAnimation::FadeAnimation()
{
  //ctor
}

FadeAnimation::~FadeAnimation()
{
  //dtor
}

void FadeAnimation::LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2]) {
  Animation::LoadContent(image, text, position);
  fade_speed = 1.0f;
  increase = false;
}


void FadeAnimation::UnloadContent() {
  Animation::UnloadContent();
  fade_speed = NULL;
}

void FadeAnimation::Update(InputManager input) {
  if (is_active) {
    if (!increase) {
      alpha -= fade_speed;
    } else {
      alpha += fade_speed;
    }
    if (alpha <= 0) {
      alpha = 0;
      increase = true;
    } else if (alpha >= 255) {
      alpha = 255;
      increase = false;
    }
  } else {
    alpha = 255;
  }
}

void FadeAnimation::SetAlpha(float value) {
  alpha = value;
  if (alpha == 0) {
    increase = true;
  } else if (alpha == 255) {
    increase = false;
  }
}

