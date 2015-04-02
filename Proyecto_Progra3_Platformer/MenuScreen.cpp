#include "MenuScreen.h"

MenuScreen::MenuScreen()
{
}

MenuScreen::MenuScreen(string selected, string unselected, int x, int y)
{
    this->selected = al_load_bitmap(selected.c_str());
    this->unselected = al_load_bitmap(unselected.c_str());
    is_selected = false;
    this->x = x;
    this->y = y;
    option = 1;
}

void MenuScreen::LoadContent()
{
    menu_background = al_load_bitmap("menu_fondo.png");
//    buttons.push_back(new MenuScreen("button1_selected.png","button1_unselected.png", 300, 300));
//    buttons.push_back(new MenuScreen("button2_selected.png","button2_unselected.png", 300, 400));
//    buttons.push_back(new MenuScreen("button3_selected.png","button3_unselected.png", 300, 500));
}

void MenuScreen::render()
{
    al_draw_bitmap(menu_background, 0, 0, 0);

    if(is_selected)
    {
//        al_draw_bitmap(selected, x, y, 0);
    }
    else
    {
//        al_draw_bitmap(unselected, x, y, 0);
    }
}

void MenuScreen::Select()
{
    is_selected = true;
}

void MenuScreen::Unselect()
{
    is_selected = false;
}

void MenuScreen::Draw(ALLEGRO_DISPLAY *display)
{

}

void MenuScreen::UnloadContent()
{

}

void MenuScreen::Update(ALLEGRO_EVENT ev)
{

    al_draw_bitmap(menu_background, 0, 0, 0);


    if(input.IsKeyPressed(ev, ALLEGRO_KEY_DOWN))
    {
        option++;
        if(option > 3)
            option = 3;
    }
    if(input.IsKeyPressed(ev, ALLEGRO_KEY_UP))
    {
        option--;
        if(option < 1)
            option = 1;
    }

    for(int i=0;i<buttons.size();i++)
    {
        buttons[i]->Unselect();
    }
//    buttons[option-1]->Select();
    for(int i=0;i<buttons.size();i++)
    {
        buttons[i]->render();
    }
}

MenuScreen::~MenuScreen()
{
    //dtor
}
