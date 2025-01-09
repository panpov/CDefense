#include "Game_Window.h"

/**
* @brief Creates a default game window
*/
Game_Window::Game_Window() {
    // Gets maximum dimensions of terminal, sets default bg colors
    getmaxyx(stdscr, _max_y, _max_x);
    _timeout = TIMEOUT;
    start_color();
    init_pair(2, COLOR_CYAN, COLOR_BLUE);
}

/**
* @brief Initializes the game window as a newwin and sets attributes of that window
* @return true if successfully initialized, false otherwise
*/
bool Game_Window::init() {
    // Checks if terminal size is big enough to allow game
    if (_max_y < HEIGHT || _max_x < WIDTH) {
        std::cout << "Your window is too small. ";
        std::cout << "(Minimum window height: " <<  HEIGHT;
        std::cout << ". Your window height: " << _max_y;
        std::cout << ". Minimum window width: " <<  WIDTH;
        std::cout << ". Your window height: " << _max_x << ".)" << std::endl;
        return false;
    }

    // Creates the game window with rectangular dimensions, sets bg color, enables keyboard, refreshes window
    _game_window = newwin(HEIGHT, WIDTH, (_max_y / 2 ) - (HEIGHT / 2), (_max_x / 2) - (WIDTH / 2));
    
    // Set background color of window and enable keypad inputs
    wbkgd(_game_window, COLOR_PAIR(2) | ' ');
    keypad(_game_window, true);

    clear();
    refresh();

    return true;
}

/**
* @brief Adds a border to the game window
*/
void Game_Window::add_border() {
    wborder(_game_window, '#', '#', 'v', '-', '+', '+', '+', '+');
}

/**
* @brief Puts a blank space at every position of the window and adds border
*/
void Game_Window::clear() {
    wclear(_game_window);
    add_border();
}

/**
* @brief Copies the window to the physical terminal screen, 
* taking into account what is already there to do optimizations
*/
void Game_Window::refresh() {
    wrefresh(_game_window);    
}

/**
* @brief Returns the pointer to the window
* @return _game_window the pointer to the game window
*/
WINDOW * Game_Window::get_window() {
    return _game_window;
}

/**
* @brief Finds a blank space in the bottom half of the screen
* and sets (y,x) coordinates to that space
* @param y container for the y value of first random blank space
* @param x container for the x value of first random blank space
*/
void Game_Window::get_rand_point(int & y, int & x) {
    int rand_y = (HEIGHT / 2) + rand() % ((HEIGHT / 2) - 1);
    int rand_x = 1 + rand() % (WIDTH - 2);
    while (mvwinch(_game_window, y = rand_y, x = rand_x) == ' ');
}

// CITE: Casual Coder (https://youtu.be/O2Zr9aUrYfo?si=AUuuB_eIms6kgCsm)
// DESC: Shows how to handle input in a way that does not speed up the game every key press
/**
* @brief Gets input from the user's keyboard
* @return the character the user inputs
*/
chtype Game_Window::get_input() {
    // Current time
    time_t curr_time = Time::milliseconds();

    // "Regular" input and "extra" input to allow input change before timeout
    chtype input = wgetch(_game_window);
    chtype extra_input = 1;

    // Pauses the game for the full _timeout duration, while getting extra input
    wtimeout(_game_window, 0);
    while (curr_time + _timeout >= Time::milliseconds())
        extra_input = wgetch(_game_window);
    wtimeout(_game_window, _timeout);
    
    // If there is an extra input, process that one instead of original
    if ((extra_input * -1) != 1)
        input = extra_input;

    return input;
}

/**
* @brief Prints text in the window
* @param y the y coordinate of the text
* @param x the x coordinate of the text
* @param str the text to print
*/
void Game_Window::print(int y, int x, std::string str) {
    mvwprintw(_game_window, y, x, "%s", str.data());
}

/**
* @brief Prints a character in the window (must be separate func due to %c)
* @param y the y coordinate of the char
* @param x the x coordinate of the char
* @param character the char to print
*/
void Game_Window::add_at(int y, int x, char character) {
    mvwprintw(_game_window, y, x, "%c", character);
}

/**
* @brief Adds a Drawable object to the window
* @param drawable the Drawable to add to window
*/
void Game_Window::add(Drawable drawable) {
    add_at(drawable.gety(), drawable.getx(), drawable.get_icon());
}

/**
* @brief Shows the menu on the window
* @return difficulty the char input by the user
*/
chtype Game_Window::menu() {
    // Main menu strings  
    std::string hard = "Press 1 for hard mode.", medium = "Press 2 for medium mode.";
    std::string easy = "Press any other key for easy mode.", title = "<- CDefense ->";
    std::string pan_pov = " Pan Pov", b_haj = "Brett Hajdaj";
    std::string controls = "Move: WASD or Arrow Keys, Shoot: X, Pause: P";

    // Print the menu strings
    print(10, (WIDTH / 2) - (title.size() / 2), title);
    print(14, (WIDTH / 2) - (pan_pov.size() / 2) - 1, pan_pov);
    print(16, (WIDTH / 2) - (b_haj.size() / 2), b_haj);
    print(28, (WIDTH / 2) - (hard.size() / 2), hard);
    print(30, (WIDTH / 2) - (medium.size() / 2), medium);
    print(32, (WIDTH / 2) - (easy.size() / 2), easy);
    print(34, (WIDTH / 2) - (controls.size() / 2), controls);

    // Pauses at the menu until a character is pushed, then clears menu from the window
    refresh();
    wtimeout(_game_window, -1);
    chtype difficulty = wgetch(_game_window);
    clear();
    wtimeout(_game_window, _timeout);
    return difficulty;
}

/**
* @brief Displays the pause menu and timeouts the game
*/
void Game_Window::pause() {
    std::string pause = "PAUSED", press = "Press any key to resume.";

    print((HEIGHT / 2) - 1, (WIDTH / 2) - (pause.size() / 2), pause);
    print((HEIGHT / 2) + 1, (WIDTH / 2) - (press.size() / 2), press);
    
    // Game timeout until a key press
    refresh();
    wtimeout(_game_window, -1);
    getch();
    clear();
    wtimeout(_game_window, _timeout);
}

/**
* @brief Displays the losing screen
*/
void Game_Window::lose_screen() {
    std::string loser = "YOU LOST!!", press = "Press any key to exit.";

    print((HEIGHT / 2) - 1, (WIDTH / 2) - (loser.size() / 2), loser);
    print((HEIGHT / 2) + 1, (WIDTH / 2) - (press.size() / 2), press);
    
    // Game timeout until a key press
    refresh();
    wtimeout(_game_window, -1);
    getch();
    clear();
    wtimeout(_game_window, _timeout);
}

/**
* @brief Displays the winning screen
*/
void Game_Window::win_screen() {
    std::string winner = "YOU WIN!", descriptive = "You successfully defended your base.";
    std::string press = "Press any key to exit.";
    
    print((HEIGHT / 2) - 1, (WIDTH / 2) - (winner.size() / 2), winner);
    print((HEIGHT / 2) + 1, (WIDTH / 2) - (descriptive.size() / 2), descriptive);
    print(HEIGHT - (HEIGHT / 4), (WIDTH / 2) - (press.size() / 2), press);
    
    // Game timeout until a keypress
    refresh();
    wtimeout(_game_window, -1);
    getch();
    clear();
    wtimeout(_game_window, _timeout);
}