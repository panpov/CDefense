#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <ncurses.h>

/**
 * @brief 
 * 
 */
class Game_Window {
private:
    WINDOW * game_window;
    
public:
    Game_Window(/* args */);
    ~Game_Window();
};

Game_Window::Game_Window(/* args */) {
}

Game_Window::~Game_Window() {
}

#endif