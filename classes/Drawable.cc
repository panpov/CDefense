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

chtype Drawable::get_icon() {
    return _icon;
}