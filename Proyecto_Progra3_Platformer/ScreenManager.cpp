#include "ScreenManager.h"

ScreenManager &ScreenManager::GetInstance()
{
    static ScreenManager instance;
    return instance;
}

ScreenManager::ScreenManager()
{
//ctor
}

ScreenManager::~ScreenManager()
{
//dtor
}

void ScreenManager::AddScreen(GameScreen *screen)
{

    CurrentScreen->UnloadContent();
    delete CurrentScreen;
    CurrentScreen = screen;
    CurrentScreen->LoadContent();

//    transition.SetAlpha(0);
//    start_transition = true;
//    NewScreen = screen;
}

void ScreenManager::Initialize()
{
    CurrentScreen = new GameplayScreen;
}

void ScreenManager::LoadContent()
{
    CurrentScreen->LoadContent();
    transition_image = al_load_bitmap("transition_image.png");
    float position[2] = {0, 0};
    transition.LoadContent(transition_image, "", position);
    start_transition = false;
}

void ScreenManager::UnloadContent()
{
    al_destroy_bitmap(transition_image);
}
void ScreenManager::Update(ALLEGRO_EVENT ev)
{
    if (!start_transition)
    {
        CurrentScreen->Update(ev);
    }
    else
    {
        Transition();
    }
}

void ScreenManager::Draw(ALLEGRO_DISPLAY *display)
{
    CurrentScreen->Draw(display);

    if (start_transition)
    {
        transition.Draw(display);
    }
}

void ScreenManager::Transition()
{

    transition.Update(CurrentScreen->GetInput());

    if (transition.GetAlpha() >= 255)
    {
        transition.SetAlpha(255);
        CurrentScreen->UnloadContent();
        delete CurrentScreen;
//        CurrentScreen = NewScreen;
//        CurrentScreen->LoadContent();
        al_rest(1.0);
    }
}

