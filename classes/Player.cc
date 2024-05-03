#include "Player.h"

/**
 * @brief Initializes a player object
 * @param init_x The starting x position of player
 * @param init_y The starting y position of player
*/
Player::Player() {
    _x = WIDTH / 2;
    _y = HEIGHT - 10;
    _icon = 'A';

    _health = STARTING_HEALTH;
    _speed = 1;
    _damage_output = 3;
    _damage_input = 3;
}

/**
 * @brief Changes the position of the player
 * @param new_x The new x position of player
 * @param new_y The new y position of player
*/
void Player::move(int new_x) {
    _x = new_x;
}