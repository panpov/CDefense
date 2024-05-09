#include "Game.h"

/**
* @brief Adds the powerup directly to the player
* @param player the player object being powered up
* @param pwup the type of powerup being applied to player
*/
void operator+(Player & player, const Power_up * pwup) {
    if (pwup->get_type() == HEALING)
        player.change_health(1);
    else if (pwup->get_type() == EMPOWER)
        player.empower(EMPOWER_DURATION);
    
    delete pwup;
}

/**
* @brief Creates a default game object
*/
Game::Game() {
    _tick = 0;
    _game_over = false;
    _player = Player(INIT_HP, INIT_SPD);
    _player.set_location(HEIGHT - (HEIGHT / 4), WIDTH / 2); 
    _curr_wave_num = 1;
    srand(time(NULL));
}

/**
* @brief Deletes all of the powerups and enemies in the game
*/
Game::~Game() {
    for (Enemy * enemy : _enemies)
        delete enemy;
    
    for (Power_up * pwup : _pwups)
        delete pwup;
}

/**
* @brief Initializes the game's window to default size and color
* @return true if properly initialized, false otherwise
*/
bool Game::init() {
    return _game_window.init();
}

/**
* @brief Gets input from keyboard and corresponds that to a valid action
*/
void Game::get_input() {
    chtype input = _game_window.get_input();
    player_movement(input);

    // Pause menu and shoot functionality
    if (input == 'p')
        _game_window.pause();
    else if (input == 'x')
        shoot();
}

/**
* @brief Goes through all relevant game events
*/
void Game::update() {
    // Checks if enemies should be moved
    if (_tick % _enemy_speed == 0) {
        enemy_roam();
        detect_damage();
    }
    
    // Cleans laser particles
    if (_tick % CLEAN_FREQ == 0)
        clean();

    // Reduces empowered duration
    if (_player.is_empowered())
        _player.empower(-1);

    // Spawns a power_up every PWUP_FREQ ticks
    if (_tick % PWUP_FREQ == 0)
        spawn_pwup();

    // Displays and move power_ups
    for (Power_up * pwup : _pwups) {
        _game_window.add_at(pwup->gety(), pwup->getx(), ' ');
        pwup->move(_player);
        _game_window.add(*pwup);
    }

    // Checks if player health is 0
    if (_player.is_dead()) {
        loss();
        _game_over = true;
    }

    // Checks if current wave is completed
    if (_num_enemies == 0 && !game_over())
        check_wave();
    
    // Displays all enemies on the screen
    for (Enemy * enemy : _enemies)
        _game_window.add(*enemy);

    // Applies power_ups and display game info and player
    pwup();
    info();
    _game_window.add(_player);

    _tick++;
}

/**
* @brief Copies the named window to the physical terminal screen, 
* taking into account what is already there to do optimizations
*/
void Game::refresh() {
    _game_window.refresh();
}

/**
* @brief Removes laser particles from screen
*/
void Game::clean() {
    // Finds laser chars on screen, replaces with blank
    for (int y = 1; y < HEIGHT - 1; y++)
        for (int x = 1; x < WIDTH - 1; x++) {
            chtype curr = mvwinch(_game_window.get_window(), y, x) & A_CHARTEXT;
            if (curr == LASER_ICON)
                _game_window.print(y, x, " ");
        }
}

/**
* @brief Returns _game_over attribute
* @return true if game is over, false otherwise
*/
bool Game::game_over() {
    return _game_over;
}

/**
* @brief Displays HP and wave information in the bottom left of window
*/
void Game::info() {
    _game_window.print(HEIGHT - 3, 4, "HP: " + std::to_string(_player.get_health()));
    _game_window.print(HEIGHT - 4, 4, "WAVE: " + std::to_string(_curr_wave_num));
}

/**
* @brief Replaces current (x,y) with blank and adds to the coordinates of a drawable
* @param drawable the object to be moved on the screen
* @param delta_y the amount the object is moving in the y direction
* @param delta_x the amount the object is moving in the x direction
*/
void Game::move_entity(Entity & entity, int delta_y, int delta_x) {
    _game_window.add_at(entity.gety(), entity.getx(), ' ');
    entity.move(delta_y, delta_x);
}

/**
* @brief Allows player to move in a legal direction
* @param input the direction the player wants to move
*/
void Game::player_movement(chtype input) {
    // Saves a string of invalid moves from a directional input
    std::string invalid_move = _player.nearby_edges(_game_window.get_window());
    int max_y, max_x;
    getmaxyx(_game_window.get_window(), max_y, max_x);

    // Checks which directional key is pressed. If player near edge, move to edge.
    // Otherwise, move by _speed.
    if (input == KEY_UP || input == 'w') {
        if (invalid_move.find("u") == std::string::npos)
            move_entity(_player, -_player.get_speed(), 0);
        else
            move_entity(_player, 1 - _player.gety(), 0);
    }
    else if (input == KEY_DOWN || input == 's') {
        if (invalid_move.find("d") == std::string::npos)
            move_entity(_player, _player.get_speed(), 0);
        else
            move_entity(_player, max_y - _player.gety() - 2, 0);
    }
    else if (input == KEY_LEFT || input == 'a') {
        if (invalid_move.find("l") == std::string::npos)
            move_entity(_player, 0, -_player.get_speed());
        else
            move_entity(_player, 0, 1 - _player.getx());
    }
    else if (input == KEY_RIGHT || input == 'd') {
        if (invalid_move.find("r") == std::string::npos)
            move_entity(_player, 0, _player.get_speed());
        else
            move_entity(_player, 0, max_x - _player.getx() - 2);
    }
}

