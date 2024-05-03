#ifndef GAME
#define GAME

#include <ncurses.h>
#include <time.h>
#include <stdlib.h>
#include "Game_Window.h"
#include "Player.h"

class Game
{
private:
    Game_Window _window;
    Player _player;
    bool _game_over;

public:
    Game();
    bool valid_window();
    void get_input();
    void update();
    void refresh();
    bool game_over();
};

#endif // GAME