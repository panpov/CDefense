#ifndef ENTITY_H
#define ENTITY_H

#include "Drawable.h"
#include "Game_Window.h"
#include <cmath>
#include <vector>

class Entity : public Drawable {
public:
    Entity();
    Entity(int health, int speed, chtype icon);
    virtual ~Entity();
    
    int get_health();
    int get_speed();
    std::vector<int> get_coords();
    bool is_dead();
    bool near(Entity other, int radius);
    
    void change_health(int amount);
    void set_speed(int new_speed);
    void set_location(int y, int x);
    
    std::string nearby_edges(WINDOW * window);
    virtual void move(int delta_y, int delta_x);

protected:
    int _health;
    int _speed;

};

#endif // ENTITY_H