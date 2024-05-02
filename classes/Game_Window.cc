#include "Game_Window.h"

Game_Window::Game_Window() {
    getmaxyx(stdscr, _max_y, _max_x);
}

bool Game_Window::init() {
    if (_max_y < HEIGHT) {
        std::cout << "Your window is too small. (Minimum window height: " << HEIGHT;
        std::cout << ". Your window height: " << _max_y << ")" << std::endl;
        return false;
    }

    _game_window = newwin(HEIGHT, WIDTH, ((_max_y / 2 ) - (HEIGHT / 2)), ((_max_x / 2) - (WIDTH / 2)));
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

void Game_Window::get_spaces(int & y, int & x) {
    while ((mvwinch(_game_window, y = rand() % HEIGHT, x = rand() % WIDTH)) != ' ');
}

chtype Game_Window::get_input() {
    return wgetch(_game_window);
}

void Game_Window::add_at(int y, int x, chtype character) {
    mvwaddch(_game_window, y, x, character);
}

void Game_Window::add(Drawable drawable) {
    add_at(drawable.gety(), drawable.getx(), drawable.get_icon());
}