#include "Game_Window.h"

Game_Window::Game_Window() {
    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    _height = max_y - (max_y % 5);
    _width = _height * (float(2) / 3);
    _width -= _width % 5;

    WINDOW * game_window = newwin(_height, _width, ((max_y / 2 ) - (_height / 2)), ((max_x / 2) - (_width / 2)));
    box(game_window, 0, 0);
    wrefresh(game_window);    

    move((max_y / 2) - 10, (max_x / 2) + 10);
    printw("%d", max_y);
    move((max_y / 2) + 10, (max_x / 2) + 10);
    printw("%d", _height);

    move((max_y / 2) - 10, (max_x / 2) - 10);
    printw("%d", max_x);
    move((max_y / 2) + 10, (max_x / 2) - 10);
    printw("%d", _width);
}