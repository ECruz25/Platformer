#ifndef FADEANIMATION_H
#define FADEANIMATION_H

#include "Animation.h"

class FadeAnimation : public Animation {
 public:
  FadeAnimation();
  ~FadeAnimation();

  void LoadContent(ALLEGRO_BITMAP *image, std::string text, float position[2]);
  void UnloadContent();
  void Update(InputManager input);
  void SetAlpha(float value);

 private:
  float fade_speed;
  bool increase;
};

#endif // FADEANIMATION_H
