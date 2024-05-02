#ifndef PLAYER
#define PLAYER

// May not be necessary
#include <ncurses.h>
#include "Drawable.h"

#define HEALTH 5

class Player : public Drawable {
public:
    Player(int y, int x);
    void boost_health();
    void boost_damage();
    void boost_defense();
    void move(int new_x, int new_y);
    void draw();

private:
    int _health;
    int _speed;
    int _damage_output;
    int _damage_input;
};

#endif // PLAYER