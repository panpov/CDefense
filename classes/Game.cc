#include "Game.h"

Game::Game() {
    _game_over = false;
    srand(time(NULL));
}

bool Game::init() {
    return _window.init();
}

void Game::get_input() {
    chtype input = _window.get_input();
    std::string invalid_move = _player.at_edge(_window.get_window());

    _window.add_at(_player.gety(), _player.getx(), ' ');

    if ((input == KEY_UP || input == 'w') && invalid_move.find("u") == std::string::npos)
        _player.move(-1, 0);
    else if ((input == KEY_DOWN || input == 's') && invalid_move.find("d") == std::string::npos)
        _player.move(1, 0);
    else if ((input == KEY_LEFT || input == 'a') && invalid_move.find("l") == std::string::npos)
        _player.move(0, -1);
    else if ((input == KEY_RIGHT || input == 'd') && invalid_move.find("r") == std::string::npos)
        _player.move(0, 1);
}

void Game::update() {
    // int y, x;
    // _window.get_top_spaces(y, x);
    // _window.add(Drawable(y, x, 'X'));
    _window.add(_player);
}

void Game::refresh() {
    _window.refresh();
}

void Game::move_drawable(Drawable drawable, int delta_y, int delta_x) {
    _window.add_at(drawable.gety(), _player.getx(), ' ');
    drawable.move(delta_y, delta_x);
    _window.add(drawable);
}

bool Game::game_over() {
    return _game_over;
}