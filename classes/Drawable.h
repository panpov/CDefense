#ifndef DRAWABLE_CLASS
#define DRAWABLE_CLASS

#include <ncurses.h>
#include <string>

class Drawable {
public:
    Drawable();
    Drawable(int, int, chtype);
    int getx();
    int gety();
    char get_icon();
    std::string at_edge(WINDOW * window);
    void move(int delta_y, int delta_x);
    
protected:
    int _y, _x;
    char _icon;
};

#endif // DRAWABLE_CLASS