#ifndef PLAYER
#define PLAYER

// May not be necessary
#include <ncurses.h>

// Concerns and uncertainties:
// How do we set the player as the thing ncruses is moving around?
// How do we detect when a projectile hits the player? Hitboxes?
// 
class Player {
public:
    Player();
    ~Player();
    void boost_health();
    void boost_damage();
    void boost_defense();
    

private:
    int _health;
    int _speed;
    int _damage_output;
    int _damage_input;
};

#endif // PLAYER