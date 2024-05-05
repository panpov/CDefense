#include "Drawable.h"

Drawable::Drawable() {
    _x = _y = 0;
    _icon = ' ';
}

Drawable::Drawable(int y, int x, chtype ch) {
    _y = y;
    _x = x;
    _icon = ch;
}

int Drawable::gety() {
    return _y;
}

int Drawable::getx() {
    return _x;
}

char Drawable::get_icon() {
    return _icon;
}

std::string Drawable::at_edge(WINDOW * window) {
    int max_y, max_x;
    getmaxyx(window, max_y, max_x);

    std::string edges = "";

    if (_y == 1)
        edges += 'u';
    if (_x == 1)
        edges += 'l';
    if (_y == max_y - 2)
        edges += 'd';
    if (_x == max_x - 2)
        edges += 'r';

    return edges;
}

/**
 * @brief Changes position of Drawable by delta_x and delta_y
 * @param delta_x The new x position of Drawable
 * @param delta_y The new y position of Drawable
*/
void Drawable::move(int delta_y, int delta_x) {
    _y += delta_y;
    _x += delta_x;
}