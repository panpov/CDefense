#include "Player_Class.h"

/**
 * @brief Initializes a player object
 * @param init_x The starting x position of player
 * @param init_y The starting y position of player
*/
Player::Player(int init_x, int init_y) {
    _x = init_x;
    _y = init_y;

    _health = HEALTH;
    _speed = 1;
    _damage_output = 3;
    _damage_input = 3;
}

/**
 * @brief Changes the position of the plyaer
 * @param new_x The new x position of player
 * @param new_y The new y position of player
*/
void Player::move(int new_x, int new_y) {
    _x = new_x;
    _y = new_y;
}

void Player::draw() {
    mvprintw(_y, _x, "@");
}