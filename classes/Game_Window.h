#ifndef GAME_WINDOW
#define GAME_WINDOW

#include <ncurses.h>
#include <iostream>

#define MIN_HEIGHT 25

/**
 * @brief 
 * 
 */
class Game_Window {
private:
    WINDOW * _game_window;
    int _max_y, _max_x;
    int _height, _width;
    
public:
    Game_Window();
    bool init(bool window_details);
    void add_border();
    void clear();
    void refresh();
    void add_at(int y, int x, chtype character);
    chtype get_input();
};

#endif // GAME_WINDOW