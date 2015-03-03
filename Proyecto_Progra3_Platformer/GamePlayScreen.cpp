#include "GamePlayScreen.h"

GamePlayScreen::GamePlayScreen()
{

}

GamePlayScreen::~GamePlayScreen()
{

}

void GamePlayScreen::LoadContent()
{
    player.LoadContent();
}
void GamePlayScreen::UnloadContent()
{
    GameScreen::UnloadContent();
    player.UnloadContent();
}
void GamePlayScreen::Update(ALLEGRO_EVENT ev)
{
    player.Update(ev, input);
}
void GamePlayScreen::Draw(ALLEGRO_DISPLAY *display)
{
    player.Draw(display);
}
