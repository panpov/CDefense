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

#define WINDOW_WIDTH 30 * 2.25
#define WINDOW_HEIGHT 45

int main() {
    initscr();
    refresh();

    int max_y, max_x;
    getmaxyx(stdscr, max_y, max_x);

    WINDOW * game_window = newwin(WINDOW_HEIGHT, WINDOW_WIDTH, ((max_y / 2 ) - (WINDOW_HEIGHT / 2)), ((max_x / 2) - (WINDOW_WIDTH / 2)));
    box(game_window, 0, 0);
    wrefresh(game_window);

    // Automatic resize function draft

    int new_y = max_y - (max_y % 5);
    int new_x = new_y * (float(2) / 3);
    new_x -= new_x % 5;

    move((max_y / 2) - 10, (max_x / 2) + 10);
    printw("%d", max_y);
    move((max_y / 2) + 10, (max_x / 2) + 10);
    printw("%d", new_y);

    move((max_y / 2) - 10, (max_x / 2) - 10);
    printw("%d", max_x);
    move((max_y / 2) + 10, (max_x / 2) - 10);
    printw("%d", new_x);

    getch();
    endwin();

    return 0;
}