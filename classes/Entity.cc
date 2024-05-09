#include "Entity.h"

/**
* @brief Creates a default Entity object
*/
Entity::Entity() : Drawable() {
    _health = 0;
    _speed = 0;
}

/**
* @brief Creates a Entity object with specified health, speed, and damage
* @param health the initial amount of health
* @param speed the speed of an Entity
* @param damage the amount of damage the Entity deals
* @param icon the char representation of the Entity
*/
Entity::Entity(int health, int speed, chtype icon) : Drawable(0, 0, icon) {
    _health = health;
    _speed = speed;
}

/**
* @brief Destroys an Entity by setting health and speed to 0
*/
Entity::~Entity() {
    _health = 0;
    _speed = 0;
}

/**
* @brief Returns the health of the Entity
* @return _health the amount of health
*/
int Entity::get_health() {
    return _health;
}

/**
* @brief Returns the speed of an Entity
* @return _speed the speed of an Entity
*/
int Entity::get_speed() {
    return _speed;
}

/**
* @brief Returns the coordinates of an Entity in a vector
* @return coords a vector of the x and y values of an Entity
*/
std::vector<int> Entity::get_coords() {
    // Initialize empty vector, then push back y and x
    std::vector<int> coords = {};
    coords.push_back(_y);
    coords.push_back(_x);
    
    return coords;
}

/**
* @brief Checks if the Entity is dead
* @return true if health is 0, false otherwise
*/
bool Entity::is_dead() {
    return _health <= 0;
}

/**
 * @brief Checks if this Entity within a certain radius of another Entity
 * @param other the other Entity
 * @param radius given radius
 * @return true this Entity is within the given radius of the other Entity
 * @return false this Entity is not within the given radius of the other Entity
 */
bool Entity::near(Entity other, int radius) {
    // Calculate the distance between this Entity and other Entity
    int dist_y = abs(other.gety() - _y);
    int dist_x = abs(other.getx() - _x);
    int dist = sqrt(pow(dist_x, 2) + pow(dist_y, 2));

    return (dist < radius);
}

/**
* @brief Increments the health attribute by amount
* @param amount the number of health to increment (can be negative)
*/
void Entity::change_health(int amount) {
    _health += amount;
}

/**
* @brief Updates speed of an Entity to a new speed
* @param new_speed the new speed of an Entity
*/
void Entity::set_speed(int new_speed) {
    _speed = new_speed;
}

/**
* @brief Sets the (x,y) coordinates of an Entity
* @param y the new y coordinate
* @param x the new x coordinate
*/
void Entity::set_location(int y, int x) {
    _y = y;
    _x = x;
}

/**
* @brief Finds the edges that the Entity is near
* @param window the current game window
* @return edges - a string of characters representing the edges the Entity is near
*/
std::string Entity::nearby_edges(WINDOW * window) {
    // Finds dimensions for the window
    int max_y, max_x;
    getmaxyx(window, max_y, max_x);

    // Adds to edges string if near an edge
    std::string edges = "";
    if (_y - _speed <= 1)
        edges += 'u';
    if (_x - _speed <= 1)
        edges += 'l';
    if (_y + _speed >= max_y - 2)
        edges += 'd';
    if (_x + _speed >= max_x - 2)
        edges += 'r';

    return edges;
}

/**
 * @brief Changes position of Drawable by delta_x and delta_y
 * @param delta_x The new x position of Drawable
 * @param delta_y The new y position of Drawable
*/
void Entity::move(int delta_y, int delta_x) {
    _y += delta_y;
    _x += delta_x;
}