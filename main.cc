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
#include "./classes/Player.h"

int main() {
    // Menu screen code
    // initscr();
    // refresh();
    // Game_Window menu;
    // mvwprintw(menu.get_window(), 10, 10, "------------TESTING BRETT AND PAN--------------");
    // // menu.clear();
    // getch();
    // endwin();
    

    // Window initialization
    initscr();
    refresh();

    noecho();
    curs_set(0);

    Game_Window menu;

    menu.init();

    menu.print(20, 28, "Brett on the Pan Game");

    menu.refresh();

    getch();
    endwin();

    initscr();
    refresh();

    noecho();
    curs_set(0);

    Game game;

    // Main game loop
    if (game.init())
        while (!game.game_over()) {
            game.get_input();
            // getch();
            // ship.draw();
            game.update();
            game.refresh();
        }
    
    getch();
    endwin();

    return 0;
}