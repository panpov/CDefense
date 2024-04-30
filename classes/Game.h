#ifndef GAME
#define GAME

#include <ncurses.h>
#include "Game_Window.h"

class Game
{
private:
    Game_Window _window;
    bool _game_over;

public:
    Game();
    void get_input();
    void update();
    void refresh();
    bool game_over();
};

#endif // GAME