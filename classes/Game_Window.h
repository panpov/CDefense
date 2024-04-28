#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <ncurses.h>

/**
 * @brief 
 * 
 */
class Game_Window {
private:
    WINDOW * _game_window;
    int _height;
    int _width;
    
public:
    Game_Window();
};

#endif