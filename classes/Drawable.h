#ifndef DRAWABLE_CLASS
#define DRAWABLE_CLASS

#include <ncurses.h>

class Drawable {
public:
    Drawable();
    Drawable(int, int, chtype);
    int getx();
    int gety();
    chtype get_icon();

protected:
    int _y, _x;
    chtype _icon;
};

#endif // DRAWABLE_CLASS