#ifndef EMPTY
#define EMPTY

#include <ncurses.h>
#include "Drawable.h"

class Empty : public Drawable {
public:
    Empty(int y, int x);

};

#endif // EMPTY