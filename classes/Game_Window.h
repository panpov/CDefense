#ifndef GAME_WINDOW_H
#define GAME_WINDOW_H

#include <ncurses.h>
#include <iostream>
#include "Drawable.h"
#include "Time.h"

#define HEIGHT 40
#define WIDTH 76
#define TIMEOUT 30

class Game_Window {
private:
    WINDOW * _game_window;
    int _max_y, _max_x;
    int _timeout;
    
public:
    Game_Window();
    bool init();
    void add_border();
    void clear();
    void refresh();
    
    WINDOW * get_window();
    void get_rand_point(int & y, int & x);
    chtype get_input();

    void print(int y, int x, std::string str);
    void add_at(int y, int x, char character);
    void add(Drawable drawable);
    
    chtype menu();
    void pause();
    void lose_screen();
    void win_screen();
};

#endif // GAME_WINDOW_H