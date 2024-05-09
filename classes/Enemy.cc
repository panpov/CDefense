#include "Enemy.h"

/**
* @brief Creates a default Enemy object
*/
Enemy::Enemy() : Entity(0, 0, ENEMY_ICON) {
}

/**
* @brief Creates an Enemy object with specified health, speed, and icon
* @param health the initial health of the Enemy
* @param speed the speed of the Enemy
* @param icon the char representation of the Enemy
*/
Enemy::Enemy(int health, int speed, chtype icon) : \
       Entity(health, speed, icon) {
}

/**
* @brief Moves this enemy downward
*/
void Enemy::move() {
    _y += _speed;
}