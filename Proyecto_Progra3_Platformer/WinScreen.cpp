#include "WinScreen.h"

WinScreen::WinScreen()
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

    font = al_load_ttf_font("assets/fonts/Molot.otf",50,0 );
    background = al_load_bitmap("assets/win_screen.png");
}
void WinScreen::LoadContent()
{

}

void WinScreen::UnloadContent()
{
    al_destroy_font(font);
    al_destroy_bitmap(background);
}

void WinScreen::Update(ALLEGRO_EVENT ev)
{
    if(input.IsKeyPressed(ev, ALLEGRO_KEY_ENTER))
    {
        ScreenManager::GetInstance().AddScreen(new MenuScreen);
    }
}

void WinScreen::Draw(ALLEGRO_DISPLAY *display)
{
    floor.draw(display, 1);

    al_draw_bitmap(background, 0, 0, 0);
    al_draw_text(font, al_map_rgb(0,0,0), 100, 450, 0, "NEW HIGHSCORE: ");
    al_draw_text(font, al_map_rgb(0,0,0), 550, 450, ALLEGRO_ALIGN_LEFT, str_score1.c_str());
}

void WinScreen::PrintScore()
{
    ifstream i("assets/Score.txt");
    i>>score1;
    i>>score2;
    i>>score3;
    i.close();
}

string WinScreen::PrintName()
{
//    string inicial;
//    ifstream n("Nombres.txt");
//    n>>inicial;
//    n.close();
    return "";
}

WinScreen::~WinScreen()
{
    //dtor
}
