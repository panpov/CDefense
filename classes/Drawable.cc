#include "Drawable.h"

Drawable::Drawable() {
    _x = _y = 0;
    _icon = ' ';
}

Drawable::Drawable(int y, int x, chtype ch) {
    _x = x;
    _y = y;
    _icon = ch;
}

int Drawable::getx() {
    return _x;
}

int Drawable::gety() {
    return _y;
}

chtype Drawable::get_icon() {
    return _icon;
}