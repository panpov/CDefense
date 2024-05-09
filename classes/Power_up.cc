#include "Power_up.h"

/**
* @brief Initializes a powerup object
* @param type the kind of powerup
*/
Power_up::Power_up(int type) : Entity(1, 1, POWER_UP_ICON) {
    _type = type;

    if (type == HEALING)
        set_icon(HEALING_ICON);
    else if (type == EMPOWER)
        set_icon(EMPOWER_ICON);
}

/**
* @brief Move towards Entity if it is within HOMING_RADIUS
* @param other the Entity for the powerup to move towards
*/
void Power_up::move(Entity other) {    
    if (near(other, HOMING_RADIUS)) {
        if (_y > other.gety() )
            _y -= _speed;
        else if (_y < other.gety()) {
            _y += _speed;
        }
        else if (_x > other.getx() )
            _x -= _speed;
        else if (_x < other.getx()) {
            _x += _speed;
        }
    }
}

/**
* @brief Returns the type of a powerup object
* @return _type the type of powerup
*/
int Power_up::get_type() const {
    return _type;
}