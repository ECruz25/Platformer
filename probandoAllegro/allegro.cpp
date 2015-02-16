#include <allegro5\allegro.h>
#include <allegro5\allegro_primitives.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

//GLOBALS==============================
const int WIDTH = 800;
const int HEIGHT = 400;
enum KEYS{UP, DOWN, LEFT, RIGHT, SPACE};
bool keys[5] = {false, false, false, false, false};
enum IDS{PLAYER};

struct Player
{
 int ID;
 int x;
 int y;
 int height;
 int width;
 int speed;
};

void InitPlayer(Player &player);
void DrawPlayer(Player &player);

void MovePlayerRight(Player &player);
void MovePlayerLeft(Player &player);
void MovePlayerUp(Player &player);
void MovePlayerDown(Player &player);
int main(void)
{
 //primitive variable
 const int FPS = 60;
 bool done = false;
 bool redraw = true;

//object variables
 Player player;

//Allegro variables
 ALLEGRO_DISPLAY *display = NULL;
 ALLEGRO_EVENT_QUEUE *event_queue = NULL;
 ALLEGRO_TIMER *timer = NULL;
 ALLEGRO_FONT *font18 = NULL;

//Initialization Functions
 if(!al_init()) //initialize Allegro
 return -1;

display = al_create_display(WIDTH, HEIGHT); //create our display object

if(!display) //test display object
 return -1;

//Allegro Module Init
 al_init_primitives_addon();
 al_install_keyboard();
 al_init_font_addon();
 al_init_ttf_addon();

event_queue = al_create_event_queue();
 timer = al_create_timer(1.0 / FPS);

al_register_event_source(event_queue, al_get_keyboard_event_source());
 al_register_event_source(event_queue, al_get_display_event_source(display));
 al_register_event_source(event_queue, al_get_timer_event_source(timer));

al_start_timer(timer);

//Game Init
 InitPlayer(player);

while(!done)
 {
 ALLEGRO_EVENT ev;
 al_wait_for_event(event_queue, &ev);
 if(ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
 {
 done = true;
 }
 else if(ev.type == ALLEGRO_EVENT_TIMER)
 {
 redraw = true;
 if(keys[RIGHT])
 MovePlayerRight(player);
 if(keys[LEFT])
 MovePlayerLeft(player);
 if(keys[UP])
 MovePlayerUp(player);
 if(keys[DOWN])
 MovePlayerDown(player);
 }
 else if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
 {
 switch(ev.keyboard.keycode)
 {
 case ALLEGRO_KEY_ESCAPE:
 done = true;
 break;
 case ALLEGRO_KEY_UP:
 keys[UP] = true;
 break;
 case ALLEGRO_KEY_DOWN:
 keys[DOWN] = true;
 break;
 case ALLEGRO_KEY_RIGHT:
 keys[RIGHT] = true;
 break;
 case ALLEGRO_KEY_LEFT:
 keys[LEFT] = true;
 break;
 case ALLEGRO_KEY_SPACE:
 keys[SPACE] = true;
 break;

}
 }
 else if(ev.type == ALLEGRO_EVENT_KEY_UP)
 {
 switch(ev.keyboard.keycode)
 {
 case ALLEGRO_KEY_UP:
 keys[UP] = false;
 break;
 case ALLEGRO_KEY_DOWN:
 keys[DOWN] = false;
 break;
 case ALLEGRO_KEY_RIGHT:
 keys[RIGHT] = false;
 break;
 case ALLEGRO_KEY_LEFT:
 keys[LEFT] = false;
 break;
 case ALLEGRO_KEY_SPACE:
 keys[SPACE] = false;
 break;
 }
 }

&nbsp;

// Draw stuff to screen
 if(redraw && al_is_event_queue_empty(event_queue))
 {
 redraw = false;
 DrawPlayer(player);
 al_flip_display();
 al_clear_to_color(al_map_rgb(0,0,0));
 }

}
}

void InitPlayer(Player &player)
{
 player.x = 20;
 player.y = HEIGHT /2;
 player.height = 4;
 player.width = 4;

 player.speed = 1;
 player.ID = PLAYER;
}

void DrawPlayer(Player &player)
{
 al_draw_filled_rectangle(player.x, player.y, player.x+player.width, player.y+player.height, al_map_rgb(255, 0, 0));
}

void MovePlayerRight(Player &player) {
 player.x += player.speed;
}
void MovePlayerLeft(Player &player) {
 player.x -= player.speed;
}

void MovePlayerUp(Player &player) {
 player.y -= player.speed;
}

void MovePlayerDown(Player &player) {
 player.y += player.speed;
}
