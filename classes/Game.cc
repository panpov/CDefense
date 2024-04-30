#include "Game.h"

Game::Game() {
    _window.init(true);
    _game_over = false;
}

void Game::get_input() {
    // chtype input = _window.get_input();
}

void Game::update() {

}

void Game::refresh() {
    _window.refresh();
}

bool Game::game_over() {
    return _game_over;
}