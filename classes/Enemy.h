#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

#define ENEMY_ICON 'W'

class Enemy : public Entity {
public:
    Enemy();
    Enemy(int health, int speed, chtype icon = ENEMY_ICON);
    void move();
};

#endif // ENEMY_H