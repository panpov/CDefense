#ifndef POWER_UP_H
#define POWER_UP_H

#include "Entity.h"

#define POWER_UP_ICON 'X'
#define HOMING_RADIUS 8
#define HEALING 0
#define HEALING_ICON 'H'
#define EMPOWER 1
#define EMPOWER_ICON 'E'

class Power_up : public Entity {
private:
    int _type;

public:
    Power_up(int type);
    void move(Entity other);
    int get_type() const;
};


#endif // POWER_UP_H