/**
* @brief Launches a laser from the player
*/
void Game::shoot() {
    // Large laser, if player is empowered
    if (_player.is_empowered()) {
        for (int y = 1; y < _player.gety(); y++)
            for (int x = _player.getx() - 2; x <= _player.getx() + 2; x++) {
                for (size_t i = 0; i < _enemies.size(); i++)
                    // If the laser intersects with an enemy, kill it
                    if ((_enemies[i]->getx() >= _player.getx() - 2) && (_enemies[i]->getx() <= _player.getx() + 2)) {
                        delete _enemies[i];
                        _enemies.erase(_enemies.begin() + i);
                        _num_enemies--;
                    }
                
                _game_window.add_at(y, x, LASER_ICON);
            }  
    }
    // Small laser otherwise
    else {
        for (int y = 1; y < _player.gety(); y++) {
            for (size_t i = 0; i < _enemies.size(); i++)
                // If the laser intersects with an enemy, kill it
                if (_enemies[i]->getx() == _player.getx()) {
                    delete _enemies[i];
                    _enemies.erase(_enemies.begin() + i);
                    _num_enemies--;
                }
            
            _game_window.add_at(y, _player.getx(), LASER_ICON);
        }
    }
}

/**
* @brief Lowers players health if they take damage
*/
void Game::detect_damage() {
    for (size_t i = 0; i < _enemies.size(); i++) {
        // Damage taken if enemy reaches base
        if (_enemies[i]->gety() >= HEIGHT) {
            delete _enemies[i];
            _enemies.erase(_enemies.begin() + i);
            _num_enemies--;

            _player.change_health(-1);
        }
        // Damage taken if enemy hits player
        else if (_enemies[i]->get_coords() == _player.get_coords())
            _player.change_health(-1);
    }
}

/**
* @brief Creates the amount of enemies in a wave
* @param locations the (x,y) coordinate vector for enemies
*/
void Game::enemies_init(std::vector<int> locations) {
    for (int i = 0; i < _num_enemies; i++) {
        _enemies.push_back(new Enemy(1, 1));
        _enemies[i]->set_location(1, locations[i]);
    }
}

/**
* @brief Moves the enemy down the screen
*/
void Game::enemy_roam() {
    for (Enemy * enemy : _enemies) {
        _game_window.add_at(enemy->gety(), enemy->getx(), ' ');
        enemy->move();
    }
}

/**
* @brief Spawns a powerup on screen
*/
void Game::spawn_pwup() {
    // Creates a new powerup and places it at a random point
    Power_up * pwup = new Power_up(rand() % 2); 
    int y, x;

    _game_window.get_rand_point(y, x);
    pwup->set_location(y, x);
    _pwups.push_back(pwup);
}

/**
* @brief Activates the powerup for the player
*/
void Game::pwup() {
    // If player picks up a powerup, give them the buff
    for (size_t i = 0; i < _pwups.size(); i++)
        if (_pwups[i]->get_coords() == _player.get_coords()) {
            _player + _pwups[i];
            _pwups.erase(_pwups.begin() + i);
        }
}

/**
* @brief Shows either the title screen or pause screen based on choice
* @param choice the number of the screen to show (0 - TITLE, 1 - PAUSE)
*/
void Game::menu() {
    _difficulty = _game_window.menu();
}

/**
* @brief Shows the loss screen
*/
void Game::loss() {
    _game_window.lose_screen();
}

/**
* @brief Shows the victory screen
*/
void Game::victory() {
    _game_window.win_screen();
}

/**
* @brief Initializes fstream object and summons first wave of enemies
*/
void Game::load_level() {
    if (_difficulty == '1') {
        _level.open("./levels/hard.txt", std::ios::in | std::ios::out);
        _enemy_speed = HARD_SPEED;
    }
    else if (_difficulty == '2') {
        _level.open("./levels/medium.txt", std::ios::in | std::ios::out);
        _enemy_speed = MED_SPEED;
    }
    else {
        _level.open("./levels/easy.txt", std::ios::in | std::ios::out);
        _enemy_speed = EASY_SPEED;
    }
   
    // Adds all waves of chosen difficulty level into a vector
    // https://stackoverflow.com/questions/12133379/c-using-ifstream-with-getline
    for (std::string wave; std::getline(_level, wave);)
        _waves.push_back(wave);
    
    _total_waves = _waves[0][0] - '0';
    next_wave();
}

/**
* @brief Summons the subsequent wave of enemies
*/
void Game::next_wave() {    
    _num_enemies = 0;
    std::string curr_wave = _waves[_curr_wave_num];
    std::vector<int> enemy_locs = {};

    // Counts number of enemies in a wave
    for (size_t i = 0; i < WIDTH - 2; i++)
        if (curr_wave[i] == 'w') {
            _num_enemies++;
            enemy_locs.push_back(1 + i);
        }

    // Initializes the number of enemies needed
    enemies_init(enemy_locs);
    _curr_wave_num++;
}

/**
* @brief Checks if all waves are completed or if the next should be ran
*/
void Game::check_wave() {
    if (_curr_wave_num == _total_waves + 1) {
        victory();
        _game_over = true;
    }
    else
        next_wave();
}