/**
 * @file main.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-04-28
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <iostream>
#include <ncurses.h>
#include "./classes/Game_Window.h"
#include "./classes/Game.h"

#define WINDOW_WIDTH 30 * 2.25
#define WINDOW_HEIGHT 45

int main() {
    initscr();
    refresh();

    Game game;

    while (!game.game_over())
    {
        game.get_input();
        game.update();
        game.refresh();
    }
    
    getch();
    endwin();

    return 0;
}