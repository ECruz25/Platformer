#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#include "GameScreen.h"
#include "SplashScreen.h"
#include "TitleScreen.h"
#include "FadeAnimation.h"

class ScreenManager {
 public:
  ~ScreenManager();
  static ScreenManager &GetInstance();
  void Initialize();
  void LoadContent();
  void UnloadContent();
  void Update(ALLEGRO_EVENT ev);
  void Draw(ALLEGRO_DISPLAY *display);
  void AddScreen(GameScreen *screen);
 private:
  ScreenManager();
  ScreenManager(ScreenManager const&);
  void operator = (ScreenManager const&);
  void Transition();
  GameScreen *CurrentScreen, *NewScreen;
  ALLEGRO_BITMAP *transition_image;
  FadeAnimation transition;
  bool start_transition;
};

#endif // SCREENMANAGER_H
