#include "Player.h"

/**
 * @brief Initializes a player object with 0 health and 0 speed
*/
Player::Player() : Entity(0, 0, PLAYER_ICON) {
    _health = 0;
    _speed = 0;
    _empowered = false;
    _empowered_duration = 0;
}

/**
 * @brief Initializes a player object with specified health and speed
 * @param health the specified health
 * @param speed the specified speed
*/
Player::Player(int health, int speed) : Entity(health, speed, PLAYER_ICON) {
    _health = health;
    _speed = speed;
    _empowered = false;
    _empowered_duration = 0;
}

/**
 * @brief Checks if the player is empowered or not (shoots a larger laser)
 * @return true the player is empowered
 * @return false the player is not empowered
 */
bool Player::is_empowered() {
    return _empowered_duration > 0;
}

/**
 * @brief Empowers the player
 * @param choice 0 for not empowered, 1 for empowered
 */
void Player::empower(int duration) {
    _empowered_duration += duration;
}