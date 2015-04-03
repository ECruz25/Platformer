#include "EndScreen.h"

EndScreen::EndScreen()
{
    score = PrintScore();

    al_init_font_addon();
    al_init_ttf_addon();

    oss << score;
    str_score = oss.str();

    font = al_load_ttf_font("assets/fonts/Monaco.ttf",30,0 );
}
void EndScreen::LoadContent()
{

}

void EndScreen::UnloadContent()
{

}

void EndScreen::Update(ALLEGRO_EVENT ev)
{

}

void EndScreen::Draw(ALLEGRO_DISPLAY *display)
{

    floor.draw(display, 1);

    al_clear_to_color(al_map_rgb(50,10,70));
    al_draw_text(font, al_map_rgb(255,255,255), 0, 0, NULL, "Score: ");
    al_draw_text(font, al_map_rgb(255,255,255), 120, 0, ALLEGRO_ALIGN_LEFT, str_score.c_str());

}

//void EndScreen::Save()
//{
//    cout<<"Saving..."<<endl;
//
//    ofstream o("Score.txt");
//    o<<score;
//    o.close();
//}

int EndScreen::PrintScore()
{
    int Score;
    ifstream i("Score.txt");
    i>>Score;
    i.close();
    return Score;
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
