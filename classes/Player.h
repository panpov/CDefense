#ifndef PLAYER_H
#define PLAYER_H

#include "Game_Window.h"
#include "Drawable.h"
#include "Entity.h"

#define INIT_HP 5
#define INIT_SPD 1
#define PLAYER_ICON 'A'

class Player : public Entity {
public:
    Player();
    Player(int health, int speed);
    
    bool is_empowered();
    void empower(int duration);

private:
    bool _empowered;
    int _empowered_duration;
};

#endif // PLAYER_H