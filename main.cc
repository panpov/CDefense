/**
 * @file main.cpp
 * @author Brett Hajdaj & Pan Pov
 * @brief 
 * @version 0.1
 * @date 2024-04-28
 * 
 * @copyright Copyright (c) 2024
 */

#include <iostream>
#include <ncurses.h>
#include "./classes/Game_Window.h"
#include "./classes/Game.h"
#include "./classes/Drawable.h"
#include "./classes/Player_Class.h"

#define WINDOW_WIDTH 30 * 2.25
#define WINDOW_HEIGHT 45

int main() {
    initscr();
    refresh();

    Game game;

    while (!game.game_over())
    {
        // game.get_input();
        getch();
        game.update();
        game.refresh();
    }
    
    getch();
    endwin();

    return 0;
}