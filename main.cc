/**
 * @file main.cpp
 * @author Brett Hajdaj & Pan Pov
 * @brief CDefense is a wave-based shooter game made with Ncurses
 * @version 1.0
 * @date 2024-04-28
 * 
 * @copyright Copyright (c) 2024
 */

#include <ncurses.h>
#include "./classes/Game.h"


int main() {
    // Screen initialization & maintain default color of terminal
    initscr();
    use_default_colors();
    init_pair(1, -1, -1);
    wbkgd(stdscr, COLOR_PAIR(1) | ' ');
    refresh();
    noecho();
    curs_set(0);
    
    Game game;

    // Main game loop
    if (game.init()) {
        game.menu();
        game.load_level();
        game.update();
        while (!game.game_over()) {
            game.refresh();
            game.get_input();
            game.update();
        }
    }
    else
        getch();
    endwin();

    return 0;
}