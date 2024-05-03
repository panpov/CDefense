#ifndef PLAYER
#define PLAYER

// May not be necessary
#include <ncurses.h>
#include "Game_Window.h"
#include "Drawable.h"

#define STARTING_HEALTH 5

// // Might not need these
// enum Directionals {
//     left,
//     right
// }

class Player : public Drawable {
public:
    Player();
    void boost_health();
    void boost_damage();
    void boost_defense();
    void move(int new_x);
    
private:
    int _health;
    int _speed;
    int _damage_output;
    int _damage_input;
};

#endif // PLAYER