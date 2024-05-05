#include "Player.h"

/**
 * @brief Initializes a player object
 * @param init_x The starting x position of player
 * @param init_y The starting y position of player
*/
Player::Player() {
    _x = WIDTH / 2;
    _y = HEIGHT - (HEIGHT / 4);
    _icon = 'A';

    _health = STARTING_HEALTH;
    _speed = 1;
    _damage_output = 3;
}