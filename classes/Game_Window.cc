#include "Game_Window.h"

Game_Window::Game_Window() {
    getmaxyx(stdscr, _max_y, _max_x);
    _height = _max_y - (_max_y % 5);
    _width = _height * (float(2) / 3);
    // _width *= 2.25; // make wider
}

bool Game_Window::init(bool window_details) {
    if (_height < MIN_HEIGHT) {
        std::cout << "Your window is too small. (Minimum window height: " << MIN_HEIGHT;
        std::cout << ". Your window height: " << _height << ")" << std::endl;
        return false;
    }

    // Window details
    if (window_details) {
        printw("Max y: %d", _max_y);
        mvprintw(1, 0, "Max x: %d", _max_x);
        mvprintw(2, 0, "Height: %d", _height);
        mvprintw(3, 0, "Width: %d", _width);
    }

    _game_window = newwin(_height, _width, ((_max_y / 2 ) - (_height / 2)), ((_max_x / 2) - (_width / 2)));
    clear();
    refresh();

    return true;
}

void Game_Window::add_border() {
    box(_game_window, 0, 0);
}

void Game_Window::clear() {
    wclear(_game_window);
    add_border();
}

void Game_Window::refresh() {
    wrefresh(_game_window);    
}

void Game_Window::add_at(int y, int x, chtype character) {
    mvwaddch(_game_window, y, x, character);
}

chtype Game_Window::get_input() {
    return wgetch(_game_window);
}