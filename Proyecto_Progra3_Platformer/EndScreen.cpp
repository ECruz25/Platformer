#include "EndScreen.h"

EndScreen::EndScreen()
{
    al_init_font_addon();
    al_init_ttf_addon();

    PrintScore();

    oss1 << score1;
    str_score1 = oss1.str();
    oss2 << score2;
    str_score2 = oss2.str();
    oss3 << score3;
    str_score3 = oss3.str();

    font = al_load_ttf_font("assets/fonts/Monaco.ttf",50,0 );
    background = al_load_bitmap("assets/game-over.png");
}
void EndScreen::LoadContent()
{

}

void EndScreen::UnloadContent()
{
    al_destroy_font(font);
    al_destroy_bitmap(background);
}

void EndScreen::Update(ALLEGRO_EVENT ev)
{
    if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen(new MenuScreen);
    }
}

void EndScreen::Draw(ALLEGRO_DISPLAY *display)
{
    floor.draw(display, 1);

    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(255,255,255), 200, 150, 0, "Score: ");
    al_draw_text(font, al_map_rgb(255,255,255), 380, 150, ALLEGRO_ALIGN_LEFT, str_score1.c_str());
    al_draw_text(font, al_map_rgb(255,255,255), 380, 200, ALLEGRO_ALIGN_LEFT, str_score2.c_str());
    al_draw_text(font, al_map_rgb(255,255,255), 380, 250, ALLEGRO_ALIGN_LEFT, str_score3.c_str());
}

void EndScreen::PrintScore()
{
    ifstream i("Score.txt");
    i>>score1;
    i>>score2;
    i>>score3;
    i.close();
}

string EndScreen::PrintName()
{
//    string inicial;
//    ifstream n("Nombres.txt");
//    n>>inicial;
//    n.close();
    return "";
}

EndScreen::~EndScreen()
{
    //dtor
}
