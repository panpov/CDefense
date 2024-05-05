#ifndef PLAYER
#define PLAYER

// May not be necessary
#include <ncurses.h>
#include "Game_Window.h"
#include "Drawable.h"

#define STARTING_HEALTH 5

class Player : public Drawable {
public:
    Player();
    void boost_health();
    void boost_damage();
    void boost_defense();
    
private:
    int _health;
    int _speed;
    int _damage_output;
};

#endif // PLAYER