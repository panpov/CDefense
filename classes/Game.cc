#include "Game.h"

Game::Game() {
    _game_over = false;
    srand(time(NULL));
}

bool Game::valid_window() {
    return _window.init();
}

void Game::get_input() {
    // chtype input = _window.get_input();
}

void Game::update() {
    int y, x;
    _window.get_top_spaces(y, x);
    _window.add(Drawable(y, x, 'X'));
    _window.add(_player);
}

void Game::refresh() {
    _window.refresh();
}

bool Game::game_over() {
    return _game_over;
}