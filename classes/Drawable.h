#ifndef DRAWABLE_H
#define DRAWABLE_H

#include <ncurses.h>
#include <string>

class Drawable {
public:
    Drawable();
    Drawable(int, int, chtype);
    
    int gety();
    int getx();
    char get_icon();

    void set_icon(chtype new_icon);
    
protected:
    int _y, _x;
    char _icon;
};

#endif // DRAWABLE_H