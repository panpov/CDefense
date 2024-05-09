#include "Drawable.h"

/**
* @brief Creates a default Drawable object
*/
Drawable::Drawable() {
    _x = _y = 0;
    _icon = ' ';
}

/**
* @brief Creates a Drawable object with specified starting coordinated and icon
*/
Drawable::Drawable(int y, int x, chtype ch) {
    _y = y;
    _x = x;
    _icon = ch;
}

/**
* @brief Returns y coordinate of the Drawable
* @return _y the y int of the Drawable
*/
int Drawable::gety() {
    return _y;
}

/**
* @brief Returns x coordinate of the Drawable
* @return _x the x int of the Drawable
*/
int Drawable::getx() {
    return _x;
}

/**
* @brief Returns the icon of the Drawable object
* @return _icon the char representation of the Drawable
*/
char Drawable::get_icon() {
    return _icon;
}

/**
* @brief Updates the icon of the Drawable object
* @param new_icon the updated icon for the Drawable
*/
void Drawable::set_icon(chtype new_icon) {
    _icon = new_icon;
}