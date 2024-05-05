#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <ncurses.h>
#include <iostream>
#include "Drawable.h"

#define HEIGHT 40
#define WIDTH 76

/**
 * @brief 
 * 
 */
class Game_Window {
private:
    WINDOW * _game_window;
    int _max_y, _max_x;
    
public:
    Game_Window();
    bool init();
    void add_border();
    void clear();
    void refresh();
    void print(int y, int x, std::string str);
    WINDOW * get_window();
    void get_spaces(int & y, int & x);
    void get_top_spaces(int & y, int & x);
    chtype get_input();
    void add_at(int y, int x, char character);
    void add(Drawable drawable);
    
};

#endif // GAME_WINDOW