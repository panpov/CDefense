#include "Game.h"

Game::Game() {
    _window.init();
    _game_over = false;
    srand(time(NULL));
}

void Game::get_input() {
    // chtype input = _window.get_input();
}

void Game::update() {
    int y, x;
    _window.get_spaces(y, x);
}

void Game::refresh() {
    _window.refresh();
}

bool Game::game_over() {
    return _game_over;
}